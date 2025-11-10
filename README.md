Nama : Fransisca Najwa Putri Wibowo
Kelas: 3 D4 Teknik Komputer A
NRP : 3223600003


Daftar Percobaan (Total 8 Program)
| No | Percobaan      | Peripheral        |
| -- | -------------- | ----------------- |
| 1  | OLED Display   | OLED SSD1306 I2C  |
| 2  | LED Control    | GPIO Output       |
| 3  | Buzzer         | PWM Speaker       |
| 4  | Servo Motor    | PWM               |
| 5  | Push Button    | GPIO Input        |
| 6  | Potensiometer  | ADC Input         |
| 7  | Rotary Encoder | CLK / DT / Button |
| 8  | Stepper Motor  | Step/Dir Driver   |

Langkah Percobaan
1. Hubungkan peripheral ke ESP32-S3 sesuai diagram wiring
2. Buat program terpisah untuk tiap modul/peripheral
3. Jalankan task di Core-0 dan Core-1 menggunakan FreeRTOS
4. Amati:
Output device
Log pada Serial Monitor
5. Dokumentasikan:
Foto rangkaian / wiring
Kode tiap percobaan
Video demo
6. Upload seluruh percobaan ke GitHub

Tools
| Komponen  | Detail              |
| --------- | ------------------- |
| Board     | ESP32-S3            |
| IDE       | Wokwi               |
| Framework | FreeRTOS            |
| Bahasa    | C / C++             |

Simulasi Wokwi : https://wokwi.com/projects/447222444492476417

