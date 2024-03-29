//
//  NSData+YHHexadecimal.h
//  YhPaymentAPP
//
//  Created by ljt on 2016/12/5.
//  Copyright © 2016年 jagtu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (YHHexadecimal)

//十六进制字符串转换成NSData
+ (NSData *)yh_dataFromHexadecimalString:(NSString *)aString;

//NSData的十六进制的字符串
- (NSString *)yh_hexadecimalString;

@end
