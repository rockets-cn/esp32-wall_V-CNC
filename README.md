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
* 2021年7月30日：Z轴正常运行，经调试，Z轴精度达到要求。主要问题为步进电机驱动器接地不可靠。修改了代码中Z轴必须和X、Y轴一起运动的bug

## TODO list
 1. * [ ] 寻求X、Y轴精确定位解决方案。拟调研tof和超声波测距。
 2. * [ ] 重新设计中心圆盘。

## 测试
http://maslowcommunitygarden.org/Fold-Flat-Chair.html
第一次试制椅子。

## 感谢
感谢蘑菇云创客空间的@light（solasolo）https://github.com/solasolo 和 @撒哈拉大野牛 @999 @孙浩钦(sunhaoqin) https://github.com/sunhaoqin

感谢@maslow CNC项目https://www.maslowcnc.com/

感谢@ESP_GRBL项目https://github.com/bdring/Grbl_Esp32



# esp32-wall_V-CNC
## Origin
This project originated with maslowcnc, when we invited Mr. Sun Haoqin to reproduce this project together. The first phase of the project was all done by Mr. Sun.

The mechanical structure of Z-axis part was designed and made by @999.

But in the software debugging stage, a series of problems were encountered. The project was put on hold for some time.

Later, we found that GRBL could run on esp32, so we were ready to migrate to esp32.

Next the migration of coordinate system was done by @light with help.

@SaharaBison provided great support during the testing phase.

## Improvements

* Main control changed to ESP32

* Firmware used ESP_GRBL

* Motor changed to stepper motor with gearbox
## Features
* Small system footprint
* Cheap price
* Open source

## Testing process

* July 2, 2021: Left and right axes can move, accuracy has some problems.

* July 9, 2021: Left and right axis cable installation and commissioning, moving normally, accurate data.

* July 16, 2021: Left and right axis chains installed and tested, moving normally. Need to calibrate the design of the function.

* July 23, 2021: Z-axis installed and tested, Z-axis can be controlled, but the data seems to have problems.
* July 30, 2021: Z-axis operates normally, and after debugging, Z-axis accuracy meets the requirement. The main problem is that the stepper motor driver grounding is not reliable. Modified the bug in the code that Z-axis must move with X and Y-axis

## TODO list
 1. * [ ] Seeking X, Y axis precise positioning solution. Proposed to investigate tof and ultrasonic distance measurement.
 2. * [ ] Redesign the center disc.

## Testing
http://maslowcommunitygarden.org/Fold-Flat-Chair.html
First test chair.

## Thanks
Thanks to @light (solasolo) https://github.com/solasolo and @saharabison @999 @sunhaoqin (sunhaoqin) https://github.com/sunhaoqin from Mushroom Cloud Makerspace

Thanks to @maslow CNC project https://www.maslowcnc.com/

Thanks to @ESP_GRBL project https://github.com/bdring/Grbl_Esp32
 Translated with www.DeepL.com/Translator (free version)
