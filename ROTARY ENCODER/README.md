Dual-Core Rotary Encoder

📌 Deskripsi
Percobaan ini menggunakan ESP32-S3 dual-core untuk membaca rotary encoder dan push button secara paralel menggunakan FreeRTOS.
| Core   | Task        | Fungsi                               |
| Core 0 | TaskEncoder | Membaca rotary encoder (CLK + DT)    |
| Core 1 | TaskButton  | Membaca tombol push (tombol encoder) |

🛠️ Hardware Setup
| Komponen         | Pin ESP32-S3 | Mode          |
| Rotary CLK       | GPIO 15      | Input Pull-Up |
| Rotary DT        | GPIO 16      | Input Pull-Up |
| Rotary SW (push) | GPIO 17      | Input Pull-Up |
| Power            | 3.3V & GND   | —             |

📎 Koneksi Encoder
| Encoder Pin | Arduino Label | ESP32-S3 Pin |
| CLK         | A             | GPIO 15      |
| DT          | B             | GPIO 16      |
| SW          | Button        | GPIO 17      |
| +           | VCC           | 3.3V         |
| GND         | Ground        | GND          |

🧠 Cara Kerja Sistem
Core 0 membaca sinyal CLK + DT
Putar CW → nilai bertambah
Putar CCW → nilai berkurang
Core 1 membaca tombol
Tekan → nilai bertambah (manual increment)
Setiap perubahan nilai encoder ditampilkan di Serial Monitor.

▶️ Langkah Percobaan
| No | Langkah              | Hasil yang Diharapkan                       |
| 1  | Upload program       | Serial menampilkan task start               |
| 2  | Putar encoder CW/CCW | Nilai encoder naik/turun                    |
| 3  | Tekan tombol         | Nilai encoder bertambah                     |
| 4  | Lihat serial monitor | Data dibaca dari kedua core secara realtime |

🎥 Video Demo
Gdrive: https://drive.google.com/drive/folders/1xHsLUh8lWJG1qjUEWygBUBDPuTShIQ0_?usp=sharing
