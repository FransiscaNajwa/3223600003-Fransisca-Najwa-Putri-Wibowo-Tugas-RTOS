Dual Core PushButton

📌 Deskripsi  
Percobaan ini menunjukkan bagaimana ESP32-S3 menangani input dan output secara paralel menggunakan dua core:
| Core   | Task            | Fungsi                        |
| ------ | --------------- | ----------------------------- |
| Core 0 | TaskButtonCore0 | Membaca tombol 1 + toggle LED |
| Core 1 | TaskButtonCore1 | Membaca tombol 2 + toggle LED |

🛠️ Hardware Setup
| Komponen      | Pin ESP32-S3 | Mode            |
| ------------- | ------------ | --------------- |
| Push Button 1 | GPIO 15      | Input (Pull-up) |
| Push Button 2 | GPIO 12      | Input (Pull-up) |
| LED           | GPIO 5       | Output          |

▶️ Langkah Percobaan
| No | Langkah                    | Hasil yang Diharapkan                         |
| -: | -------------------------- | --------------------------------------------- |
|  1 | Upload program ke ESP32-S3 | Serial menampilkan “task started”             |
|  2 | Tekan tombol 1             | Core 0 mendeteksi input & toggle LED          |
|  3 | Tekan tombol 2             | Core 1 mendeteksi input & toggle LED          |
|  4 | Amati LED                  | LED menyala/mati sesuai tombol yang ditekan   |
|  5 | Cek Serial Monitor         | Log menampilkan core mana yang menyalakan LED |

🎥 Video Demo
![Demo PUSHBUTTON](pushbutton-2.gif)

Core 0
![alt text](image-1.png)  

Core 1  
![alt text](image-2.png)   