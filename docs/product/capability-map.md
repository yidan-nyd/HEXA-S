[English](capability-map.md) | [中文](capability-map.zh.md)

# HEXA-S Capability Map

| Capability | Input | Output | Value | Maturity |
| --- | --- | --- | --- | --- |
| Flexible stretch sensing | Local textile stretch | Resistance / ADC change | Captures relative surface change | Demonstrated |
| Multi-channel acquisition | Six sensing regions | Channel-labelled stream | Observes several locations together | Demonstrated |
| Calibration and filtering | Raw ADC, channel ranges | `0.0–1.0` relative values | Reduces jitter and supports mapping | Demonstrated |
| Live 3D mapping | Normalised data, channel map | Blender deformation | Makes the location of change visible | Demonstrated |
| Data-quality state | Disconnect, saturation, drift, gaps | Quality state and recovery action | Prevents bad data becoming a body claim | Designed |
| Timeline and event record | Continuous data, activity, symptoms | Daily and multi-day trends | Turns a moment into comparable evidence | Designed |
| Clinical evidence summary | Trends, regions, symptoms, quality | Explainable review material | Supports user–prosthetist communication | Designed |
| Long-term pattern recognition | Multi-day personal baseline | Repeated patterns and confidence | Finds change worth reviewing | Future |
| Risk routing | Pattern, symptoms, quality, rules | Observe / recollect / professional review | Controls alert consequences | Future |
| Fitting decision support | Confirmed evidence and judgement | Candidate response and rationale | Supports fitting discussion | Future |
| Responsive lattice link | Validated regional need | TPU density / softness proposal | Explores a more adaptive interface | Future |

## Maturity rules

- `Demonstrated` requires a physical prototype, code, video, data, or repeatable test.
- `Designed` requires a defined flow, interface, data structure, and failure state.
- `Future` remains a research direction and never appears as a delivered result.
- Detecting deformation is not the same as measuring clinical dimensions.
- Finding an unusual pattern is not a diagnosis.
- Generating a recommendation does not bypass professional judgement.
