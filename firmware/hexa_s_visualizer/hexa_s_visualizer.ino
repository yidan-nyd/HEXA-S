/*
  HEXA-S smart textile visualizer

  Target: Arduino Mega 2560 + CD74HC4067
  Output: BlendixSerial CSV (Fixed), one 9-value transform per sensor

  The default configuration reads six sensors and drives Scale Z for six
  Blender objects. Calibrate every textile sample before visualization.
*/

#include <Arduino.h>

constexpr uint32_t SERIAL_BAUD = 115200;
constexpr uint8_t SENSOR_COUNT = 6;  // 1..16 for one CD74HC4067
constexpr uint8_t MUX_SIGNAL_PIN = A0;
constexpr uint8_t MUX_SELECT_PINS[4] = {2, 3, 4, 5};  // S0, S1, S2, S3

constexpr uint8_t ADC_SAMPLES = 8;
constexpr float FILTER_ALPHA = 0.25f;
constexpr float MAX_SCALE_ADDITION = 0.75f;
constexpr uint8_t FRAME_RATE_HZ = 20;

// Set true only while collecting raw values in Arduino Serial Monitor.
constexpr bool CALIBRATION_MODE = false;

// Replace these starter limits with measurements from the actual textile.
uint16_t CAL_MIN[SENSOR_COUNT] = {0, 0, 0, 0, 0, 0};
uint16_t CAL_MAX[SENSOR_COUNT] = {1023, 1023, 1023, 1023, 1023, 1023};
bool INVERT[SENSOR_COUNT] = {false, false, false, false, false, false};

float filtered[SENSOR_COUNT] = {0};
bool filterInitialized = false;

void selectMuxChannel(uint8_t channel) {
  for (uint8_t bit = 0; bit < 4; ++bit) {
    digitalWrite(MUX_SELECT_PINS[bit], (channel >> bit) & 0x01);
  }
}

uint16_t readMuxRaw(uint8_t channel) {
  selectMuxChannel(channel);
  delayMicroseconds(5);

  // Discard the first conversion after switching channels.
  analogRead(MUX_SIGNAL_PIN);

  uint32_t total = 0;
  for (uint8_t sample = 0; sample < ADC_SAMPLES; ++sample) {
    total += analogRead(MUX_SIGNAL_PIN);
  }
  return static_cast<uint16_t>(total / ADC_SAMPLES);
}

float normalizeReading(uint16_t raw, uint8_t channel) {
  const int32_t minimum = CAL_MIN[channel];
  const int32_t maximum = CAL_MAX[channel];

  if (maximum <= minimum) {
    return 0.0f;
  }

  float value = static_cast<float>(static_cast<int32_t>(raw) - minimum) /
                static_cast<float>(maximum - minimum);
  value = constrain(value, 0.0f, 1.0f);

  if (INVERT[channel]) {
    value = 1.0f - value;
  }
  return value;
}

void printRawFrame(const uint16_t raw[SENSOR_COUNT]) {
  for (uint8_t channel = 0; channel < SENSOR_COUNT; ++channel) {
    if (channel > 0) {
      Serial.print(',');
    }
    Serial.print(raw[channel]);
  }
  Serial.println();
}

void printCsvValue(float value, bool &firstValue) {
  if (!firstValue) {
    Serial.print(',');
  }
  Serial.print(value, 3);
  firstValue = false;
}

void sendBlendixFrame() {
  bool firstValue = true;

  for (uint8_t channel = 0; channel < SENSOR_COUNT; ++channel) {
    const float scaleZ = 1.0f + filtered[channel] * MAX_SCALE_ADDITION;
    const float transform[9] = {
        0.0f, 0.0f, 0.0f,  // Location X, Y, Z
        0.0f, 0.0f, 0.0f,  // Rotation X, Y, Z
        1.0f, 1.0f, scaleZ  // Scale X, Y, Z
    };

    for (uint8_t valueIndex = 0; valueIndex < 9; ++valueIndex) {
      printCsvValue(transform[valueIndex], firstValue);
    }
  }

  Serial.println(';');
}

void setup() {
  for (uint8_t bit = 0; bit < 4; ++bit) {
    pinMode(MUX_SELECT_PINS[bit], OUTPUT);
    digitalWrite(MUX_SELECT_PINS[bit], LOW);
  }

  pinMode(MUX_SIGNAL_PIN, INPUT);
  Serial.begin(SERIAL_BAUD);
}

void loop() {
  uint16_t raw[SENSOR_COUNT];

  for (uint8_t channel = 0; channel < SENSOR_COUNT; ++channel) {
    raw[channel] = readMuxRaw(channel);
  }

  if (CALIBRATION_MODE) {
    printRawFrame(raw);
  } else {
    for (uint8_t channel = 0; channel < SENSOR_COUNT; ++channel) {
      const float normalized = normalizeReading(raw[channel], channel);
      if (!filterInitialized) {
        filtered[channel] = normalized;
      } else {
        filtered[channel] += FILTER_ALPHA * (normalized - filtered[channel]);
      }
    }
    filterInitialized = true;
    sendBlendixFrame();
  }

  delay(1000 / FRAME_RATE_HZ);
}
