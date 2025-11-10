Dual Core Servo

📌 Deskripsi
Percobaan ini menunjukkan bagaimana ESP32-S3 menjalankan dua task servo secara paralel pada dua core berbeda menggunakan FreeRTOS.
| Core   | Task         | Fungsi                                   |
| Core 0 | TaskServoCW  | Menggerakkan servo searah jarum jam (CW) |
| Core 1 | TaskServoCCW | Menggerakkan servo berlawanan (CCW)      |

🛠️ Hardware Setup
| Komponen | Pin      | Mode   |
| Servo    | GPIO 15  | Output |
| Power    | 5V + GND | —      |

📎 Koneksi Servo
Merah → 5V
Coklat/Hitam → GND
Kuning/Putih → GPIO 15

🧠 Cara Kerja
Core 0 mengirim sinyal posisi servo bertahap 0° → 180°
Core 1 mengirim sinyal posisi servo bertahap 180° → 0°
Karena keduanya memakai servo yang sama, terjadi interleaving/freeRTOS scheduling

▶️ Langkah Percobaan
| No | Langkah               | Hasil yang Diharapkan                 |
| 1  | Upload program        | Serial menampilkan pesan task         |
| 2  | Lihat servo           | Servo bergerak bolak-balik            |
| 3  | Perhatikan pergerakan | Gerakan tidak linear → efek dual core |
| 4  | Cek Serial Monitor    | Log posisi servo dari kedua core      |

🎥 Video Demo
Gdrive: https://drive.google.com/drive/folders/1xxA0_UCxWb_t9nFO6QF-OKTMf1O4tiRF?usp=sharing 