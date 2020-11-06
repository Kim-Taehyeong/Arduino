#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, PIN, NEO_GRB + NEO_KHZ800);

#include <SoftwareSerial.h> // 0,1번핀 제외하고 Serial 통신을 하기 위해 선언

// Serial 통신핀으로 D11번핀을 Rx로, D10번핀을 Tx로 선언
SoftwareSerial mySerial(10, 9); // HC-06 TX=11번핀 , RX=10번핀 연결

void setup()
{
 Serial.begin(9600); // 통신 속도 9600bps로 PC와 시리얼 통신 시작
 mySerial.begin(9600); // 통신 속도 9600bps로 블루투스 시리얼 통신 시작
 pinMode(2,INPUT);
 pinMode(3, INPUT);

  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
}

void loop()
{
  String Week;
  String Date;
  String TimeStr;
  String pmcf100;
  String pmcf25;
  String pmcf10;
  String h;
  String t;
  String UV;
 // mySerial 핀에 입력이 들어오면, 바이트단위로 읽어서 PC로 출력
 if (mySerial.available()){
      Week = mySerial.readStringUntil('\n');
      Date = mySerial.readStringUntil('\n');
      TimeStr = mySerial.readStringUntil('\n');
      pmcf100 = mySerial.readStringUntil('\n');
      pmcf25 = mySerial.readStringUntil('\n');
      pmcf10 = mySerial.readStringUntil('\n');
      h = mySerial.readStringUntil('\n');
      t = mySerial.readStringUntil('\n');
      UV = mySerial.readStringUntil('\n');
    
 }
  // Serial 핀에 입력이 들어오면, 바이트단위로 읽어서 블루투스로 출력
 if (Serial.available()){
   mySerial.write(Serial.read());
 }
 int a = digitalRead(2);
 int b = digitalRead(3);
 if(a == HIGH && b != HIGH)
 {
   strip.begin();
   strip.clear();
   strip.show();
   Serial.println("Dont Press");
   delay(500);
 }
 else{
  if(Week != "")
   {  
   Serial.println(Week);
   Serial.println(Date);
   Serial.println(TimeStr);
   Serial.println(pmcf100);
   Serial.println(pmcf25);
   Serial.println(pmcf10);
   Serial.println(h);
   Serial.println(t);
   Serial.println(UV);
   Serial.println("OK");
   if(pmcf100.toInt() < 50) Good();
   else if(pmcf100.toInt() >=50 && pmcf100.toInt() <100) Soso();
   else if(pmcf100.toInt() >=100 && pmcf100.toInt() <150) Bad();
   else if(pmcf100.toInt() >=150) Crazy();

   
   Serial.println("Press");
  }
 }
}

void Good()
 {
   strip.begin();
  strip.setBrightness(10);
  strip.setPixelColor(2,0,0,255);
  strip.setPixelColor(3,0,0,255);
  strip.setPixelColor(4,0,0,255);
  strip.setPixelColor(5,0,0,255);
  strip.setPixelColor(9,0,05,255);
  strip.setPixelColor(14,0,0,255);
  strip.setPixelColor(23,0,0,255);
  strip.setPixelColor(21,0,0,255);
  strip.setPixelColor(18,0,0,255);
  strip.setPixelColor(16,0,0,255);
  strip.setPixelColor(24,0,0,255);
  strip.setPixelColor(31,0,0,255);
  strip.setPixelColor(39,0,0,255);
  strip.setPixelColor(37,0,0,255);
  strip.setPixelColor(34,0,0,255);
  strip.setPixelColor(32,0,0,255);
  strip.setPixelColor(40,0,0,255);
  strip.setPixelColor(43,0,0,255);
  strip.setPixelColor(44,0,0,255);
  strip.setPixelColor(47,0,0,255);
  strip.setPixelColor(54,0,0,255);
  strip.setPixelColor(49,0,0,255);
  strip.setPixelColor(58,0,0,255);
  strip.setPixelColor(59,0,0,255);
  strip.setPixelColor(60,0,0,255);
  strip.setPixelColor(61,0,0,255);
  strip.show();
  delay(1000);
  strip.clear();
}


void Soso()
{
   strip.begin();
  strip.setBrightness(10);
  strip.setPixelColor(2,23,255,38);
  strip.setPixelColor(3,23,255,38);
  strip.setPixelColor(4,23,255,38);
  strip.setPixelColor(5,23,255,38);
  strip.setPixelColor(9,23,255,38);
  strip.setPixelColor(14,23,255,38);
  strip.setPixelColor(23,23,255,38);
  strip.setPixelColor(21,23,255,38);
  strip.setPixelColor(18,23,255,38);
  strip.setPixelColor(16,23,255,38);
  strip.setPixelColor(24,23,255,38);
  strip.setPixelColor(31,23,255,38);
  strip.setPixelColor(39,23,255,38);
  strip.setPixelColor(37,23,255,38);
  strip.setPixelColor(34,23,255,38);
  strip.setPixelColor(32,23,255,38);
  strip.setPixelColor(40,23,255,38);
  strip.setPixelColor(36,23,255,38);
  strip.setPixelColor(35,23,255,38);
  strip.setPixelColor(47,23,255,38);
  strip.setPixelColor(54,23,255,38);
  strip.setPixelColor(49,23,255,38);
  strip.setPixelColor(58,23,255,38);
  strip.setPixelColor(59,23,255,38);
  strip.setPixelColor(60,23,255,38);
  strip.setPixelColor(61,23,255,38);
  strip.show();
  delay(1000);
  strip.clear();
}

void Bad()
{
   strip.begin();
  strip.setBrightness(10);
  strip.setPixelColor(2,255,146,1);
  strip.setPixelColor(3,255,146,1);
  strip.setPixelColor(4,255,146,1);
  strip.setPixelColor(5,255,146,1);
  strip.setPixelColor(9,255,146,1);
  strip.setPixelColor(14,255,146,1);
  strip.setPixelColor(23,255,146,1);
  strip.setPixelColor(21,255,146,1);
  strip.setPixelColor(18,255,146,1);
  strip.setPixelColor(16,255,146,1);
  strip.setPixelColor(24,255,146,1);
  strip.setPixelColor(31,255,146,1);
  strip.setPixelColor(39,255,146,1);
  strip.setPixelColor(42,255,146,1);
  strip.setPixelColor(45,255,146,1);
  strip.setPixelColor(32,255,146,1);
  strip.setPixelColor(40,255,146,1);
  strip.setPixelColor(36,255,146,1);
  strip.setPixelColor(35,255,146,1);
  strip.setPixelColor(47,255,146,1);
  strip.setPixelColor(54,255,146,1);
  strip.setPixelColor(49,255,146,1);
  strip.setPixelColor(58,255,146,1);
  strip.setPixelColor(59,255,146,1);
  strip.setPixelColor(60,255,146,1);
  strip.setPixelColor(61,255,146,1);
   strip.show();
  delay(1000);
  strip.clear();
}

void Crazy()
{
   strip.begin();
  strip.setBrightness(10);
  strip.setPixelColor(3,255,0,0);
  strip.setPixelColor(4,255,0,0);
  strip.setPixelColor(11,255,0,0);
  strip.setPixelColor(12,255,0,0);
  strip.setPixelColor(20,255,0,0);
  strip.setPixelColor(19,255,0,0);
  strip.setPixelColor(27,255,0,0);
  strip.setPixelColor(28,255,0,0);
  strip.setPixelColor(36,255,0,0);
  strip.setPixelColor(35,255,0,0);
  strip.setPixelColor(52,255,0,0);
  strip.setPixelColor(51,255,0,0);
  strip.setPixelColor(59,255,0,0);
  strip.setPixelColor(60,255,0,0);
   strip.show();
  delay(1000);
 strip.clear();
}
