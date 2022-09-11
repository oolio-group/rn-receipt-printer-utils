#import "PrinterManager.h"

@interface PrinterManager()
                                        // objectid  thePrinter
@property(nonatomic) NSMutableDictionary<NSString *, Epos2Printer*> *objectDict;

@end


@implementation PrinterManager

static PrinterManager *sharedData_ = nil;

+ (PrinterManager *)sharedManager {
    @synchronized(self) {
        if (sharedData_ == nil) {
            sharedData_ = [PrinterManager new];
        }
        return sharedData_;
    }
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _objectDict = [NSMutableDictionary new];
    }

    return self;
}

- (void) removeAll{
    @synchronized (self) {
        if (_objectDict == nil) return;
        [_objectDict removeAllObjects];
    }
}

- (NSString *)add:(Epos2Printer*)thePrinterObj {
    @synchronized (self) {
        NSString *printerTarget = [thePrinterObj getPrinterTarget];

        if ([_objectDict.allKeys containsObject:printerTarget] == NO) {
            [_objectDict addEntriesFromDictionary:@{printerTarget: thePrinterObj}];
        } 
        return printerTarget;
    }
}

- (Epos2Printer*)getObject:(NSString *) identifier {
    @synchronized (self) {
        return _objectDict[identifier];
    }
}

- (void)remove:(NSString *) identifier {
    @synchronized (self) {
        _objectDict[identifier] = nil;
    }
}


@end