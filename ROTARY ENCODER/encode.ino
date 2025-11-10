#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// ==================== Pin ====================
#define CLK 2
#define DT 14
#define SW 4

// ==================== Variabel global ====================
volatile int encoderValue = 0;

TaskHandle_t TaskEncoder;
TaskHandle_t TaskButtonCore0;
TaskHandle_t TaskButtonCore1;

// ==================== Task membaca rotary encoder (full quadrature) ====================
void Task_ReadEncoder(void *pvParameters) {
  int lastState = (digitalRead(CLK) << 1) | digitalRead(DT);

  for (;;) {
    int state = (digitalRead(CLK) << 1) | digitalRead(DT);
    int delta = 0;

    if (state != lastState) {
      switch ((lastState << 2) | state) {
        case 0b0001:
        case 0b0111:
        case 0b1110:
        case 0b1000: delta = 1; break; // CW
        case 0b0010:
        case 0b0100:
        case 0b1101:
        case 0b1011: delta = -1; break; // CCW
      }
      encoderValue += delta;
      lastState = state;
    }

    vTaskDelay(pdMS_TO_TICKS(1)); // polling cepat
  }
}

// ==================== Task tombol push ====================
void Task_Button(void *pvParameters) {
  int buttonPin = *((int*)pvParameters);
  int coreID = xPortGetCoreID();
  pinMode(buttonPin, INPUT_PULLUP);

  unsigned long lastPress = 0;

  for (;;) {
    if (digitalRead(buttonPin) == LOW) {
      unsigned long now = millis();
      if (now - lastPress > 200) { // debounce
        lastPress = now;
        Serial.printf("[CORE %d] Tombol ditekan -> Encoder Value: %d\n", coreID, encoderValue);
      }

      while (digitalRead(buttonPin) == LOW) {
        vTaskDelay(pdMS_TO_TICKS(10));
      }
    }
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

// ==================== Setup ====================
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== Dual-Core Encoder Wokwi (Quadrature) ===");

  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

  // Task polling encoder (Core 1)
  xTaskCreatePinnedToCore(Task_ReadEncoder, "EncoderReader", 2048, NULL, 2, &TaskEncoder, 1);

  // Task tombol push (Core 0 & Core 1)
  static int btn = SW;
  xTaskCreatePinnedToCore(Task_Button, "ButtonCore0", 2048, &btn, 1, &TaskButtonCore0, 0);
  xTaskCreatePinnedToCore(Task_Button, "ButtonCore1", 2048, &btn, 1, &TaskButtonCore1, 1);

  Serial.println("Dual-Core Tasks Started!");
}

void loop() {
  // kosong, semua dijalankan FreeRTOS
}
