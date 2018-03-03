//
//  UserModel.h
//  项目框架 - by Candy
//
//  Created by Candy on 17/1/10.
//  Copyright © 2017年 Candy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserModel : NSObject

@property (nonatomic, copy) NSString        * username;     //用户名
@property (nonatomic, copy) NSString        * password;     //密码
@property (nonatomic, copy) NSString        * nickname;     //昵称
@property (nonatomic, copy) NSString        * signature;    //个性签名


+ (instancetype)shareUserModel;

@end
