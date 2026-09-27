[English](clinical-decision-principles.md) | [中文](clinical-decision-principles.zh.md)

# HEXA-S 临床 AI 协同原则

1. **Evidence before interpretation**：展示区域、时间、幅度、重复次数、数据质量和个人基线；无可靠证据时不补全结论。
2. **Trend before point**：单点峰值先视为待检查信号；可重复模式才进入更高一级复核。
3. **Separate body change from sensor failure**：先检查断连、饱和、漂移、串扰和标定过期，再解释身体变化。
4. **Explain in human terms**：使用者看到何时、何处、持续多久和下一步；临床人员可继续查看曲线与标定记录。
5. **Advice is not diagnosis**：使用“继续观察、记录症状、重新测量、联系临床人员”，不把模型输出描述为诊断。
6. **Human confirmation before adaptation**：改变袜套、接受腔或缓冲结构前，必须由使用者与合格专业人员确认。
7. **Escalate symptoms, not only signals**：疼痛、皮肤破损、颜色改变或麻木优先人工处理，不因传感数据正常而压低风险。
8. **Personal baseline with visible limits**：说明数据覆盖时间、缺口与适用条件；跨用户比较不能代替个体评估。
9. **Consent, minimisation, control**：明确用途、保存期限、共享对象和撤回方式；使用者可以暂停、导出和删除。
10. **Safe failure**：断连、低电量、标定失效或低置信度时进入可见安全状态并说明恢复步骤。

## 推荐界面模式

- `Evidence Summary`：趋势、位置、时间、质量与限制。
- `Compare with Baseline`：与个人基线和相似情境对比。
- `Low-confidence Recovery`：重新穿戴、重新标定或补充症状。
- `Clinical Review Pack`：预约前可导出的共同讨论摘要。
- `Confirm Before Change`：明确拟调整内容、预期影响与撤回方式。
- `Human Takeover`：暂停自动判断并交给使用者 / 临床人员。
