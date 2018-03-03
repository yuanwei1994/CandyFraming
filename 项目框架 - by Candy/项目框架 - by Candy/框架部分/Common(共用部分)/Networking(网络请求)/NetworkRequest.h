//
//  NetworkRequest.h
//  项目框架 - by Candy
//
//  Created by Candy on 17/1/5.
//  Copyright © 2017年 Candy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Response.h"
#import <AFNetworking/AFNetworking.h>

typedef void(^RequestCompletion)(Response * response);

@interface NetworkRequest : NSObject

+ (void)startGetRequest:(NSString *)urlString
             Parameters:(NSDictionary *)parameters
                   DataKey:(NSString *)dataKey
      CompletionHandler:(RequestCompletion)comletionHandler;

+ (void)startPostRequest:(NSString *)urlString
              Parameters:(NSDictionary *)parameters
                 DataKey:(NSString *)dataKey
       CompletionHandler:(RequestCompletion)comletionHandler;

+ (void)startUploadRequest:(NSString *)urlString
                  ImageUrl:(NSString *)imageUrl
                Parameters:(NSDictionary *)parameters
                   DataKey:(NSString *)dataKey
         CompletionHandler:(RequestCompletion)completionHandler;

@end
