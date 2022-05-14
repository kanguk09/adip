String serData;
int obj;
int x_cord;
int y_cord;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0){
    char rec = Serial.read();
    serData += rec; // 픽셀 ,수, 물체, 좌표순으로 나와야 함

    if (rec == "\n"){
      Serial.print("MESSAGE RECEIVED: ");
      Serial.println(serData);
    }
    break;
  }      // 이거는 확인용이라 삭제해도 됨

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



  serData = "" //제일 마지막줄에 넣어줘야함
}
  

