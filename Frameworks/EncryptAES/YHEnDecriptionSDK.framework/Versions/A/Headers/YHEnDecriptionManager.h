//
//  YHEnDecriptionManager.h
//  YHEnDecriptionSDK
//
//  Created by cy on 2018/12/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHEnDecriptionManager : NSObject

#ifndef YHEnDecriptionExcludingSM


#pragma mark --------------------------:: 读取指定路径的验证授权文件，使用SM4解密，SM3验签。必须使用带有国密算法的库。 ::--------------------------
/**
 验证授权文件，使用SM4解密，SM3验签。
 
 @param filePath 授权文件地址
 @return 是否验证成功
 */
+(BOOL)verifySMAuthFilePath:(NSString *)filePath;

/**
 验证授权文件，使用SM4解密，SM3验签。
 
 @param filePath 授权文件地址
 @param smKey sm4的key值
 @param iv sm4的iv值
 @return 是否验证成功
 */
+(BOOL)verifySMAuthFilePath:(NSString *)filePath smKey:(NSString *)smKey iv:(NSString *)iv;

/**
 验证授权文件，使用SM4解密，SM3验签。

 @param filePath 授权文件地址
 @param appId 授权应用编号
 @param appSecret 授权应用密钥
 @return 是否验证成功
 */
+(BOOL)verifySMAuthFilePath:(NSString *)filePath appId:(nullable NSString *)appId appSecret:(nullable NSString *)appSecret;

/**
 验证授权文件，使用SM4解密，SM3验签。

 @param filePath 授权文件地址
 @param appId 授权应用编号
 @param appSecret 授权应用密钥
 @param smKey sm4的key值
 @param iv sm4的iv值
 @return 是否验证成功
 */
+(BOOL)verifySMAuthFilePath:(NSString *)filePath appId:(nullable NSString *)appId appSecret:(nullable NSString *)appSecret smKey:(NSString *)smKey iv:(NSString *)iv;

/**
 验证授权文件，使用SM4解密，SM3验签。
 
 @param filePath 授权文件地址
 @param appId 授权应用编号
 @param appSecret 授权应用密钥
 @param smKey sm4的key值
 @param iv sm4的iv值
 @param version 授权的版本
 @return 是否验证成功
 */
+(BOOL)verifySMAuthFilePath:(NSString *)filePath appId:(nullable NSString *)appId appSecret:(nullable NSString *)appSecret version:(nullable NSString *)version smKey:(NSString *)smKey iv:(NSString *)iv;


#pragma mark --------------------------:: 读取指定路径的验证授权文件，使用SM2验签。 必须使用带有国密算法的库。::--------------------------

/**
 验证授权文件，使用SM2验签。

 @param filePath 授权文件地址
 @param appId 授权应用编号
 @param appSecret 授权应用密钥
 @param version 授权的版本
 @return 是否验证成功
 */
+(BOOL)verifySM2AuthFilePath:(NSString *)filePath appId:(nullable NSString *)appId appSecret:(nullable NSString *)appSecret version:(nullable NSString *)version;

/**
 验证授权文件，使用SM2验签。

 @param filePath 授权文件地址
 @param appId 授权应用编号
 @param appSecret 授权应用密钥
 @param version 授权的版本
 @param sm2PublicKey sm2公钥
 @param iv sm2的uid
 @return 是否验证成功
 */
+(BOOL)verifySM2AuthFilePath:(NSString *)filePath appId:(nullable NSString *)appId appSecret:(nullable NSString *)appSecret version:(nullable NSString *)version sm2PublicKey:(NSString *)sm2PublicKey iv:(NSString *)iv;


#pragma mark --------------------------:: 读取授权文件二进制数据，使用SM4解密，SM3验签。 必须使用带有国密算法的库。::--------------------------
/**
 验证授权文件，使用SM4解密，SM3验签。
 
 @param data 授权文件二进制数据
 @return 是否验证成功
 */
+(BOOL)verifySMAuthFileData:(NSData *)data;

/**
 验证授权文件，使用SM4解密，SM3验签。
 
 @param data 授权文件二进制数据
 @param smKey sm4的key值
 @param iv sm4的iv值
 @return 是否验证成功
 */
+(BOOL)verifySMAuthFileData:(NSData *)data smKey:(NSString *)smKey iv:(NSString *)iv;

/**
 验证授权文件，使用SM4解密，SM3验签。

 @param data 授权文件二进制数据
 @param appId 授权应用编号
 @param appSecret 授权应用密钥
 @return 是否验证成功
 */
+(BOOL)verifySMAuthFileData:(NSData *)data appId:(nullable NSString *)appId appSecret:(nullable NSString *)appSecret;


/**
 验证授权文件，使用SM4解密，SM3验签。
 
 @param data 授权文件二进制数据
 @param appId 授权应用编号
 @param appSecret 授权应用密钥
 @param smKey sm4的key值
 @param iv sm4的iv值
 @return 是否验证成功
 */
+(BOOL)verifySMAuthFileData:(NSData *)data appId:(nullable NSString *)appId appSecret:(nullable NSString *)appSecret smKey:(NSString *)smKey iv:(NSString *)iv;

/**
 验证授权文件，使用SM4解密，SM3验签。

 @param data 授权文件二进制数据
 @param appId 授权应用编号
 @param appSecret 授权应用密钥
 @param version 授权的版本
 @param smKey sm4的key值
 @param iv sm4的iv值
 @return 是否验证成功
 */
+(BOOL)verifySMAuthFileData:(NSData *)data appId:(nullable NSString *)appId appSecret:(nullable NSString *)appSecret version:(nullable NSString *)version smKey:(NSString *)smKey iv:(NSString *)iv;

#endif


+(NSString *)md5:(NSString *)inPutText NS_DEPRECATED_IOS(2_0,3_0, "use -[string yh_md5]");

@end

NS_ASSUME_NONNULL_END
