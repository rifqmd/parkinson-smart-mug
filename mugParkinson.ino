#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>   

Servo sg90;
Servo servo;
Servo servo2;
MPU6050 sensor ;

int servo_pin = 6;
int servo_pin2 = 7;
int servo_pin3 = 5;
int16_t ax, ay, az ;
int16_t gx, gy, gz ;

void setup() {
  sg90.attach(servo_pin);
  servo.attach(servo_pin2);
  servo2.attach(servo_pin3);
  Wire.begin();
  Serial.begin(9600); 
  Serial.println("Initializing the sensor"); 
  sg90.write(90);
  servo.write(90);
  servo2.write(90);
  sensor.initialize(); 
  Serial.println(sensor.testConnection() ? "Successfully Connected" : "Connection failed"); 
  delay(1000); 
  Serial.println("Taking Values from the sensor");
  delay (1000);
}


void loop(){ 

  sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);
  ax = map (ax, -17000, 17000, 0, 180);
  ay = map (ay, -17000, 17000, 0, 180);
  az = map (az, -17000, 17000, 0, 180);

  Serial.print("ax = ");
  Serial.println(ax);
  Serial.print("ay = ");
  Serial.println(ay);
  Serial.print("az = ");
  Serial.println(az);

  sg90.write(ax);
  servo.write(ay);
  servo2.write(az); 
  delay(1);
  // default 200

}