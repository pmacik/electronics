// Advent Candles
// Version 1.2
//
// Developed for Arduino Nano (rev. 3)
//
// The HW project can be found at https://github.com/pmacik/electronics/tree/master/KiCad/advent-candles
// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h" // RTClib can be found at https://github.com/adafruit/RTClib

RTC_DS1307 rtc;
const int first = 3;
const int second = 4;
const int third = 5;
const int fourth = 6;

void setup () {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  pinMode(first, OUTPUT);
  pinMode(second, OUTPUT);
  pinMode(third, OUTPUT);
  pinMode(fourth, OUTPUT);
  digitalWrite(first, LOW);
  digitalWrite(second, LOW);
  digitalWrite(third, LOW);
  digitalWrite(fourth, LOW);
}

void loop () {
  DateTime now = rtc.now();
  unsigned int nowYear = now.year();
  DateTime lastAdventSunday = getLastAdventSunday(nowYear);

  long nowUnixTime = now.unixtime();
  
  // If date is between first advent Sunday and the 26th of December (incl.)
  // show light the candles.
  if ((nowUnixTime >= (lastAdventSunday - TimeSpan(21, 0, 0, 0)).unixtime()) //
    && (nowUnixTime < DateTime(nowYear, 12, 27, 0, 0, 0).unixtime())){ 
    digitalWrite(first, HIGH);

    if(nowUnixTime >= (lastAdventSunday - TimeSpan(14, 0, 0, 0)).unixtime()){
      digitalWrite(second, HIGH);
    }
    
    if(nowUnixTime >= (lastAdventSunday - TimeSpan(7, 0, 0, 0)).unixtime()){
      digitalWrite(third, HIGH);
    }
    
    if(nowUnixTime >= lastAdventSunday.unixtime()){
      digitalWrite(fourth, HIGH);
    }
  }
  delay(1000);
}

DateTime getLastAdventSunday(unsigned int year){
  DateTime christmasDay = DateTime(year, 12, 24, 0, 0, 0);
  unsigned int weekDay = christmasDay.dayOfWeek();
  if(weekDay == 7){
    return christmasDay;
  } 
  else {
    return DateTime(year, 12, 24 - weekDay, 0, 0, 0);
  }
}

