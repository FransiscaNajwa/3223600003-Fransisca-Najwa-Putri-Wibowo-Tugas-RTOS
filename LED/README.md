Dual Core 3 LED
📘 Deskripsi
Percobaan ini menunjukkan penggunaan dua core ESP32-S3 untuk menjalankan task secara paralel menggunakan FreeRTOS.

Program ini memiliki 2 task:
| Task        | Core   | LED                           | Keterangan             |
| Task Core 0 | Core 0 | LED2 (GPIO 5)                 | Blink cepat (±300 ms)  |
| Task Core 1 | Core 1 | LED1 (GPIO 4) & LED3 (GPIO 6) | Bergantian tiap 500 ms |

🔌 Mapping Hardware 
| Perangkat | Pin ESP32-S3 | Mode   | Keterangan     |
| LED1      | GPIO 4       | Output | Kendali Core 1 |
| LED2      | GPIO 5       | Output | Kendali Core 0 |
| LED3      | GPIO 6       | Output | Kendali Core 1 |

🧪 Langkah Percobaan
| No | Langkah                        | Hasil Diharapkan                                  |
| 1  | Upload program ke ESP32-S3     | Serial menampilkan log FreeRTOS                   |
| 2  | Amati LED2 (GPIO 5)            | LED2 berkedip cepat (±300ms) → Core 0             |
| 3  | Amati LED1 & LED3 (GPIO 4 & 6) | LED1 & LED3 bergantian ON/OFF tiap 500ms → Core 1 |
| 4  | Buka Serial Monitor            | Terlihat teks `[Core 0]` dan `[Core 1]`           |

🎥 Video Demo
Gdrive: https://drive.google.com/drive/folders/1zJugp3nYugUQ3zeaDMXNZDKSGXHxg3_M?usp=sharing