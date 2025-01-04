# Mạch điều khiển động cơ DC Motor Driver BTN8982

![](/image/BTN8982_c.jpg) ![](/image/BTN8982_b.jpg)

## Giới thiệu

Mạch điều khiển động cơ DC Motor Driver BTN8982 có khả năng điều khiển động cơ ở tần số cao (ổn định ở mức 30kHz). Driver có thể điều khiển được một động cơ DC đảo chiều (thuận, nghịch) có chổi than hoặc hai động cơ DC 1 chiều. Mạch tích hợp IC chuyển mức tín hiệu (3.3/5VDC) 74HC244 giúp kết nối an toàn với vi điều khiển khi sử dụng. 

- Tích hợp MOSFET bảo vệ chống cấp ngược nguồn.
- Tích hợp IC buffer điều khiển dòng và bảo vệ các tín hiệu đầu vào/đầu ra. IC này có thể hoạt động như một bộ đệm 8 bit, giúp tăng cường tín hiệu và bảo vệ các vi điều khiển khỏi các tín hiệu nhiễu.
- IC BTN8982 chính hãng được thiết kế để điều khiển động cơ DC với dòng điện cao, cung cấp các chức năng bảo vệ như chống quá nhiệt, chống quá dòng và chống ngắn mạch.
- Mạch đồng dày 2 Oz giúp tăng khả năng dẫn điện và tản nhiệt khi có dòng điện cao.

Vietduino Uno, Arduino Uno hay bất kì board tương đương có thể dễ dàng điều khiểu DC Motor Driver BTN8982.

## Thông số kỹ thuật

- Nguồn cấp: hoạt động ổn định tại 8~18VDC (tối đa 40VDC).
- Dòng điện tải mạch: 20A (tải cảm), 50A (tải trở).
- Tín hiệu logic điều khiển: 3.3~5VDC.
- Tần số điều khiển: hoạt động ổn định ở tần số 30kHz, tần số thấp hơn có thể làm giảm hiệu năng.
- Tự động shut down khi điện áp thấp ở chân Vin thấp.
- Kích thước: 88 x 60 x 27mm.

## Kích thước

![](/image/size.jpg)

## Các chân tín hiệu

![](/image/BTN8982_a.jpg)
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
    <td>EN_1 = 0: Disable OUT1; EN_1 = 1: Enable OUT1</td>
  </tr>
  <tr>
    <td>EN_2</td>
    <td>EN_2 = 0: Disable OUT2; EN_2 = 1: Enable OUT2</td>
  </tr>
  <tr>
    <td>PWM1</td>
    <td>Điều khiển đảo chiều và tốc độ động cơ</td>
  </tr>
  <tr>
    <td>PWM2</td>
    <td>Điều khiển đảo chiều và tốc độ động cơ</td>
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

## Hướng dẫn sử dụng với Vietduino Uno
  Sử dụng Vietduino Uno cấp xung PWM cho DC Motor Driver BTN8982 để điều khiển một động cơ DC 12V quay thuận - nghịch.

![](/image/circuit_1.png)

[tải chương trình mẫu tại đây](arduino/BTN8982_test)

## Hỗ trợ và liên hệ

- Website: [https://www.makerlab.vn/](https://www.makerlab.vn/)
- Facebook: [https://www.facebook.com/makerlabvn](https://www.facebook.com/makerlabvn)

## Nhà phân phối

- Các bạn có thể mua sản phẩm của MakerLab tại các [Nhà Phân Phối.](https://www.makerlab.vn/distributor/)
