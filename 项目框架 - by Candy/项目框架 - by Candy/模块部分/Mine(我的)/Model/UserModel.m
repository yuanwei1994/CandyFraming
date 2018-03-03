//
//  UserModel.m
//  项目框架 - by Candy
//
//  Created by Candy on 17/1/10.
//  Copyright © 2017年 Candy. All rights reserved.
//

#import "UserModel.h"

@implementation UserModel

+ (instancetype)shareUserModel {
    static UserModel *userModel = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        userModel = [[UserModel alloc] init];
    });
    return userModel;
}


@end
