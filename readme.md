# STM32F429I-DISCO – Flappy Bird Extended (TouchGFX)

## Giới thiệu

Dự án này là **game Flappy Bird mở rộng** được phát triển trên **board STM32F429I-DISCO (STM32F429I6)** bằng **STM32CubeIDE** và **TouchGFX**. Project được thực hiện bởi **nhóm 4 người**, với mục tiêu học tập và thực hành lập trình nhúng, đồ họa giao diện và xử lý logic game trên vi điều khiển STM32 trong môn Lập trình Hệ Nhúng.

---

## Công cụ & môi trường phát triển

* **Vi điều khiển**: STM32F429I6
* **Board**: STM32F429I-DISCO (REV D01)
* **IDE**: STM32CubeIDE
* **Middleware đồ họa**: TouchGFX
* **Công cụ nạp chương trình**: STM32CubeProgrammer
* 

---

## Tính năng chính

### 🎮 Gameplay

* Game **Flappy Bird mở rộng** chạy trực tiếp trên STM32
* Logic game được viết lại hoàn toàn (va chạm, tính điểm, trạng thái thắng/thua)

### 🕹️ Chế độ chơi

Hệ thống bàn chơi gồm **3 chế độ**:

1. **Easy** – tốc độ chậm, khoảng cách ống rộng, cột được sinh ngẫu nhiên và đứng im
2. **Hard** – tốc độ nhanh hơn, cột sinh ngẫu nhiên, di chuyển lên xuống theo hình sin
3. **Nightmare** – tốc độ cao, có "sương" bao phủ nửa màn hình, cột sinh mẫu nhiên di chuyển lên xuống, có thêm chức năng shield

### 🏆 Hệ thống xếp hạng

* Lưu và hiển thị **điểm số**
* Có **bảng xếp hạng** để so sánh kết quả giữa các lượt chơi

### 🔊 Âm thanh & tương tác phần cứng

* Sử dụng **nút nhấn trên board** để điều khiển game
* **Buzzer** phát âm thanh khi:

  * Nhấn nút
  * Chim bay / va chạm
  * Kết thúc game


## Cách build & nạp chương trình

1. Mở project bằng **STM32CubeIDE**
2. Build project
3. Kết nối board STM32F429I-DISCO qua USB
4. Flash bằng:

   * STM32CubeIDE **hoặc**
   * TouchGFX Designer + **STM32CubeProgrammer**

---

## Tác giả

Project được phát triển bởi **nhóm 4 sinh viên**, phục vụ mục đích học tập và nghiên cứu về:

* Lập trình nhúng STM32
* Thiết kế giao diện với TouchGFX
* Xây dựng game trên vi điều khiển

---
