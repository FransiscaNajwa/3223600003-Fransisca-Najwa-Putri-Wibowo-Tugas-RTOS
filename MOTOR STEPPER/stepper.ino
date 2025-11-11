#include <Arduino.h>
#include <AccelStepper.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// ================== Konfigurasi Pin ==================
#define STEP_PIN 18
#define DIR_PIN 19
#define EN_PIN 20

// ================== Objek Stepper ==================
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

// ================== Batas Posisi ==================
const long MAX_POS = 800;
const long MIN_POS = 0;

// ================== Variabel Global ==================
volatile bool motorDirection = true; // true = kanan, false = kiri

// ================== Task Handle ==================
TaskHandle_t TaskStepper;
TaskHandle_t TaskControl;

// ================== Task Stepper (Core 1) ==================
void taskStepper(void *pvParameters) {
  Serial.printf("[Core %d] Task Stepper berjalan\n", xPortGetCoreID());

  while (1) {
    stepper.run(); // Jalankan motor
    vTaskDelay(1); // Supaya FreeRTOS tetap responsif
  }
}

// ================== Task Kontrol Arah (Core 0) ==================
void taskControl(void *pvParameters) {
  Serial.printf("[Core %d] Task Control berjalan\n", xPortGetCoreID());

  while (1) {
    long currentPos = stepper.currentPosition();

    // Jika sudah mencapai batas posisi, ubah arah
    if (motorDirection && currentPos >= MAX_POS) {
      motorDirection = false;
      stepper.moveTo(MIN_POS);
      Serial.println(">> Berubah ke arah KIRI");
    } 
    else if (!motorDirection && currentPos <= MIN_POS) {
      motorDirection = true;
      stepper.moveTo(MAX_POS);
      Serial.println("<< Berubah ke arah KANAN");
    }

    vTaskDelay(pdMS_TO_TICKS(100)); // Cek arah tiap 100 ms
  }
}

// ================== Setup ==================
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== FreeRTOS Dual-Core Stepper Demo ===");

  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW); // aktifkan driver stepper

  stepper.setMaxSpeed(900);
  stepper.setAcceleration(400);
  stepper.moveTo(MAX_POS); // mulai ke arah kanan

  // Task untuk kontrol stepper di Core 1
  xTaskCreatePinnedToCore(taskStepper, "StepperTask", 4096, NULL, 2, &TaskStepper, 1);

  // Task untuk ubah arah otomatis di Core 0
  xTaskCreatePinnedToCore(taskControl, "ControlTask", 4096, NULL, 1, &TaskControl, 0);

  Serial.println("Semua task telah dibuat!");
}

void loop() {
  // Kosong, semua dijalankan oleh FreeRTOS
}
