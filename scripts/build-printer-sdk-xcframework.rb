#!/usr/bin/env ruby
# Regenerates ios/PrinterSDK/GenericPrinterSDK.xcframework from the vendor's libGenericPrinterSDK.a.
#
# The vendor library only tags its arm64 objects for iOS devices, so Apple Silicon simulators
# cannot link it. The simulator slice reuses the arm64 code re-tagged as iOS Simulator, plus the
# original x86_64 objects (ld already treats x86_64 + LC_VERSION_MIN_IPHONEOS as simulator).
#
# Usage: ruby scripts/build-printer-sdk-xcframework.rb
require 'fileutils'
require 'tmpdir'

LC_VERSION_MIN_IPHONEOS = 0x25
LC_LINKER_OPTIMIZATION_HINT = 0x2E
LC_BUILD_VERSION = 0x32
PLATFORM_IOSSIMULATOR = 7
MIN_OS = (12 << 16)
MH_MAGIC_64 = 0xFEEDFACF

SDK_DIR = File.expand_path('../ios/PrinterSDK', __dir__)
SRC = File.join(SDK_DIR, 'libGenericPrinterSDK.a')
OUT = File.join(SDK_DIR, 'GenericPrinterSDK.xcframework')

def run(*cmd)
  system(*cmd, out: File::NULL) || abort("command failed: #{cmd.join(' ')}")
end

# LC_BUILD_VERSION (24 bytes) does not fit where LC_VERSION_MIN_IPHONEOS (16) was, so we drop
# LC_LINKER_OPTIMIZATION_HINT: those hints are optional and ld links fine without them.
def retag_for_simulator(path)
  data = File.binread(path)
  magic, _, _, _, ncmds, sizeofcmds = data.unpack('L<6')
  abort "#{path}: not a 64-bit Mach-O object" unless magic == MH_MAGIC_64

  offset = 32
  cmds = []
  ncmds.times do
    cmd, size = data.byteslice(offset, 8).unpack('L<2')
    case cmd
    when LC_VERSION_MIN_IPHONEOS
      cmds << [LC_BUILD_VERSION, 24, PLATFORM_IOSSIMULATOR, MIN_OS, MIN_OS, 0].pack('L<6')
    when LC_LINKER_OPTIMIZATION_HINT
      nil
    when LC_BUILD_VERSION
      abort "#{path}: already has LC_BUILD_VERSION; the vendor library changed, revisit this script"
    else
      cmds << data.byteslice(offset, size)
    end
    offset += size
  end

  blob = cmds.join
  abort "#{path}: no room for LC_BUILD_VERSION" if blob.bytesize > sizeofcmds

  data[16, 8] = [cmds.size, blob.bytesize].pack('L<2')
  data[32, sizeofcmds] = blob.ljust(sizeofcmds, "\0")
  File.binwrite(path, data)
end

Dir.mktmpdir do |tmp|
  device = File.join(tmp, 'device', 'libGenericPrinterSDK.a')
  sim = File.join(tmp, 'sim', 'libGenericPrinterSDK.a')
  sim_arm64 = File.join(tmp, 'sim-arm64.a')
  sim_x86_64 = File.join(tmp, 'sim-x86_64.a')
  objs = File.join(tmp, 'objs')
  FileUtils.mkdir_p([File.dirname(device), File.dirname(sim), objs])

  run('lipo', SRC, '-thin', 'arm64', '-output', device)
  run('lipo', SRC, '-thin', 'x86_64', '-output', sim_x86_64)

  Dir.chdir(objs) { run('ar', 'x', device) }
  files = Dir[File.join(objs, '*.o')].sort
  abort "no objects extracted from #{SRC}" if files.empty?
  files.each { |f| retag_for_simulator(f) }
  run('libtool', '-static', '-no_warning_for_no_symbols', '-o', sim_arm64, *files)
  run('lipo', '-create', sim_arm64, sim_x86_64, '-output', sim)

  FileUtils.rm_rf(OUT)
  run('xcodebuild', '-create-xcframework', '-library', device, '-library', sim, '-output', OUT)
end

puts "Wrote #{OUT}"
