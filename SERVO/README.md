📌 Deskripsi

Percobaan ini menunjukkan bagaimana ESP32-S3 menjalankan dua proses secara paralel menggunakan dual-core FreeRTOS.

Core 0: Membaca input tombol (push button) dan debounce

Core 1: Mengontrol LED berdasarkan status tombol

Ketika tombol ditekan, LED akan toggle ON/OFF menggunakan mekanisme flag antar-task.