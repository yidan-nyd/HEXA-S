[English](implementation-guide.md) | [中文](implementation-guide.zh.md)

# HEXA-S 技术实现与复现指南

本指南保留仓库原有教程的工程重点。项目定位、成熟度和医疗边界见根目录 `README.zh.md`。

## 数据链路

```text
织物拉伸 → 传感器电阻变化 → 分压电路 → CD74HC4067
→ Arduino Mega ADC → 标定 / 归一化 / 滤波
→ USB Serial / CSV → BlendixSerial → Blender 3D 变形
```

## 环境与硬件

| 项目 | 说明 |
| --- | --- |
| 开发环境 | Windows 10；Arduino IDE + Arduino AVR Boards |
| 主控 | Arduino Mega 2560 |
| 多路复用 | CD74HC4067 16 通道模拟多路复用器 |
| 传感 | 6 个起的拉伸传感器或导电橡胶绳感测单元 |
| 3D 可视化 | Blender 4.2+；BlendixSerial 扩展 |
| 数据 | CSV Fixed；115200 baud；约 20 Hz |

每个传感器与固定电阻构成分压电路。固定电阻应根据传感器静止与目标拉伸状态下的实测阻值选取，不要照搬概念图数值。

## Arduino Mega ↔ CD74HC4067

| CD74HC4067 | Arduino Mega | 说明 |
| --- | --- | --- |
| VCC | 5V | 先确认模块额定电压 |
| GND | GND | 共地 |
| S0–S3 | D2–D5 | 通道选择 |
| SIG / COM | A0 | 模拟输入 |
| EN | GND | 低电平使能 |

## 安全组装顺序

1. 断电时连接一个传感器和一个分压电阻。
2. 检查 5V 与 GND 无短路；通电后确认 A0 随拉伸变化。
3. 接入多路复用器，先验证 `C0`，再逐个增加通道。
4. 在柔性织物与刚性导线交界处增加应力释放。
5. 固定走线并避免导电路径接触，同时保留织物活动范围。
6. 检查完成后连接 USB，逐通道标定并联调 Blender。

## 固件与标定

打开 `firmware/hexa_s_visualizer/hexa_s_visualizer.ino`，选择 Arduino Mega 2560 / ATmega2560 与正确端口后上传。

1. 将 `CALIBRATION_MODE` 设为 `true`。
2. 在 Serial Monitor 以 `115200 baud` 记录每通道静止与最大设计拉伸值。
3. 为读数留少量余量，写入 `CAL_MIN[]` 与 `CAL_MAX[]`。
4. 如方向反转，将对应 `INVERT[]` 设为 `true`。
5. 恢复 `CALIBRATION_MODE = false` 并重新上传。
6. 连接 Blender 前关闭 Serial Monitor，避免 COM 口占用冲突。

面料、装配、温湿度、重复加载和重新缝制都会引起基线变化。每件样品应保留独立标定记录。

## Blender 映射

1. 安装 BlendixSerial 扩展。
2. 创建或导入六个对象，顺序与 `C0–C5` 一致。
3. 对对象执行 Apply Scale，使初始值为 `1,1,1`。
4. 连接正确 COM 口，设 `115200`、Receive、CSV Fixed。
5. 以 `C0–C5` 顺序添加对象，仅启用 `Scale Z`。
6. 点击 Start，检查各织物区域只改变对应对象。

当前固件每对象输出位置 XYZ、旋转 XYZ、缩放 XYZ 九个值，只改变第九个值 `Scale Z`。通道、身体区域和 Blender 对象必须维护同一份映射表。

## 功能验证

| 检查 | 预期结果 |
| --- | --- |
| 单通道拉伸 | 只有对应对象明显变化 |
| 回到静止 | 对象接近初始状态，无持续大漂移 |
| 多区域拉伸 | 通道独立更新，不串位 |
| 连续运行 10 分钟 | 通信不中断，延迟不持续累积 |
| USB 断开 / 重连 | 停止更新，并可恢复 |
| 重复同一动作 | 趋势相近；差异被记录 |

## 常见问题

| 问题 | 检查 |
| --- | --- |
| COM 口缺失 | 数据线、驱动、设备管理器 |
| Blender 无法连接 | 关闭 Serial Monitor；核对端口与波特率 |
| 对象不动 | Receive、CSV Fixed、Start、Scale Z |
| 通道错位 | `C0–C5`、`SENSOR_COUNT`、对象顺序 |
| 数据抖动 | 共地、焊点、长线干扰、采样数、滤波参数 |
| 饱和在 0 / 1023 | 分压、电阻选型、开路或短路 |
| 方向相反 | `INVERT[]` |
| 显示卡顿 | 降低帧率、增加更新间隔、降低网格复杂度 |

## 来源与许可

- [BlendixSerial](https://electronicstree.com/blendixserial-addon/)：Blender 端串口扩展和通信格式。
- [blendixserial-arduino](https://github.com/electronicstree/blendixserial-arduino)：可选 Arduino 库。
- Arduino–Blender 数据可视化参考：3D Temperature Gauge with Blender and Arduino。

仓库应在确定开源策略后增加 `LICENSE`。如复制或修改 GPL-3.0 上游代码，必须遵守其许可证并保留归属。
