/*
    chương trình đọc giá trị của biến trở
    chuyển đổi giá trị đọc được thành tần số và duty cycle
    hiển thị tần số và duty cycle lên LCD
*/

/*
    KẾT NỐI CHÂN TÍN HIỆU DC MOTOR DRIVER BTN8982
    --> chân 5V nối nguồn +5VDC
    --> chân GND nối 0VDC
    --> chân EN_1 set 1 (nối +5VDC)
    --> chân EN_2 set 0 (nối GND)
    --> chân PWM1 nối pin9
    --> chân PWM2 nối GND
*/

/*
    KẾT NỐI CHÂN CẤP NGUỒN, ĐỘNG CƠ
    --> chân Vin nối nguồn 8~18VDC
    --> chân GND nối 0VDC
    --> chân OUT1, OUT2 nối động cơ
*/

#include <TimerOne.h>
#include <LCD-I2C.h>
#include <Wire.h>

// Định nghĩa chân kết nối biến trở và chân PWM
const int potPin1 = A1;  // Biến trở nối với chân A1 điều chỉnh tần sốsố
const int potPin2 = A2;  // Biến trở nối với chân A2 điều chỉnh duty cycle
const int pwmPin = 9;    // Chân số 9 để xuất tín hiệu PWM

int frequencyNew = 0, frequencyOld = 0; 
int dutyCycle = 0, DO = 0;

LCD_I2C lcd(0x27, 16, 2);

void setup() {
  // Khởi tạo kết nối nối tiếp để gửi dữ liệu tới máy tính
  Serial.begin(9600);
  
  // Khởi tạo chân PWM là đầu ra
  pinMode(pwmPin, OUTPUT);
  
  // Khởi tạo Timer1 với tần số 1000Hz
  Timer1.initialize(1000);
      /*
        Giá trị 1000 là thời gian chu kỳ
        Ví dụ: khi muốn PWM có tần số 1000Hz thì giá trị đặt vào init là 1000000/1000 = 1000
      */
  // Thiết lập chân PWM với giá trị duty cycle ban đầu là 50%
  Timer1.pwm(pwmPin, 512); 
      /*
        Giá trị duty cycle (0-100%) ứng với 0-1023
      */ 

  // Khởi tạo LCD-I2C
  Wire.begin();
  lcd.begin(&Wire);
  lcd.display();
  lcd.backlight();
  
}

void loop() {
  // Đọc giá trị từ biến trở
  int potValue1 = analogRead(potPin1);
  int potValue2 = analogRead(potPin2);
  
  // Chuyển đổi giá trị đọc được thành tần số và duty cycle
  frequencyNew = map(potValue1, 0, 680, 450, 33000); 
  dutyCycle = map(potValue2, 0, 680, 0, 1023);
  
  // Cập nhật tần số và duty cycle
  Timer1.setPeriod(1000000/frequencyNew);
  Timer1.pwm(pwmPin, dutyCycle);

  // In giá trị tần số và duty cycle ra LCD
  if(dutyCycle != DO || frequencyNew != frequencyOld){
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("fre (Hz): ");
    lcd.print(frequencyNew);
    lcd.setCursor(0, 1); 
    lcd.print("D (%): ");
    lcd.print(int(dutyCycle/1023.0 *100));
    DO = dutyCycle;
    frequencyOld = frequencyNew;
  }
  
  delay(100);
}
