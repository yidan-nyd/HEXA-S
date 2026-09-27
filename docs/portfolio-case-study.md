[English](portfolio-case-study.md) | [中文](portfolio-case-study.zh.md)

# HEXA-S Portfolio Case Study

> Page goal: use prototype evidence, sensor data, and 3D mapping to explain how bodily change becomes decision evidence. Keep implementation details on GitHub and label every healthcare capability as Demonstrated, Designed, or Future.

## 01 | Hero

# HEXA-S

## Adaptive smart textile care

HEXA-S records how a residual limb changes throughout the day and translates multi-region stretch data into a live 3D model, providing dynamic evidence for more informed prosthetic socket fitting.

`Smart Textile · Wearable Sensing · Digital Twin · Prosthetic Care · Healthcare Innovation`

**Visual:** show the wearer, textile, and live 3D model together. Add a 10–15 second loop: wear → stretch → data → model response.

## 02 | Overview

### From flexible sensing to evidence people can discuss

| Item | Detail |
| --- | --- |
| Context | Daily residual-limb volume change and prosthetic socket fitting |
| Team | Yidan Nai and Neil Barnabas |
| Institution | University of the Arts London |
| Technology | Embroidery, Arduino, multiplexed sensing, Blender / Grasshopper, TPU printing |
| Outputs | Smart textile, multi-channel acquisition, live 3D mapping, flexible lattice studies, system workflow |

**Visual:** wearable system / sensor detail / live mapping / TPU lattice.

## 03 | Problem

### A static scan can be accurate, but the body is not static

A residual limb can change with activity, temperature, and body condition. A one-off scan captures only one moment, while a socket may become tight or loose later. Adding or removing prosthetic socks helps manage fit, but the location and pattern of change remain hard to communicate.

> **How might daily shape change become comparable, locatable evidence for a shared fitting decision?**

## 04 | System

### HEXA-S is an evidence-to-decision workflow, not a standalone sensor

```text
Flexible sensing → Relative limb-change data → Visualisation
→ Pattern review → Fitting recommendation → Human action → Outcome record
```

Mark sensing and live visualisation as **Demonstrated**. Mark longitudinal interpretation, recommendations, and the outcome loop as **Designed / Future**.

## 05 | Smart Textile Development

### Making a sensor stretch and recover with the textile

The project moved from conductive-thread trials to single and paired sensors, a six-sensor ring, and a larger zig-zag network. Conductive thread responded to stretch but produced inconsistent raw data, leading to conductive rubber cord and continued iteration on stitch paths, wiring, fabric behaviour, and material combinations.

```text
Material test → Single sensor → Two sensors → Six-sensor ring → Zig-zag network → Wearable sleeve
```

Label each prototype with `Question / Change / Evidence / Next`.

## 06 | Data to Geometry

### Turning invisible resistance change into a locatable 3D response

Arduino reads sensing regions through a multiplexer, calibrates, filters, and normalises each channel, then sends the data to Blender. Each channel maps to a known body region and 3D object.

```text
Stretch → Resistance → ADC → Calibration → Normalised data → 3D deformation
```

**Critical label:** the prototype visualises relative stretch. It is not a clinically accurate dimensional measurement until geometric calibration is validated against ground truth.

## 07 | From Snapshot to Timeline

### The value is not one frame, but how change repeats over time

Live visualisation proves the pipeline. Product value comes from comparing when a change occurs, where it concentrates, how long it lasts, and whether it coincides with activity or discomfort.

Show four screens: `Current fit / Daily timeline / Change map / Evidence summary`.

## 08 | AI and Clinical Collaboration

### AI finds and explains patterns; people interpret meaning and act

- Detect repeated patterns rather than react to one peak.
- Separate ordinary activity, sensor failure, and possible health concern.
- Explain location, time, magnitude, duration, and confidence.
- Let users and clinicians confirm, edit, or reject a recommendation.

```text
Finding: lateral change repeatedly exceeded the personal baseline on three afternoons
Evidence: C3/C4, 14:00–18:00, three repetitions, good data quality
Limit: the system cannot determine tissue health or socket cause alone
Next step: record discomfort and skin condition, then review with a prosthetist
```

Do not show autonomous diagnosis or adjustment without real validation and an appropriate regulatory basis.

## 09 | Adaptive Response

### Exploring a better interface between soft tissue and a rigid socket

3D-printed TPU lattices test different softness and density levels. They are a data-informed material study, not an automatically generated or clinically validated final socket component.

## 10 | Prototype Strategy and Validation

| Layer | Current evidence | Next question |
| --- | --- | --- |
| Sensor | Readable resistance change | Repeatability, hysteresis, drift, durability |
| Garment | Multi-region embroidered structure | Comfort, washing, wiring, skin safety |
| Data | Acquisition, calibration, filtering | Long-term stability, missing data, baseline |
| Visualisation | Live 3D response | Geometric validity, clinical readability |
| Decision | Workflow and AI principles | User research, clinical judgement, outcomes |

- **Demonstrated:** sensing, multi-channel acquisition, Arduino–Blender visualisation.
- **Designed:** timeline, change map, evidence summary, shared decision interface.
- **Future:** AI pattern recognition, clinical validation, adaptive lattice integration.

## 11 | Outcome and Reflection

### The project designs how body data enters professional decisions

HEXA-S connects textile practice, embedded electronics, data visualisation, and digital fabrication. It also establishes an essential healthcare boundary: visualisation is not measurement validity, prediction is not diagnosis, and a recommendation is not a clinical decision.

> HEXA-S shows that flexible textiles can turn daily bodily change into continuous, locatable evidence. The next task is not simply adding intelligence, but proving that the evidence is reliable, understandable, and useful in shared decisions.

## Content split

| Location | Content |
| --- | --- |
| Portfolio | Outcomes, problem, decisions, prototype evolution, evidence, reflection |
| README | Positioning, system loop, maturity, boundaries, roadmap |
| Technical guide | BOM, wiring, firmware, calibration, Blender, troubleshooting |
| Capability map | Inputs, outputs, value, evidence, maturity |
| AI principles | Explanation, risk, human control, failure, data governance |
| Validation | Engineering, wear, algorithm, clinical workflow, safety |
