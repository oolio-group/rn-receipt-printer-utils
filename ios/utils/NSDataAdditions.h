//
//  NSDataAdditions.h
//
//  Created by Till POS on 14/09/21.
//

@interface NSData ()
+ (NSData *) dataWithBase64EncodedString:(NSString *)string;
- (id) initWithBase64EncodedString:(NSString *)string;
- (NSString *)hexadecimalString;
@end
