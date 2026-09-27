[English](portfolio-case-study.md) | [中文](portfolio-case-study.zh.md)

# HEXA-S 个人网站详情页展示文档

> 页面定位：用真实原型、传感数据和 3D 映射结果讲清楚“身体变化如何成为决策证据”。正文只保留结论；接线、标定、算法边界和验证方法链接至 GitHub。所有健康与临床表述必须区分 Demonstrated / Designed / Future。

---

## 01｜Hero

# HEXA-S

## Adaptive smart textile care

HEXA-S 是一套面向假肢使用者的智能织物系统：它记录残肢在一天中的形态变化，将多区域拉伸数据转化为实时 3D 模型，为更准确、更具适应性的接受腔设计提供动态证据。

`Smart Textile · Wearable Sensing · Digital Twin · Prosthetic Care · Healthcare Innovation`

【配图｜全屏主视觉】佩戴者、智能织物和实时 3D 可视化同框；可叠加 10–15 秒“穿戴 → 拉伸 → 数据 → 模型响应”影片。

---

## 02｜Overview

### 从柔性传感器到可讨论的身体变化证据

| 项目 | 内容 |
| --- | --- |
| 场景 | 残肢体积日内波动与假肢接受腔适配 |
| 团队 | Yidan Nai、Neil Barnabas |
| 机构 | University of the Arts London |
| 技术 | 刺绣传感、Arduino、多路采集、Blender / Grasshopper、TPU 3D 打印 |
| 产出 | 智能织物、多通道采集、实时 3D 映射、柔性晶格探索、系统工作流 |

【配图｜成果四宫格】穿戴与整体结构 / 传感器细节 / 3D 数据映射 / TPU 晶格样件。

---

## 03｜Problem

### 静态扫描很准确，但身体不是静态的

残肢会随活动、温度和身体状态发生体积变化。一次 3D 扫描只能记录一个时间点，因此接受腔可能在不同时段过紧或过松。使用者通常依靠加减袜套处理，但位置、幅度和规律很难准确传达给假肢技师。

> **如何把日常生活中发生的形态波动，转化为可比较、可定位、可用于共同决策的证据？**

【配图】`Static scan / Changing body` 对比；一天内的轮廓变化；过紧、过松与不适的关系。

---

## 04｜System

### HEXA-S 不是单一传感器，而是一条从证据到决策的工作流

```text
柔性传感器采集
→ 残肢变化数据
→ 数据可视化
→ 异常与趋势判断
→ 假肢适配建议
→ 使用者 / 临床人员采取行动
→ 记录结果
```

这是页面核心。把“采集与实时可视化”标为 **Demonstrated**，把“长期判断、建议与行动闭环”标为 **Designed / Future**。

---

## 05｜Smart Textile Development

### 让传感器随织物一起拉伸、恢复，并持续产生可读数据

项目从导电线单传感器开始，逐步测试双传感器、六点环形结构和大范围之字形网络。早期导电线能响应拉伸，但一致性不足；后续以导电橡胶绳建立更稳定的基线，并持续调整刺绣路径、线材、走线和固定方式。

【配图｜演化时间线】

```text
Material test → Single sensor → Two sensors → Six-sensor ring → Zig-zag network → Wearable sleeve
```

每阶段只标注 `Question / Change / Evidence / Next`，不做纯过程堆图。

---

## 06｜Data to Geometry

### 将不可见的电阻变化，映射成可定位的 3D 形态变化

Arduino 通过多路复用器读取不同传感区域，完成逐通道标定、滤波和归一化，再经串口发送至 Blender。每个通道对应明确的身体区域和 3D 单元。

```text
Stretch → Resistance → ADC → Calibration → Normalised data → 3D deformation
```

【配图】传感点—身体区域编号 / 电子系统 / 原始与滤波数据 / 织物和模型同步视频。

**必须说明**：当前表达相对拉伸；未经几何标定和真实测量验证，不能称为精确临床尺寸。

---

## 07｜From Snapshot to Timeline

### 真正的价值不在某一帧，而在变化如何随时间重复出现

实时可视化证明了数据链路；下一步价值来自连续比较：何时变化、集中在哪、持续多久、是否与活动或不适同时出现。

【配图｜四个关键页面】

1. Current fit：当前区域变化与数据质量；
2. Daily timeline：日内曲线与关键事件；
3. Change map：跨时段 / 跨日空间对比；
4. Evidence summary：使用者和技师共同讨论摘要。

---

## 08｜AI & Clinical Collaboration

### AI 负责发现模式和解释证据，人负责判断意义和采取行动

- 识别长期模式，而非追逐单点波动；
- 区分正常活动、传感异常和潜在健康风险；
- 用位置、时间、幅度、持续时长和置信度解释预测；
- 允许使用者与临床人员确认、修改或拒绝建议。

【配图｜一组完整状态】

```text
发现：过去三天下午，外侧区域持续高于个人基线
依据：C3 / C4；14:00–18:00；三次重复；数据质量良好
限制：系统无法单独判断组织健康或接受腔问题
建议：记录不适与皮肤状态，并在下次适配时与假肢技师复核
```

不要展示“AI 已诊断”或“系统自动调整”，除非未来有真实验证与监管依据。

---

## 09｜Adaptive Response

### 从看见变化，到探索更合适的身体—接受腔界面

团队用 3D 打印 TPU 晶格测试不同柔软度与密度，探索刚性接受腔和软组织之间的响应式缓冲结构。这是材料研究，不是当前系统已经自动生成或临床验证的最终方案。

【配图】晶格样件 / 压缩或弯曲测试 / `Data-informed concept` 标签 / 变化区域到材料属性的概念映射。

---

## 10｜Prototype Strategy & Validation

### 分层验证材料、数据、空间映射和临床价值

| 层级 | 当前证据 | 下一步问题 |
| --- | --- | --- |
| Sensor | 拉伸产生可读电阻变化 | 重复性、迟滞、漂移、耐用性 |
| Garment | 多区域刺绣与穿戴结构 | 舒适、穿脱、洗涤、走线与皮肤安全 |
| Data | 多通道采集、标定、滤波 | 长期稳定性、缺失数据、个体基线 |
| Visualisation | 实时 3D 对象响应 | 几何有效性、临床可读性 |
| Decision | 工作流与 AI 原则 | 真实使用者研究、临床判断与结果改善 |

- **Demonstrated**：传感材料、多通道采集、Arduino–Blender 实时可视化；
- **Designed**：时间线、变化地图、证据摘要、共同决策界面；
- **Future**：AI 模式识别、真实临床验证、自适应晶格联动。

---

## 11｜Outcome & Reflection

### 我设计的不只是一个可穿戴原型，而是身体数据进入专业决策的方式

项目把纺织工艺、嵌入式电子、数据可视化和数字制造连接成工作系统，也明确了医疗产品的边界：可视化不等于测量有效，预测不等于诊断，建议不等于临床决定。

> HEXA-S 证明柔性织物可以把日常身体变化转化为连续、可定位的证据；下一步不是增加更多智能，而是验证这些证据是否可靠、可理解，并真正改善共同决策。

---

## 页面末尾

- View Technical Repository
- Read System & Capability Map
- Read Clinical AI Principles
- View Project Film
- View James Dyson Award Entry
- Next Project

## GitHub 与网站的内容分工

| 位置 | 保留内容 |
| --- | --- |
| 个人网站 | 结果、问题、关键决策、原型演化、证据、反思 |
| README | 项目定位、系统闭环、成熟度、边界、路线图 |
| Technical Guide | BOM、接线、固件、标定、Blender、故障排查 |
| Capability Map | 输入、输出、价值、证据与成熟度 |
| AI Principles | 解释、风险、人工控制、失败恢复、数据治理 |
| Validation | 工程、穿戴、算法、临床工作流与安全测试 |
