#include <TimerOne.h>
#include <LCD-I2C.h>
#include <Wire.h>

// Định nghĩa chân kết nối biến trở và chân PWM
const int potPin1 = A1;  // Biến trở thứ nhất kết nối với chân A1
const int potPin2 = A2;  // Biến trở thứ hai kết nối với chân A2
const int pwmPin = 9;    // Chân số 9 để xuất tín hiệu PWM

/*  chân EN_1, EN_2 nối với nguồn 3.3V
    chân PWM2 nối GND
*/

int frequencyNew = 0, frequencyOld = 0; 
int dutyCycle = 0, DO = 0;

LCD_I2C lcd(0x27, 16, 2);

void setup() {
  // Khởi tạo kết nối nối tiếp để gửi dữ liệu tới máy tính
  Serial.begin(9600);
  
  // Khởi tạo chân PWM là đầu ra
  pinMode(pwmPin, OUTPUT);
  
  // Khởi tạo Timer1
  Timer1.initialize(1000);  // Thiết lập thời gian chu kỳ là 1000 microseconds (tương đương với 1kHz)
  Timer1.pwm(pwmPin, 512);  // Thiết lập chân PWM với giá trị duty cycle ban đầu là 50%

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
  Serial.println(potValue1);
  Serial.println(potValue2);
  Serial.println("-----");
  
  // Chuyển đổi giá trị đọc được thành tần số và duty cycle
  frequencyNew = map(potValue1, 0, 680, 450, 33000); 
  dutyCycle = map(potValue2, 0, 680, 0, 1023);
  
  // Cập nhật tần số và duty cycle
  Timer1.setPeriod(1000000/frequencyNew);  // Thiết lập chu kỳ PWM
  Timer1.pwm(pwmPin, dutyCycle);          // Cập nhật duty cycle

  // In giá trị đọc được và các giá trị chuyển đổi ra màn hình nối tiếp
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
  
  
  // Đợi một chút trước khi đọc lần tiếp theo
  delay(100);
}
