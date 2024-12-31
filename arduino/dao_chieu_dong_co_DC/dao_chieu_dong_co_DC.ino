/*
  chương trình phát xung PWM cho DC Driver Motor BTN8982
  điều khiển 1 động cơ quay thuận - nghịch với tần số (FREQUENCY) được định nghĩa trước.
  tốc độ động cơ được điều khiển bằng cách thay đổi giá trị duty cycle
*/

/*
  KẾT NỐI CHÂN TÍN HIỆU
    --> chân 5V nối nguồn +5VDC
    --> chân GND nối 0VDC
    --> chân EN_1, EN_2 kích mức 1 (nối )
    --> chân PWM1 nối pin9 của Vietduino Uno
    --> chân PWM2 nối pin10 của Vietduino Uno
*/

/*
  KẾT NỐI CHÂN CẤP NGUỒN, ĐỘNG CƠ
    --> chân Vin nối nguồn 8~18VDC
    --> chân GND nối 0VDC
    --> chân OUT1, OUT2 nối động cơ
*/

#include <TimerOne.h>
#define FREQUENCY 18000   // định nghĩa tần số của xung PWM (Hz)

// định nghĩa chân PWM
const int pwm1Pin = 9;    
const int pwm2Pin = 10;   

void setup() {
  // khởi tạo Serial
  Serial.begin(9600);

  // Khởi tạo Timer1
  Timer1.initialize(1000000/FREQUENCY);
      /*
        Giá trị 1000000/FREQUENCY là thời gian chu kỳ
        Ví dụ: khi muốn PWM có tần số 1000Hz thì giá trị đặt vào init là 1000000/1000 = 1000
      */

  // Khởi tạo chân PWM là đầu ra
  pinMode(pwm1Pin, OUTPUT);
  pinMode(pwm2Pin, OUTPUT);
  // Ban đầu đặt duty cycle cho 2 xung PWM = 0
  Timer1.pwm(pwm1Pin, 0);
  Timer1.pwm(pwm2Pin, 0);
      /*
        Giá trị duty cycle (0-100%) ứng với 0-1023
      */

  delay(500);
}

void loop() {
  // quay theo chiều kim đồng hồ
  Serial.println("quay theo chieu kim dong ho");
  run(pwm1Pin);
  stop();

  // quay nguoc chieu kim dong ho
  Serial.println("quay nguoc chieu kim dong ho");
  run(pwm2Pin);
  stop();

}

void run(int pwmPin){
  for(int i = 0; i<1024; i++){
    Timer1.pwm(pwmPin, i);
    if(i == 1023)
      delay(1000);
    else
    delay(10);
  }
  for(int j = 1023; j >= 0;j--){
    Timer1.pwm(pwmPin, j);
  delay(10);
  }
}
void stop(){
  Timer1.pwm(pwm1Pin, 0);
  Timer1.pwm(pwm2Pin, 0);
  delay(500);
}
