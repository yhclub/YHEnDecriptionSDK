//
//  YHSecKeyWrapper.h
//  YiKaTongAPP
//
//  Created by YLZ-MAC on 15-1-6.
//  Copyright (c) 2015年 YLZ-MAC. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AES_IV @"0102030405060708"
#define AES_ENCODE_TYPE_BESE64 @"base64"
#define AES_ENCODE_TYPE_HEX @"hex"

#define YH_DEFAULT_IV @"0102030405060708"
#define YH_STRING_ENCODE_TYPE_BASE64 @"base64"
#define YH_STRING_ENCODE_TYPE_HEX @"hex"


#define kChosenDigestLength        CC_SHA1_DIGEST_LENGTH

// Global constants for padding schemes.
#define kPKCS1                   11
#define kTypeOfPwdPadding        kSecPaddingNone
#define kTypeOfWrapPadding       kSecPaddingPKCS1
#define kTypeOfSigPadding        kSecPaddingPKCS1SHA1
#define kMaxBlockSize            117


@interface YHSecKeyWrapper : NSObject

#pragma mark ----------------------------:: RSA ::----------------------------

/*
 * RSA 加密
 * content 待加密字符
 * return 加密后的字符串
 */
+ (NSString *_Nullable)encryptUseRSA:(NSString *_Nonnull)content;

+ (NSString *_Nullable)encryptUseRSA:(NSString *_Nonnull)content publicKey:(NSString *_Nullable)publicKeyString;

+ (NSString *_Nullable)encryptUseRSA:(NSString *_Nonnull)content publicKey:(NSString *_Nullable)publicKeyString secPadding:(SecPadding)secPadding;

/*
 * RSA 数字签名验证
 * content 待签名字符串
 * sig 待验证的签名字符串
 * return yes签名正确
 */
+ (BOOL)verifySignatureWithString:(NSString *_Nonnull)content signature:(NSString *_Nullable)sig;


+ (BOOL)verifySignatureWithString:(NSString *_Nonnull)content signature:(NSString *_Nullable)sig publicKey:(NSString *_Nullable)publicKeyStr;


#pragma mark ----------------------------:: AES ::----------------------------

/*
 * AES 加密
 * content 待加密字符
 * symmetricKey    对称密钥 前16位有效
 * return 加密后的字符串
 */
+ (NSString *_Nullable)encryptUseAES:(NSString *_Nonnull)content withKey:(NSString *_Nullable)key withIv:(NSString *_Nullable)iv withEncodeType:(NSString *_Nullable)encode;

/*
 * AES 解密
 * encryptedString 待解密字符
 * symmetricKey    对称密钥 前16位有效
 * return 解密后的Data
 */
+ (NSData *_Nullable)dataWithDecryptAESWrap:(NSString *_Nonnull)encryptedString withKey:(NSString *_Nonnull)key withIv:(NSString *_Nullable)iv withEncodeType:(NSString *_Nullable)encode;

+ (NSString *_Nullable)decryptAESWrap:(NSString *_Nonnull)encryptedString withKey:(NSString *_Nonnull)key withIv:(NSString *_Nullable)iv withEncodeType:(NSString *_Nullable)encode;

#pragma mark ----------------------------:: 兼容分库后外部用到的国密算法 ::----------------------------

/**
 hash data for sm3
 
 @param plainData for input plain data
 @return hash result, null for error
 */
+ (NSData * _Nullable)sm3_hashWithPainData:(NSData *_Nonnull)plainData;


/**
 encrypt plain data for sm4 ecb-mode
 
 @param plainData to be encrypted
 @param key for sm4 cbc-mode 健康合肥、吉一通等送检项目
 @return encrypt result, null for error
 */
+ (NSData * _Nullable)sm4_cbcEncryptData:(NSData *_Nonnull)plainData withCipherKey:(NSString *_Nonnull)key;


/**
 encrypt plain data for sm4 ecb-mode
 
 @param plainData to be encrypted
 @param key for sm4 ecb-mode 国家医保局项目
 @return encrypt result, null for error
 */
+ (NSData * _Nullable)sm4_ecbEncryptData:(NSData *_Nonnull)plainData withCipherKey:(NSString *_Nonnull)key NS_AVAILABLE_IOS(8_0);

/**
 sign plain string for sm2
 
 @param str for plain string
 @param uid user-identifier
 @param key for private
 @return signed string
 */
+ (NSString * _Nullable)sm2_signPlainString:(NSString *_Nonnull)str withUID:(NSString *_Nullable)uid withPrivateKey:(NSString *_Nullable)key;

/**
 decrypt cipher data for sm4
 
 @param cipherData to be decrypted
 @param key for sm4 cbc-mode
 @return decrypt result, null for error
 */
+ (NSData * _Nullable)sm4_decryptData:(NSData *_Nonnull)cipherData withCipherKey:(NSString *_Nonnull)key NS_AVAILABLE_IOS(8_0);

/**
 decrypt cipher data for sm4
 
 @param cipherData to be decrypted
 @param key for sm4 cbc-mode
 @param iv for sm4 cbc-mode. recommend 0102030405060708
 @return decrypt result, null for error
 */
+ (NSData * _Nullable)sm4_decryptData:(NSData * _Nonnull)cipherData withCipherKey:(NSString *_Nonnull)key iv:(NSString *_Nullable)iv NS_AVAILABLE_IOS(8_0);


/*
 * md5加密
 * content 待加密字符
 * return 加密后的字符串
 */
+(NSString *_Nullable)md5:(NSString *_Nullable)content NS_DEPRECATED_IOS(2_0,3_0, "use -[string yh_md5]");

@end

