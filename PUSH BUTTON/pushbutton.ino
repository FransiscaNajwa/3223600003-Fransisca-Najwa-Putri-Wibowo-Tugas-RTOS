#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

// Pin
#define BUTTON1_PIN 15
#define BUTTON2_PIN 12
#define LED_PIN     5

// Global
volatile bool ledState = LOW; // status LED
SemaphoreHandle_t ledMutex;

// ==================== Core 0 ====================
void TaskButtonCore0(void *pvParameters) {
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  for (;;) {
    if (digitalRead(BUTTON1_PIN) == LOW) { // tombol ditekan
      if (xSemaphoreTake(ledMutex, portMAX_DELAY)) {
        ledState = !ledState;               // toggle LED
        digitalWrite(LED_PIN, ledState);
        Serial.printf("[Core 0] LED toggled: %s\n", ledState ? "ON" : "OFF");
        xSemaphoreGive(ledMutex);
      }
      vTaskDelay(200 / portTICK_PERIOD_MS); // debounce
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

// ==================== Core 1 ====================
void TaskButtonCore1(void *pvParameters) {
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  for (;;) {
    if (digitalRead(BUTTON2_PIN) == LOW) { // tombol ditekan
      if (xSemaphoreTake(ledMutex, portMAX_DELAY)) {
        ledState = !ledState;               // toggle LED
        digitalWrite(LED_PIN, ledState);
        Serial.printf("[Core 1] LED toggled: %s\n", ledState ? "ON" : "OFF");
        xSemaphoreGive(ledMutex);
      }
      vTaskDelay(200 / portTICK_PERIOD_MS); // debounce
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  ledMutex = xSemaphoreCreateMutex();

  xTaskCreatePinnedToCore(TaskButtonCore0, "Core0Btn", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(TaskButtonCore1, "Core1Btn", 2048, NULL, 1, NULL, 1);
}

void loop() {}
