Dual Core Potentiometer

📌 Deskripsi
Percobaan ini menunjukkan bagaimana ESP32-S3 menjalankan dua task secara paralel pada dua core berbeda menggunakan FreeRTOS:
Core 0: Membaca nilai potensiometer
Core 1: Menampilkan status sistem setiap 3 detik

🧠 Fitur Sistem
| Core   | Task      | Fungsi                                |
| Core 0 | Core0Task | Membaca potensiometer secara realtime |
| Core 1 | Core1Task | Mencetak status sistem periodik       |

🛠️ Hardware Setup
| Komponen      | Pin    | Mode                   |
| Potensiometer | GPIO 4 | Analog Input           |
| ESP32-S3 USB  | —      | Power & Serial Monitor |

▶️ Langkah Percobaan
| No | Langkah               | Hasil yang Diharapkan                                      |
| 1  | Upload program        | Serial Monitor aktif                                       |
| 2  | Putar potensiometer   | Nilai analog berubah                                       |
| 3  | Perhatikan log Core 0 | Tampil nilai potensiometer tiap 200 ms                     |
| 4  | Perhatikan log Core 1 | Pesan *System Running Smoothly* tiap 3 detik               |
| 5  | Validasi dual-core    | Log menunjukkan **Core 0** dan **Core 1** berjalan paralel |

🎥 Video Demo
Gdrive: https://drive.google.com/drive/folders/1-IQlojRIvyesS60SiTbj_doWpA2G7N0t?usp=sharing