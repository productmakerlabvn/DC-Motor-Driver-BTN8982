# Mạch điều khiển động cơ DC Motor Driver BTN8982

![](/image/BTN8982_front.jpg)

## Giới thiệu

Mạch điều khiển động cơ DC Motor Driver BTN8982 có khả năng điều khiển động cơ ở tần số cao (ổn định ở mức 30kHz). Driver có thể điều khiển được một động cơ DC 2 chiều có chổi than hoặc hai động cơ DC 1 chiều. Mạch tích hợp MOSFET P chống cấp ngược nguồn và IC chuyển mức tín hiệu (3.3/5VDC) 74HC244 giúp kết nối an toàn với vi điều khiển khi sử dụng. 

> **Cảnh báo:**  

## Thông số kỹ thuật

- Nguồn cấp: 8~18VDC (tối đa 40VDC).
- Dòng điện tải mạch: dòng điện động cơ trung bình 30A .
- Tín hiệu logic điều khiển: 3.3~5VDC.
- Tần số điều khiển: hoạt động ổn định ở tần số 30kHz, tần số thấp hơn có thể làm giảm hiệu năng.
- Tự động shut down khi điện áp thấp: Nếu điện áp < 5.5VDC, driver sẽ tự ngắt điện và sẽ mở lại sau khi điện áp > 5.5VDC.
- Bảo vệ quá nhiệt: BTN8982 bảo vệ chống quá nhiệt bằng cảm biến tích hợp bên trong. Đầu ra sẽ bị ngắt khi có hiện tượng quá nhiệt.
- Chống cấp ngược nguồn: tích hợp MOSFET P giúp bảo vệ mạch khi cấp ngược nguồn ở chân Vin.
- Kích thước: 89 x 61 x 27mm.

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
    <td>chân cho phép PWM1</td>
  </tr>
  <tr>
    <td>EN_2</td>
    <td>chân cho phép PWM2</td>
  </tr>
  <tr>
    <td>PWM1</td>
    <td>cấp xung PWM</td>
  </tr>
  <tr>
    <td>PWM2</td>
    <td>cấp xung PWM</td>
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
    <td>Ngõ ra điều khiển động cơ</td>
  </tr>
  <tr>
    <td>OUT2</td>
    <td>Ngõ ra điều khiển động cơ</td>
  </tr>
</tbody>
</table>

## Hướng dẫn sử dụng với STM32F103RCT6STM32F103RCT6

### Các thiết bị sử dụng trong bài hướng dẫn


## Hỗ trợ và liên hệ

- Website: [https://www.makerlab.vn/](https://www.makerlab.vn/)
- Facebook: [https://www.facebook.com/makerlabvn](https://www.facebook.com/makerlabvn)

## Nhà phân phối

- Các bạn có thể mua sản phẩm của MakerLab tại các [Nhà Phân Phối.](https://www.makerlab.vn/distributor/)
