Dual Core PushButton

📌 Deskripsi
Percobaan ini menunjukkan bagaimana ESP32-S3 menangani input dan output secara paralel menggunakan dua core:
| Core   | Tugas      | Fungsi                                      |
| Core 0 | TaskButton | Membaca tombol input & debounce             |
| Core 1 | TaskLED    | Mengontrol LED berdasarkan flag dari core 0 |

🛠️ Hardware Setup
| Komponen | Pin    | Mode            |
| Button   | GPIO 15| Input (pull-up) |
| LED      | GPIO 5 | Output          |

▶️ Langkah Percobaan
| No | Langkah              | Hasil                                |
| 1  | Upload program       | Serial “task started” muncul         |
| 2  | Tekan tombol         | Core 0 mendeteksi tombol             |
| 3  | Lihat LED            | LED toggle ON/OFF setiap tekan       |
| 4  | Lihat Serial Monitor | Log LED & button dari 2 core berbeda |

🎥 Video Demo
Gdrive: https://drive.google.com/drive/folders/1l86TyPkNUZNA6bz5GUtfGsD7UbBDtODY?usp=sharing 