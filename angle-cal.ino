#include <Servo.h>

int BASE = 3;
int SHOULDER = 5;
int ELBOW = 6;
int WRIST = 9;
int GRIP = 10;
int GRIPPER = 11;
// 핀 연결

Servo S1, S2, S3, S4, S5, S6;


float pos1 = 0;//초기 각도 찾아줘야함
float pos2 = 25;
float pos3 = 30;
float pos4 = 15;
float pos5 = 20;
float pos6 = 0;


String serData;
int obj;
int x_cord;
int y_cord;



void setup() {
  serData = "pixel,num,0,100,234";
  // put your setup code here, to run once:
  S1.attach(BASE);
  S2.attach(SHOULDER);
  S3.attach(ELBOW);
  S4.attach(WRIST);
  S5.attach(GRIP);
  S6.attach(GRIPPER);
  


  Serial.begin(9600);
}


void loop() {

  S1.write(pos1);//초기 각도 출력
  S2.write(pos2);
  S3.write(pos3);
  S4.write(pos4);
  S5.write(pos5);
  S6.write(pos6);
  serData.trim();
  int pixel = serData.indexOf(",");
  int num = serData.indexOf(",",pixel+1);
  int first = serData.indexOf(",",num+1); // 분류 콤마위치
  int next = serData.indexOf(",",first+1); // 좌표 콤마 위치
  int strlength = serData.length(); // 문자열 길이
  String str1 = serData.substring(num+1, first); // 첫번째 토큰
  String str2 = serData.substring(first+1, next); // 두번째 토큰
  String str3 = serData.substring(next+1,strlength); // 세번째 토큰
  
  obj = str1.toInt();
  x_cord = str2.toInt();
  y_cord = str3.toInt(); 

  Serial.println(obj);
  delay(1000);
  Serial.println(x_cord);
  delay(1000);
  Serial.println(y_cord);
  delay(1000);



  float BASE_ANGLE = atan(200/x_cord);//BASE ANGLE 값 구하기(Z값은 200으로 설정)
  Serial.print("base angle: ");
  Serial.println(BASE_ANGLE);  
  float pos11 = BASE_ANGLE;//1step-1
  float pos21 = 349.6;//1step-2
  float pos31 = 35;
  float pos41 = 25.3;
  float pos51 = 20;
  float pos61 = 0;

  S1.write(pos11);
  delay(500);//BASE 회전 1step-1
    
  S2.write(pos21);//1step-1 나머지 로봇팔 회전(바닥에서 5cm)
  S3.write(pos31);
  S4.write(pos41);
  S5.write(pos51);
  S6.write(pos61);


  float pos12 = BASE_ANGLE;
  float pos22 = 335.5;//2step 바닥까지 내려가기
  float pos32 = 42.6;
  float pos42 = 31.85;
  float pos52 = 20;
  float pos62 = 0;

  S1.write(pos12);
  S2.write(pos22);
  S3.write(pos32);
  S4.write(pos42);
  S5.write(pos52);
  S6.write(pos62);

  float pos63 = 360;//3 step 그리퍼 집기

  S6.write(pos63);
  delay(500);

  float pos14 = 0;//4step 바구니로 옮기기 위해 로봇팔 들어올려주는 과정(바구니랑 간섭나지 않도록 하는 각도 아직 못찾음. 찾아줘야함)
  float pos24 = pos2;
  float pos34 = pos3;
  float pos44 = pos4;
  float pos54 = 0;
  float pos64 = 360;

  S1.write(pos14);
  S2.write(pos24);
  S3.write(pos34);
  S4.write(pos44);
  S5.write(pos54);
  S6.write(pos64);
  delay(500);
  serData = ""; //제일 마지막줄에 넣어줘야함
}
  