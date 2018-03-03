//
//  Config.h
//  项目框架 - by Candy
//
//  Created by Candy on 17/1/5.
//  Copyright © 2017年 Candy. All rights reserved.
//  配置文件

#ifndef Config_h
#define Config_h

//随机颜色
#define COLOR_RANDOM [UIColor colorWithRed:arc4random()%255/256.f green:arc4random()%255/256.f blue:arc4random()%255/256.f alpha:1]
//RGB自定义颜色
#define COLOR_RGB(r,g,b,a) [UIColor colorWithRed:r/256.f green:g/256.f blue:b/256.f alpha:a]
//应用主题色
#define APP_MAIN_COLOR COLOR_RGB(239, 234, 218, 1)

//调试版本输出语句
#if DEBUG
#define Log(format, ...)       NSLog(format, ##__VA_ARGS__)
#else
#define Log(format, ...)
#endif


#endif /* Config_h */
