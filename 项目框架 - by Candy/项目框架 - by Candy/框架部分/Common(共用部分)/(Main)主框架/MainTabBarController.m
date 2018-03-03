//
//  MainTabBarController.m
//  项目框架 - by Candy
//
//  Created by Candy on 17/1/5.
//  Copyright © 2017年 Candy. All rights reserved.
//

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
