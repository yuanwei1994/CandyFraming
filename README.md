# iOS开发 - 项目基本框架搭建

### 1.项目的基本框架的搭建（带标签控制器）
### 2.基本网络请求的封装（使用的AFNetworking）
### 3.本框架采用的是MVC模式
##### 注意事项：
	 在下载该框架以后，请先执行	"pod install" 进行第三方框架的下载
	 该框架适用于一些初入门的新手交流学习，避免走了弯路，欢迎借鉴，谢谢！
	 有什么好的建议可以在底部下方给我留言，也可发邮件到我的邮箱：90candy.com@gmail.com
	 
##### 项目结构图展示	- [点击查看项目结构截图（大图）](项目结构图.png)
<html>
	<body>
		<img src="http://p1.bqimg.com/567571/51c1b54933390bce.png" width="500" height="300" style="margin:0 auto"/>
	</body>
</html>
****
##### 代码展示
> 预编译文件 "PrefixHeaderPCH.pch"

```
#ifndef PrefixHeaderPCH_pch
#define PrefixHeaderPCH_pch

#import "Adaption.h"
#import "Config.h"
#import "RequestURL.h"
#import "NetworkRequest.h"


#endif /* PrefixHeaderPCH_pch */

```
> 项目配置文件 "Config.h"

```
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
```

> 屏幕适配文件 "Adaption.h"

```
#ifndef Adaption_h
#define Adaption_h

#import <UIKit/UIKit.h>

#pragma 尺寸

#define SCREEN_WIDTH        [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT       [UIScreen mainScreen].bounds.size.height
#define SCREEN_SIZE         [UIScreen mainScreen].bounds.size
#define SCREEN_ORIGIN       [UIScreen mainScreen].bounds.origin

#pragma 参照尺寸

#define BaseWidth 414
#define BaseHeight 736

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
```

> 主框架代码	"MainTabBarController.m"

```
//这里导入的是4个普通的ViewController
#import "MainTabBarController.h"
#import "HomeViewController.h"
#import "SchoolViewController.h"
#import "MessageViewController.h"
#import "MineViewController.h"
	
@interface MainTabBarController ()<UITabBarControllerDelegate>
	
@end
	
@implementation MainTabBarController
	
- (void)viewDidLoad {
    [super viewDidLoad];
    //界面初始化
    [self initializUI];
}
	
//UITabBar改变默认高度
- (void)viewWillLayoutSubviews{
    CGRect tabFrame = self.tabBar.frame;
    //这里也可根据屏幕大小进行改变工具条的高度AAdaption(60.0)
    tabFrame.size.height = 50.0;
    tabFrame.origin.y = self.view.frame.size.height - 50.0;
    self.tabBar.frame = tabFrame;
    //添加上自定义的工具条
    //    [self.tabBar bringSubviewToFront:self.tabBarToolView];
}
	
- (void)initializUI {
    NSArray *viewControllers = @[[[HomeViewController alloc]init],[[SchoolViewController alloc]init],[[MessageViewController alloc]init],[[MineViewController alloc]init]];
    //标签控制器 - 标题
    NSArray *tabBarItemTitle = @[@"首 页",@"学 校",@"消 息",@"我 的"];
    //标签控制器 - 正常图片
    NSArray *tabBarItemImageName = @[@"menu_home_normal", @"menu_school_normal", @"menu_interactive_normal", @"menu_mine_normal"];
    //标签控制器 - 选中图片
    NSArray *tabBarItemSelectedImageName = @[@"menu_home_selected", @"menu_school_selected", @"menu_interactive_selected", @"menu_mine_selected"];
    _VCArray = [NSMutableArray array];
    //循环赋值
    for (int i = 0; i<viewControllers.count; i++) {
        UIViewController * vc = viewControllers[i];
        //方法一：直接初始化
        //UITabBarItem * item = [[UITabBarItem alloc] initWithTitle:tabBarItemTitle[i] image:[UIImage imageNamed:tabBarItemImageName[i]] selectedImage:[UIImage imageNamed:tabBarItemSelectedImageName[i]]];
        //方法二：设置图片渲染
        UITabBarItem * item = [[UITabBarItem alloc] init];
        [item setTitle:tabBarItemTitle[i]];
        item.image = [[UIImage imageNamed:tabBarItemImageName[i]] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
        item.selectedImage = [[UIImage imageNamed:tabBarItemSelectedImageName[i]] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
        vc.tabBarItem = item;
        vc.title = tabBarItemTitle[i];
        UINavigationController * nav = [[UINavigationController alloc] initWithRootViewController:vc];
        //设置导航控制器主题色
        [nav.navigationBar setTitleTextAttributes:@{NSForegroundColorAttributeName:[UIColor whiteColor]}];
        nav.navigationBar.barTintColor = [UIColor blackColor];
//        nav.view.backgroundColor = COLOR_RGB(235, 235, 235, 0.9);
        [_VCArray addObject:nav];
    }
    
    //设置标签栏风格(默认高度49 - 上面有自定义高度方法)
    self.tabBar.barStyle = UIBarStyleBlack;
    //设置初始状态选中的下标
    self.selectedIndex = 3;
    //设置标签栏文字和图片的颜色
    self.tabBar.tintColor = [UIColor whiteColor];
    //设置标签栏的颜色
    self.tabBar.barTintColor = [UIColor blackColor];
    self.delegate = self;
    self.viewControllers = _VCArray;
	
}
	
@end
	
```

> 基本网络请求处理代码	"#import "Response.h"
"

```
#import <Foundation/Foundation.h>

@interface Response : NSObject
	
@property (nonatomic,assign) BOOL       success;        //是否正确返回
@property (nonatomic,strong) id         resultVaule;    //请求结果
@property (nonatomic,copy) NSString   * resultDesc;     //请求结果描述

@end
	
```

> 基本网络请求封装	"#import "NetworkRequest.h" 文件
	
```
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

	
```

> 基本网络请求封装	"#import "NetworkRequest.m" 文件

```
#import "NetworkRequest.h"

@implementation NetworkRequest

#pragma mark -- 普通POST网络请求
//GET请求
+ (void)startGetRequest:(NSString *)urlString Parameters:(NSDictionary *)parameters DataKey:(NSString *)dataKey CompletionHandler:(RequestCompletion)comletionHandler {
   //Get内的方法与Post类似 
}
//POST请求
+ (void)startPostRequest:(NSString *)urlString Parameters:(NSDictionary *)parameters                    DataKey:(NSString *)dataKey CompletionHandler:(RequestCompletion)comletionHandler {
    AFHTTPSessionManager *manager = [self sessionManager];
    [manager POST:[NSString stringWithFormat:@"%@%@",SEVER_URL,urlString] parameters:parameters progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        [self handlerResponse:responseObject error:nil DataKey:dataKey CompletionHandler:comletionHandler];
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        [self handlerResponse:nil error:error DataKey:dataKey CompletionHandler:comletionHandler];
    }];
}

#pragma mark -- 单文件上传

+ (void)startUploadRequest:(NSString *)urlString ImageUrl:(NSString *)imageUrl Parameters:(NSDictionary *)parameters DataKey:(NSString *)dataKey CompletionHandler:(RequestCompletion)completionHandler {
    AFHTTPSessionManager *manager = [self sessionManager];
    [manager POST:[NSString stringWithFormat:@"%@%@",SEVER_URL,urlString] parameters:parameters constructingBodyWithBlock:^(id<AFMultipartFormData>  _Nonnull formData) {
        NSData *imageData = [NSData dataWithContentsOfURL:[NSURL URLWithString:imageUrl]];
        [formData appendPartWithFileData:imageData
                                    name:@"file"
                                fileName:@"image.jpg"
                                mimeType:@"image/jpg"];
        
    } progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        [self handlerResponse:responseObject error:nil DataKey:dataKey CompletionHandler:completionHandler];
        
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        [self handlerResponse:nil error:error DataKey:dataKey CompletionHandler:completionHandler];
        
    }];
}

#pragma mark -- Private(私有方法)

+ (AFHTTPSessionManager * )sessionManager {
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json",@"text/json",@"text/html",@"text/javascript", nil];
    manager.requestSerializer.timeoutInterval = 15.0;
    return manager;
}

//处理请求
+ (void)handlerResponse:(id)responseObject error:(NSError *)error DataKey:(NSString *)dataKey CompletionHandler:(RequestCompletion)comletionHandler{
    Response * response = [[Response alloc] init];
    if (error) {
        //请求失败
        response.resultDesc = error.localizedDescription;
        if (error.code == NSURLErrorNotConnectedToInternet) {
            response.resultDesc = @"无网络连接";
        } else if (error.code == NSURLErrorTimedOut){
            response.resultDesc = @"网络连接超时";
        }
    } else{
        NSInteger resultCode = [responseObject[@"statusCode"] integerValue];
        if (resultCode == 0) {
            response.success = YES;
            response.resultVaule = responseObject[dataKey];
            response.resultDesc = responseObject[@"msg"];
        }else{
            NSString * message = responseObject[@"msg"];
            if (message) {
                response.resultDesc = message;
            }else{
                response.resultDesc = @"网络请求失败";
            }
        }
        
        if (resultCode == -1) {
            NSString * message = responseObject[@"msg"];
            if (message) {
                response.resultDesc = message;
            } else {
                response.resultDesc = @"token验证失败";
            }
            
        }
    }
    if (comletionHandler) {
        comletionHandler(response);
    }
}

@end
```

### [项目下载 - 码云链接](https://git.oschina.net/candy90/Framing-By-Candy.git) -- by Candy
