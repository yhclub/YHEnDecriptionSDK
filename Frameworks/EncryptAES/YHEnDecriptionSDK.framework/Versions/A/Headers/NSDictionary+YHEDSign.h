//
//  NSDictionary+YHEDSign.h
//  YHEnDecriptionSDK
//
//  Created by ljt on 19/5/14.
//  Copyright (c) 2015年 dev. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary(YHEDSign)

/**
 JSON字符串转字典数据

 @param jsonString JSON字符串
 @return 字典
 */
+(instancetype)yh_dictionaryWithJSON:(NSString *)jsonString;

/**
 对字典数据进行MD5签名
 注：默认会过滤：@"sign", @"encryptData", @"externalMap", @"pageParam" 
 @param secret 签名私钥
 @return 签名后数据
 */
-(NSString *)yh_signWithMd5WithSecret:(NSString *)secret;

  
/**
对字典数据进行签名
注：默认会过滤：@"sign", @"encryptData", @"externalMap", @"pageParam"
@param secret 签名私钥
@param signType 签名类型（MD5/SM3/SM2）
@return 签名后数据
*/
-(NSString *)yh_signWithSecret:(NSString *)secret signType:(NSString *)signType;
    
/**
对字典数据进行签名

 @param secret 签名私钥
 @param signType 签名类型（MD5/SM3/SM2）
 @param blackList 需要剔除key的集合。
 @return 签名后数据
 */
-(NSString *)yh_signWithSecret:(NSString *)secret signType:(NSString *)signType blackList:(NSArray<NSString *> *)blackList;

-(NSString *)yh_jsonString;

/**
 字典按参数名升序转换为JSON字符串
 @return 处理后的字符
 */
-(NSString *)yh_sortJsonString;

/**
 字典按参数名升序，对基础数据类型格式化处理，滤空操作，以"参数名=值&参数名=值&...&参数名=值"格式生成
 
 注：默认会过滤：@"sign", @"encryptData", @"externalMap", @"pageParam"
 
 @return 处理后的字符
 */
-(NSString *)yh_signSortString;

/**
 字典按参数名升序，对基础数据类型格式化处理，滤空操作，以"参数名=值&参数名=值&...&参数名=值"格式生成，可指定黑名单剔除不需要的数据

 @param blackList 需要剔除key的集合。
 @return 处理后的字符
 */
-(NSString *)yh_signSortStringWithBlackList:(NSArray<NSString *> *)blackList;

/**
 对字典验签
 
 @param sign 签名
 @param secret 签名私钥
 @param signType 签名类型（MD5/SM3）
 @return 是否签名成功
 */
-(BOOL)yh_verifySign:(NSString *)sign secret:(NSString *)secret signType:(NSString *)signType;

/**
 对字典验签

 @param sign 签名
 @param secret 签名私钥
 @param signType 签名类型（MD5/SM3）
 @param blackList 不参与验签的key
 @return 是否签名成功
 */
-(BOOL)yh_verifySign:(NSString *)sign secret:(NSString *)secret signType:(NSString *)signType blackList:(NSArray<NSString *> *)blackList;

+(NSArray<NSString *> *)yh_signIgnorePropertyArr;

/**
 旧版Deprecated
*/
+(instancetype)dictionaryWithJSON:(NSString *)jsonString NS_DEPRECATED_IOS(2_0, 3_0, "Use -yhEn_sortJsonString") __TVOS_PROHIBITED;

+(NSArray<NSString *> *)signIgnorePropertyArr NS_DEPRECATED_IOS(2_0, 3_0, "Use -yhEn_sortJsonString") __TVOS_PROHIBITED;

-(NSString *)jsonString NS_DEPRECATED_IOS(2_0, 3_0, "Use -yhEn_sortJsonString") __TVOS_PROHIBITED;

-(NSString *)sortJsonString NS_DEPRECATED_IOS(2_0, 3_0, "Use -yhEn_sortJsonString") __TVOS_PROHIBITED;

@end

@interface NSArray(YHEDSign)

-(NSString *)yh_sortJsonString;

@end

@interface NSString(YHEDSign)

-(NSString *)yh_stringByReplacingEscapeCharacter;

@end
