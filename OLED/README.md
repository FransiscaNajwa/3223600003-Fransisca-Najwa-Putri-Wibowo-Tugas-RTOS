Dual Core OLED Display

📌 Deskripsi
Percobaan ini menunjukkan bagaimana ESP32-S3 menjalankan dua task pada dua core untuk menampilkan teks bergantian di layar OLED dengan sinkronisasi Mutex agar tidak terjadi konflik akses I2C.
| Core   |  Task | Fungsi                             |
| ------ | ----: | ---------------------------------- |
| Core 0 | Task0 | Menampilkan teks `"CORE 0: aktif"` |
| Core 1 | Task1 | Menampilkan teks `"CORE 1: aktif"` |

OLED digunakan sebagai output yang diakses bergantian oleh kedua task melalui xSemaphore (mutex).

🛠️ Hardware Setup
| Komponen | Pin ESP32-S3 | Fungsi    |
| -------- | -----------: | --------- |
| OLED SDA |      GPIO 17 | Data I2C  |
| OLED SCL |      GPIO 18 | Clock I2C |
| OLED VCC |         3.3V | Power     |
| OLED GND |          GND | Ground    |

📎 Wiring Diagram (I2C)
| OLED Pin | ESP32-S3 |
| -------- | -------- |
| SDA      | GPIO 17  |
| SCL      | GPIO 18  |
| VCC      | 3.3V     |
| GND      | GND      |

🧠 Cara Kerja
Core 0 dan Core 1 mencoba menulis ke OLED
Hanya task yang berhasil mengambil mutex yang boleh menulis
Menghindari crash / overlap pada display I2C
Task menampilkan teks secara bergantian (2s vs 3s interval)

▶️ Langkah Percobaan
| No | Langkah                  | Hasil yang Diharapkan                      |
| -: | ------------------------ | ------------------------------------------ |
|  1 | Upload program           | OLED menampilkan `"OLED Ready!"`           |
|  2 | Biarkan program berjalan | OLED menampilkan teks dari Core bergantian |
|  3 | Buka Serial Monitor      | Tampil log task & core berjalan            |
|  4 | Amati interval tampilan  | Core0 → 2s, Core1 → 3s                     |

🎥 Video Demo
Gdrive: https://drive.google.com/drive/folders/1jcI5MgsBtEnXx9m1d-IOBRYAX6cneeiD?usp=sharing 

Core 0
![alt text](image.png)
Core 1
![alt text](image-1.png)