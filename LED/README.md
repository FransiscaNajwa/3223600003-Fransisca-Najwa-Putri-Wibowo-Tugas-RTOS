Dual Core 3 LED FreeRTOS (ESP32-S3)
📘 Deskripsi
Percobaan ini menunjukkan penggunaan dua core ESP32-S3 untuk menjalankan task secara paralel menggunakan FreeRTOS.
Program ini memiliki 2 task:
| Task        | Core   | LED                           | Perilaku               |
| ----------- | ------ | ----------------------------- | ---------------------- |
| Task Core 0 | Core 0 | LED2 (GPIO 5)                 | Blink cepat (±300 ms)  |
| Task Core 1 | Core 1 | LED1 (GPIO 4) & LED3 (GPIO 6) | Bergantian tiap 500 ms |
🔌 Mapping Hardware 
| Perangkat | Pin ESP32-S3 | Mode   | Keterangan     |
| --------- | ------------ | ------ | -------------- |
| LED1      | GPIO 4       | Output | Kendali Core 1 |
| LED2      | GPIO 5       | Output | Kendali Core 0 |
| LED3      | GPIO 6       | Output | Kendali Core 1 |
🧪 Langkah Percobaan
| No | Langkah                        | Hasil Diharapkan                                  |
| -- | ------------------------------ | ------------------------------------------------- |
| 1  | Upload program ke ESP32-S3     | Serial menampilkan log FreeRTOS                   |
| 2  | Amati LED2 (GPIO 5)            | LED2 berkedip cepat (±300ms) → Core 0             |
| 3  | Amati LED1 & LED3 (GPIO 4 & 6) | LED1 & LED3 bergantian ON/OFF tiap 500ms → Core 1 |
| 4  | Buka Serial Monitor            | Terlihat teks `[Core 0]` dan `[Core 1]`           |
📂Dokumentasi 
1️⃣ LED2 menyala (Core 0)
LED2 berkedip cepat
Serial muncul:
[Core 0] LED2 ON
[Core 0] LED2 OFF
2️⃣ LED1 / LED3 bergantian (Core 1)
[Core 1] LED1 ON | LED3 OFF
[Core 1] LED1 OFF | LED3 ON

