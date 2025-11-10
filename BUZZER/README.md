Dual Core Buzzer

📌 Deskripsi
Percobaan ini mendemonstrasikan penggunaan dua core ESP32-S3 untuk menghasilkan pola bunyi buzzer berbeda secara paralel:
| Core   | Tugas        | Frekuensi | Pola               |
| Core 0 | Bunyi lambat | 800 Hz    | 0.5s ON / 0.5s OFF |
| Core 1 | Bunyi cepat  | 1200 Hz   | 0.2s ON / 0.2s OFF |

🛠️ Hardware Setup
| Komponen      | Pin     | Mode   |
| Active Buzzer | GPIO 13 | Output |

▶️ Langkah Percobaan
| No | Step                  | Expected Result                         |
| 1  | Upload program        | Serial Monitor aktif                    |
| 2  | Dengarkan buzzer      | Buzzer bunyi cepat + lambat bergantian  |
| 3  | Perhatikan log Core 0 | Output 800 Hz setiap 0.5 detik          |
| 4  | Perhatikan log Core 1 | Output 1200 Hz setiap 0.2 detik         |
| 5  | Validasi multicore    | Log menunjukkan **Core 0** & **Core 1** |

🎥 Video Demo
Gdrive: https://drive.google.com/drive/folders/1K_wdP9ttsc-NksF2BDL43nwUQEU0aomJ?usp=sharing