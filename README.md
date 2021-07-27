# esp32-wall_V-CNC
## 缘起
本项目缘起与maslowcnc，当时邀请孙浩钦老师一起复刻这个项目。前期项目均为孙老师完成。

Z轴部分机械结构由@999 完成设计和制作。

但在软件调试阶段，遇到了一系列的问题。导致项目搁置了一段时间。

后来发现GRBL可以在esp32上运行，于是准备迁移到esp32上。

接下来由@light 帮忙完成了坐标系的迁移。

@撒哈拉大野牛在测试阶段提供了巨大的支持。

## 改进

* 主控改为ESP32

* 固件采用ESP_GRBL

* 电机改为步进电机加减速箱
## 特点
* 系统占地面积小
* 价格便宜
* 开源

## 测试过程

* 2021年7月2日：左右轴可以移动，准确度有一定问题。

* 2021年7月9日：左右轴线缆安装和调试，移动正常，数据准确。

* 2021年7月16日：左右轴链条安装和测试，移动正常。需要校准功能的设计。

* 2021年7月23日：安装和测试Z轴，Z轴可以控制，但数据貌似有问题。



## 测试
http://maslowcommunitygarden.org/Fold-Flat-Chair.html
第一次试制椅子。

## 感谢
感谢蘑菇云创客空间的@light（solasolo）https://github.com/solasolo 和 @撒哈拉大野牛 @999 @孙浩钦(sunhaoqin) https://github.com/sunhaoqin

感谢@maslow CNC项目https://www.maslowcnc.com/

感谢@ESP_GRBL项目https://github.com/bdring/Grbl_Esp32
