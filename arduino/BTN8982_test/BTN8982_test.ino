/*
  chương trình phát xung PWM cho DC Driver Motor BTN8982
  điều khiển 1 động cơ quay thuận - nghịch với tần số (FREQUENCY) được định nghĩa trước.
  tốc độ động cơ được điều khiển bằng cách thay đổi giá trị duty cycle.
  (The PWM pulse generation program for the DC Driver Motor BTN8982
  controls one motor to rotate forward and backward with a predefined frequency (FREQUENCY). 
  The motor speed is controlled by changing the duty cycle value.)
*/

/*
  KẾT NỐI CHÂN TÍN HIỆU
  Signal Pin Connection
    --> chân 5V nối +5VDC
        The 5V pin connects to +5VDC
    --> chân GND nối 0VDC
        The GND pin connects to 0VDC
    --> chân EN_1, EN_2 kích mức 1 (nối +5VDC)
        The EN_1, EN_2 enable pins connect to +5VDC
    --> chân PWM1 nối pin9 của Vietduino Uno
        The PWM1 pin connects to pin9
    --> chân PWM2 nối pin10 của Vietduino Uno
        The PWM2 pin connects to pin10
*/

/*
  KẾT NỐI CHÂN CẤP NGUỒN, ĐỘNG CƠ
  Power Supply Pin Connection
    --> chân Vin nối nguồn 8~18VDC
        The Vin pin connects to 8~18VDC
    --> chân GND nối 0VDC
        The GND pin connects to 0VDC
    --> chân OUT1, OUT2 nối động cơ
        The OUT1, OUT2 pins connect to motors
*/

#include <TimerOne.h>
// định nghĩa tần số của xung PWM (Hz)
// define the frequency of the PWM pulse (Hz)
#define FREQUENCY 18000   

// định nghĩa chân PWM
// define the PWM pin
const int pwm1Pin = 9;    
const int pwm2Pin = 10;   

void setup() {
  // khởi tạo Serial
  // initialize the serial communications:
  Serial.begin(9600);

  // Khởi tạo Timer1
  // initialize Timer1
  Timer1.initialize(1000000/FREQUENCY);
      /*
        Giá trị 1000000/FREQUENCY là thời gian chu kỳ.
        Ví dụ: khi muốn PWM có tần số 1000Hz thì giá trị đặt vào init là 1000000/1000 = 1000
        The value 1000000/FREQUENCY is the cycle time. 
        For example, if you want the PWM to have a frequency of 1000Hz, the value set for init is 1000000/1000 = 1000.
      */

  // Khởi tạo chân PWM là đầu ra
  // initialize PWM pin is output
  pinMode(pwm1Pin, OUTPUT);
  pinMode(pwm2Pin, OUTPUT);
  // Ban đầu đặt duty cycle cho 2 xung PWM = 0
  // set the initial duty cycle for both PWM signals = 0
  Timer1.pwm(pwm1Pin, 0);
  Timer1.pwm(pwm2Pin, 0);
      /*
        Giá trị duty cycle (0-100%) ứng với 0-1023
        The duty cycle (0-100%) corresponds to 0-1023
      */

  delay(500);
}

void loop() {
  // quay theo chiều kim đồng hồ
  // rotate clockwise
  Serial.println("quay theo chieu kim dong ho");
  run(pwm1Pin);
  stop();

  // quay nguoc chieu kim dong ho
  // rotate counterclockwise
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
