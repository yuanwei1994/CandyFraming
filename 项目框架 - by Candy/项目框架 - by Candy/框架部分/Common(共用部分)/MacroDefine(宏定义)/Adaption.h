//
//  Adaption.h
//  项目框架 - by Candy
//
//  Created by Candy on 17/1/5.
//  Copyright © 2017年 Candy. All rights reserved.
//  屏幕适配文件

#ifndef Adaption_h
#define Adaption_h

#import <UIKit/UIKit.h>

#pragma 尺寸

#define SCREEN_WIDTH        [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT       [UIScreen mainScreen].bounds.size.height
#define SCREEN_SIZE         [UIScreen mainScreen].bounds.size
#define SCREEN_ORIGIN       [UIScreen mainScreen].bounds.origin

#pragma 参照尺寸

#define BaseWidth 320
#define BaseHeight 568

#define Inline static inline

//适配比例
Inline CGFloat AAdaptionWidth() {
    return SCREEN_WIDTH / BaseWidth;
}

//尺寸适配
Inline CGFloat AAdaption(CGFloat x) {
    return x * AAdaptionWidth();
}

//字体适配
Inline UIFont * AAFont(CGFloat font){
    return [UIFont systemFontOfSize:font*AAdaptionWidth()];
}


Inline CGSize AAdaptionSize(CGFloat width, CGFloat height) {
    CGFloat newWidth = width * AAdaptionWidth();
    CGFloat newHeight = height * AAdaptionWidth();
    return CGSizeMake(newWidth, newHeight);
}

Inline CGPoint AAadaptionPoint(CGFloat x, CGFloat y) {
    CGFloat newX = x * AAdaptionWidth();
    CGFloat newY = y * AAdaptionWidth();
    return  CGPointMake(newX, newY);
}

Inline CGRect AAdaptionRect(CGFloat x, CGFloat y, CGFloat width, CGFloat height){
    CGFloat newX = x*AAdaptionWidth();
    CGFloat newY = y*AAdaptionWidth();
    CGFloat newW = width*AAdaptionWidth();
    CGFloat newH = height*AAdaptionWidth();
    return CGRectMake(newX, newY, newW, newH);
}

Inline CGRect AAdaptionRectFromFrame(CGRect frame){
    CGFloat newX = frame.origin.x*AAdaptionWidth();
    CGFloat newY = frame.origin.y*AAdaptionWidth();
    CGFloat newW = frame.size.width*AAdaptionWidth();
    CGFloat newH = frame.size.height*AAdaptionWidth();
    return CGRectMake(newX, newY, newW, newH);
}

#endif /* Adaption_h */
