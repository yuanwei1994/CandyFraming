//
//  Response.h
//  项目框架 - by Candy
//
//  Created by Candy on 17/1/5.
//  Copyright © 2017年 Candy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Response : NSObject

@property (nonatomic,assign) BOOL       success;        //是否正确返回
@property (nonatomic,strong) id         resultVaule;    //请求结果
@property (nonatomic,copy) NSString   * resultDesc;     //请求结果描述


@end
