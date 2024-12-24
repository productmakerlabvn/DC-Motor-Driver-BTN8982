# Mạch điều khiển động cơ MKE-M10 I2C motor control module

![](/image/BTN8982_front.jpg)

## Giới thiệu

DC Motor Driver BTN8982 có khả năng điều khiển một động cơ DC chổi than 2 chiều hoặc hai động cơ DC 1 chiều. Shield có thể được điều khiển bằng các cổng IO logic của vi điều khiển. Bạn có thể sử dụng Arduino Uno R3 hoặc XMC1100 Boot Kit từ Infineon làm bộ điều khiển chính.

Trên Shield có hai BTN8982TA NovalithICTM, mỗi cái bao gồm một MOSFET P-Channel và một MOSTFET N-Chanel với IC điều khiển tích hợp. BTN8982TA half-bridge dễ dàng điều khiển bằng các tín hiệu logic, và có thể điều chỉnh dòng điện đến động cơ qua PWM. Shield có thể dễ dàng kết nối với bất kỳ board Arduino nào hoặc XMC1100 Boot Kit thông qua các đầu kết nối.

> **Cảnh báo:**  
<!-- Nếu sử dụng động cơ RC Servo 5VDC công suất lớn có thể gây sụt áp, quá tải, chạy không ổn định, Quý Khách cần mua thêm Mạch cấp nguồn bổ sung MKE-M12 5VDC 5A power supply module với khả năng cấp nguồn 5VDC với dòng điện cung cấp tối đa lên đến 5A cho cổng POWER+. -->

## Thông số kỹ thuật

- Một Vietduino Uno, Arduino Uno R3, XMC1100 Boot Kit hoặc các Board tương tự được kết nối với shield có thể điều khiển hai half-bridges thông qua các chân IO.
- Điều khiển động cơ DC chổi than lên tới 250W continuous load
  + Điện áp đầu vào danh định 8 - 18V (tối đa 6 - 40V) cấp qua cổng Vin.
  + Dòng điện trung bình của động cơ 30A, bị hạn chế do sự phân tán công suất của PCB (giới hạn dòng điện BTN8982TA @ 55 A min).
- Điều khiển một động cơ DC chổi than hai chiều hoặc hai động cơ DC một chiều.
- Có khả năng điều khiển PWM tần số cao 20-30 kHz
- Tốc độ quay có thể điều chỉnh để tối ưu hóa EMI bằng cách thay đổi điện trở ngoài.
- Mạch điều khiển với các đầu vào mức logic.
- Chuẩn đoán flag diagnosis với khả năng cảm biến dòng điện.
- Chống quá nhiệt, quá dòng.
- Bảo vệ phân cực ngược với IPD90P04P4L.

## Kích thước

<!-- ![](/image/MKE_M10_2.jpg) -->

## Các chân tín hiệu

![](/image/BTN8982_backside.jpg)
<table><thead>
  <tr>
    <th>DC Motor Driver BTN8982/ Chân tín hiệu</th>
    <th>Ghi chú</th>
  </tr></thead>
<tbody>
  <tr>
    <td>GND</td>
    <td>Chân cấp nguồn âm 0VDC</td>
  </tr>
  <tr>
    <td>5V</td>
    <td>Chân cấp nguồn 5VDC</td>
  </tr>
  <tr>
    <td>IS_1</td>
    <td>Current Sense và Diagnostics của half-bridge 1</td>
  </tr>
  <tr>
    <td>IS_2</td>
    <td>Current Sense và Diagnostics của half-bridge 2</td>
  </tr>
  <tr>
    <td>EN_1</td>
    <td></td>
  </tr>
  <tr>
    <td>EN_2</td>
    <td></td>
  </tr>
  <tr>
    <td>PWM1</td>
    <td></td>
  </tr>
  <tr>
    <td>PWM2</td>
    <td></td>
  </tr>
</tbody>
</table>

<table><thead>
  <tr>
    <th>DC Motor Driver BTN8982/ Cổng cấp nguồn</th>
    <th>Ghi chú</th>
  </tr></thead>
<tbody>
  <tr>
    <td>GND</td>
    <td>Chân cấp nguồn âm 0VDC</td>
  </tr>
  <tr>
    <td>Vin</td>
    <td>Chân cấp nguồn 8~18VDC cho động cơ hoạt động<br>(tối đa 40VDC)</td>
  </tr>
  <tr>
    <td>OUT1</td>
    <td></td>
  </tr>
  <tr>
    <td>OUT2</td>
    <td></td>
  </tr>
</tbody>
</table>

## Hướng dẫn sử dụng

### Các thiết bị sử dụng trong bài hướng dẫn

#### Arduino

<!-- - [Mạch Vietduino Uno (Arduino Uno Compatible)](https://www.makerlab.vn/vuno)
- [Mạch MakerEdu Shield for Vietduino](https://www.makerlab.vn/vietduinosd)
- [Mạch màn hình MKE-M07 LCD1602 I2C Display Module](https://www.makerlab.vn/mkem07)
- [Động cơ RC Servo 9G](https://hshop.vn/dong-co-rc-servo-9g) -->

#### mBlock

<!-- - [Mạch MakerEdu Creator (Arduino Uno Compatible)](https://www.makerlab.vn/creator)
- [Mạch màn hình MKE-M07 LCD1602 I2C Display Module](https://www.makerlab.vn/mkem07)
- [Động cơ RC Servo 9G](https://hshop.vn/dong-co-rc-servo-9g) -->

#### Micro:bit:

<!-- - [Mạch Micro:bit V2](https://hshop.vn/products/kit-hoc-lap-trinh-stem-cho-tre-em-micro-bit-v2) hoặc các phiên bản tương thích.
- [Mạch MakerEdu Shield for Micro:bit](https://www.makerlab.vn/microbitsd)
- [Mạch màn hình MKE-M07 LCD1602 I2C Display Module](https://www.makerlab.vn/mkem07)
- [Động cơ RC Servo 9G](https://hshop.vn/dong-co-rc-servo-9g) -->

### Hướng dẫn sử dụng với Arduino (Code C)

<!-- [Hướng dẫn cài đặt phần mềm, nạp chương trình, cài đặt bộ thư viện Arduino cơ bản.](https://github.com/makerlabvn/Arduino-Vietduino)

- Tải và cài đặt [phần mềm Arduino tại đây.](https://www.arduino.cc/en/software)
- Trong Tools / Library Manager, tìm và cài đặt bộ thư viện tổng hợp "MAKERLABVN" by MakerLab.vn
- Mở chương trình mẫu "MKE_M10_I2C_Motor_LCD_Serial.ino" tại File / Examples / MAKERLABVN / Module / MKE_M10_I2C_Motor_LCD_Serial hoặc [tải chương trình mẫu tại đây](/arduino)
- Chọn board là Arduino Uno (mạch Vietduino Uno tương thích với Arduino Uno), chọn đúng cổng COM Port của mạch và tiến hành nạp chương trình.
- Kết nối mạch Vietduino Uno với MakerEdu Shield, kết nối module MKE-M10 vào cổng [I2C] và màn hình LCD vào cổng [I2C] trên MakerEdu Shield, kết nối động cơ RC Servo vào module MKE-M10, cấp nguồn qua cổng USB của Vietduino Uno để thấy chương trình hoạt động. -->

### Hướng dẫn lập trình với mBlock (kéo thả khối)

<!-- [Hướng dẫn cài đặt phần mềm, nạp chương trình, cài đặt Extension mBlock cơ bản.](https://github.com/makerlabvn/mBlock-MakerEdu-Creator)

- Tải và cài đặt phần mềm mBlock 5 ([Windows](https://www.mediafire.com/file/ma55iajd7glwmbo/%255BMakerLab.vn%255D_mBlock_V5.4.3_for_Windows.zip/file) / [Mac Intel](https://www.mediafire.com/file/pjfngy6d7ktb55f/%255BMakerLab.vn%255D_mBlock_V5.4.3_for_Mac_Intel.zip/file) / [Mac M1M2](https://www.mediafire.com/file/mfdkgpgnpa7uv2s/%255BMakerLab.vn%255D_mBlock_V5.4.3_for_Mac_M1M2.zip/file))
- Thêm Device "MakerEdu Creator" by MakerEduVN
- Thêm Extension "Upload Mode Broadcast" by mBlock Official
- Thêm Extension "MakerEdu Hardware" by MakerEduVN
- Mở [chương trình mẫu tại đây](/mBlock5), kết nối MakerEdu Creator với máy tính và nạp chương trình.
- kết nối module MKE-M10 vào cổng [I2C] và màn hình LCD vào cổng [I2C] trên MakerEdu Creator, kết nối động cơ RC Servo vào module MKE-M10, cấp nguồn qua cổng USB của MakerEdu Creator để thấy chương trình hoạt động. -->

### Hướng dẫn lập trình với Micro:bit (kéo thả khối)

<!-- [Hướng dẫn nạp chương trình, cài đặt Extension Micro:bit cơ bản.](https://github.com/makerlabvn/MakeCode-microbit)

- Khởi động phần mềm MakeCode tại: [https://makecode.microbit.org/](https://makecode.microbit.org/)
- Chọn My Projects / Import / Import URL theo đường link của chương trình mẫu: [https://github.com/devmakerlabvn/makecode-mke-s01-ultrasonic-distance-sensor](https://github.com/devmakerlabvn/makecode-mke-s01-ultrasonic-distance-sensor)
- Kết nối Micro:bit với máy tính và nạp chương trình.
- Kết nối mạch Micro:bit với MakerEdu Shield, và màn hình LCD vào cổng [I2C] trên MakerEdu Shield, **cấp nguồn qua cổng USB của MakerEdu Shield** để thấy chương trình hoạt động. -->

## Hỗ trợ và liên hệ

- Website: [https://www.makerlab.vn/](https://www.makerlab.vn/)
- Facebook: [https://www.facebook.com/makerlabvn](https://www.facebook.com/makerlabvn)

## Nhà phân phối

- Các bạn có thể mua sản phẩm của MakerLab tại các [Nhà Phân Phối.](https://www.makerlab.vn/distributor/)
