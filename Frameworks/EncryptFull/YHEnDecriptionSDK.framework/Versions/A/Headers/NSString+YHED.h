//
//  NSString+YHED.h
//  YHEnDecriptionSDK
//
//  Created by Jagtu on 2020/10/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (YHED)

/**
 * 获取MD5摘要值
 */
- (NSString *)yh_md5;

/**
 * 获取sha256摘要值
 */
- (NSString *)yh_sha256;

/**
 * 判断是否符合base64字符串格式
 */
- (BOOL)yh_isBase64;


/**
 * 判断是否符合16进展字符串格式
 */
- (BOOL)yh_isHex;

@end

NS_ASSUME_NONNULL_END
