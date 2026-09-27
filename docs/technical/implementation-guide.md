[English](implementation-guide.md) | [中文](implementation-guide.zh.md)

# HEXA-S Technical Implementation Guide

This guide contains the reproducible engineering path. See the root README for positioning, maturity, and healthcare boundaries.

## Data pipeline

```text
Textile stretch → Sensor resistance → Voltage divider → CD74HC4067
→ Arduino Mega ADC → Calibration / normalisation / filtering
→ USB serial / CSV → BlendixSerial → Blender deformation
```

## Environment and hardware

| Item | Detail |
| --- | --- |
| Development | Windows 10; Arduino IDE with Arduino AVR Boards |
| Controller | Arduino Mega 2560 |
| Multiplexer | CD74HC4067 16-channel analogue multiplexer |
| Sensing | Six or more stretch sensors / conductive rubber cord elements |
| Visualisation | Blender 4.2+ with BlendixSerial |
| Stream | CSV Fixed, 115200 baud, approximately 20 Hz |

Each sensor forms a voltage divider with a fixed resistor. Measure the resting and intended maximum-stretch resistance first; do not copy a resistor value from a concept diagram.

## Arduino Mega to CD74HC4067

| CD74HC4067 | Arduino Mega | Purpose |
| --- | --- | --- |
| VCC | 5V | Confirm module rating |
| GND | GND | Common ground |
| S0–S3 | D2–D5 | Channel selection |
| SIG / COM | A0 | Analogue input |
| EN | GND | Active-low enable |

## Safe assembly sequence

1. With power disconnected, build one sensor and divider.
2. Check for a 5V–GND short, then verify that A0 changes with stretch.
3. Add the multiplexer; validate `C0` before adding channels.
4. Add strain relief between flexible textile and rigid wire.
5. Secure wiring without restricting movement or allowing conductive paths to touch.
6. Inspect before USB connection, then calibrate each channel and test Blender.

## Firmware and calibration

Open `firmware/hexa_s_visualizer/hexa_s_visualizer.ino`, select Arduino Mega 2560 / ATmega2560 and the correct port, then upload.

1. Set `CALIBRATION_MODE` to `true`.
2. At `115200 baud`, record stable rest and maximum-design-stretch values for each channel.
3. Add a small margin and enter values in `CAL_MIN[]` and `CAL_MAX[]`.
4. If direction is reversed, set the channel's `INVERT[]` value to `true`.
5. Return `CALIBRATION_MODE` to `false` and upload again.
6. Close Serial Monitor before Blender; both cannot normally use one COM port together.

Fabric, mounting, temperature, humidity, repeated loading, and resewing can change the baseline. Keep a calibration record for each sample.

## Blender mapping

1. Install BlendixSerial.
2. Create or import six objects in `C0–C5` order.
3. Apply object scale so each begins at `1,1,1`.
4. Connect the correct port at `115200`, Receive, CSV Fixed.
5. Add objects in channel order and enable only `Scale Z`.
6. Start and verify that each textile region changes only its mapped object.

The firmware emits location XYZ, rotation XYZ, and scale XYZ for each object. It currently changes only the ninth value, `Scale Z`. Maintain one authoritative mapping between channel, body region, and Blender object.

## Functional validation

| Test | Expected result |
| --- | --- |
| Stretch one channel | Only its mapped object changes significantly |
| Return to rest | Object approaches baseline without persistent large drift |
| Stretch multiple regions | Objects update independently without swaps |
| Run for ten minutes | Connection remains active; latency does not accumulate |
| Disconnect / reconnect USB | Updating stops and can recover |
| Repeat one movement | Trend remains broadly similar; differences are recorded |

## Troubleshooting

| Problem | Check |
| --- | --- |
| Missing COM port | Data cable, driver, Device Manager |
| Blender cannot connect | Close Serial Monitor; confirm port and baud |
| Objects do not move | Receive, CSV Fixed, Start, Scale Z |
| Wrong channel order | `C0–C5`, `SENSOR_COUNT`, object list |
| Noisy data | Ground, joints, long wires, samples, filter settings |
| Reading stuck at 0 / 1023 | Divider, resistor choice, open / short sensor |
| Reversed direction | `INVERT[]` |
| Stuttering | Lower frame rate, increase update delay, reduce mesh complexity |

## References and licence

- [BlendixSerial](https://electronicstree.com/blendixserial-addon/)
- [blendixserial-arduino](https://github.com/electronicstree/blendixserial-arduino)
- Reference approach: 3D Temperature Gauge with Blender and Arduino.

Add a root `LICENSE` after selecting the project's open-source terms. Copied or modified GPL-3.0 upstream code must retain attribution and comply with that licence.
