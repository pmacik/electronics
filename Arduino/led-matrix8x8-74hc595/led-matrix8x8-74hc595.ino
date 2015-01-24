// LED matrix 8x8 with 74HC595 register
// Version 1.0
//
// Developed for Arduino Nano (rev. 3)
//
// The HW project for the register module can be found at https://github.com/pmacik/electronics/tree/master/KiCad/multiregister
// The HW project for the LED matrix module can be found at https://github.com/pmacik/electronics/tree/master/KiCad/led-matrix
// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <EEPROM.h>

const int MEMORY_STATUS_ADDR = 0;
const int MEMORY_SIZE_ADDR = 1;
const int MEMORY_START = 2;
const byte SIGNATURE = B10101010;

// pins
const int clock = 7;
const int latch = 6;
const int data = 5;

//0-8
byte bars[] = {
  B00000000,
  B10000000,  
  B11000000,
  B11100000,
  B11110000,
  B11111000,
  B11111100,
  B11111110,
  B11111111
};

byte noChar[5] = {
  B00010000,
  B00000000,
  B00010000,
  B00000000,
  B00010000
};

byte charset[][5] = {
  {   // A
    B01111000,
    B00010100,
    B00010100,
    B00010100,
    B01111000
  }
  ,{ // B
    B01111100,
    B01010100,
    B01010100,
    B01010100,
    B00101000
  }
  ,{ // C
    B00111000,
    B01000100,
    B01000100,
    B01000100,
    B01000100
  }
  ,{ // D
    B01111100,
    B01000100,
    B01000100,
    B01000100,
    B00111000
  }
  ,{ // E
    B01111100,
    B01010100,
    B01010100,
    B01010100,
    B01000100
  }
  ,{ // F
    B01111100,
    B00010100,
    B00010100,
    B00010100,
    B00000100
  }
  ,{ // G
    B00111000,
    B01000100,
    B01000100,
    B01010100,
    B01110100
  }
  ,{ // H
    B01111100,
    B00010000,
    B00010000,
    B00010000,
    B01111100
  }
  ,{ // I
    B00000000,
    B00000000,
    B01111100,
    B00000000,
    B00000000
  }
  ,{ // J
    B00100000,
    B01000000,
    B01000000,
    B01000000,
    B00111100
  }
  ,{ // K
    B01111100,
    B00010000,
    B00010000,
    B00101000,
    B01000100
  }
  ,{ // L
    B01111100,
    B01000000,
    B01000000,
    B01000000,
    B01000000
  }
  ,{ // M
    B01111100,
    B00001000,
    B00010000,
    B00001000,
    B01111100
  }
  ,{ // N
    B01111100,
    B00001000,
    B00010000,
    B00100000,
    B01111100
  }
  ,{ // O
    B00111000,
    B01000100,
    B01000100,
    B01000100,
    B00111000
  }
  ,{ // P
    B01111100,
    B00010100,
    B00010100,
    B00010100,
    B00001000
  }
  ,{ // Q
    B00111000,
    B01000100,
    B01000100,
    B01100100,
    B01111000
  }
  ,{ // R
    B01111100,
    B00010100,
    B00010100,
    B00010100,
    B01101000
  }
  ,{ // S
    B01001000,
    B01010100,
    B01010100,
    B01010100,
    B00100100
  }
  ,{ // T
    B00000100,
    B00000100,
    B01111100,
    B00000100,
    B00000100
  }
  ,{ // U
    B00111100,
    B01000000,
    B01000000,
    B01000000,
    B00111100
  }
  ,{ // V
    B00011100,
    B00100000,
    B01000000,
    B00100000,
    B00011100
  }
  ,{ // W
    B00111100,
    B01000000,
    B00110000,
    B01000000,
    B00111100
  }
  ,{ // X
    B01000100,
    B00101000,
    B00010000,
    B00101000,
    B01000100
  }
  ,{ // Y
    B00000100,
    B00001000,
    B01110000,
    B00001000,
    B00000100
  }
  ,{ // Z
    B01000100,
    B01100100,
    B01010100,
    B01001100,
    B01000100
  }
};

// variables
const int N = 8;
const int L = 6;
byte buffer[N]={
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
volatile long now = 0;
volatile int value = 0;
volatile byte readByte = 0;
volatile int charIndex = 0;
const int MAX_MESSAGE_SIZE = 32;
byte defaultMessage[MAX_MESSAGE_SIZE] = {
  'S', 'E', 'N', 'D', 0, 'S', 'O', 'M', 'E', 'T', 'H', 'I', 'N', 'G', 0, 'O', 'V', 'E', 'R', 0, 'S', 'E', 'R', 'I', 'A', 'L'};
byte message[MAX_MESSAGE_SIZE + 1];
int messageSize = 26;

// init
void setup(){
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
  byte memStatus = EEPROM.read(MEMORY_STATUS_ADDR);
  byte memSize = 0;
  if(memStatus == SIGNATURE){
    memSize = EEPROM.read(MEMORY_SIZE_ADDR);
  } 
  else {
    EEPROM.write(MEMORY_STATUS_ADDR, SIGNATURE);
    EEPROM.write(MEMORY_SIZE_ADDR, messageSize);
    for(int i = 0; (i < messageSize); i++){
      EEPROM.write(MEMORY_START + i, defaultMessage[i]);
    }
  }

  message[0] = 0;
  if(memSize > 0){
    for(int i = 1; (i <= memSize) && (i <= MAX_MESSAGE_SIZE); i++){
      message[i] = EEPROM.read(i - 1 + MEMORY_START);
    }
    messageSize = memSize + 1;
  } 
  else {
    for(int i = 1; i <= messageSize; i++){
      message[i] = defaultMessage[i - 1];
    }
  }

  Serial.begin(9600);
}

// latch output
void fire(){
  digitalWrite(latch, HIGH);
  digitalWrite(latch, LOW);
}

// sends single byte to the register
void _doSend(byte b){
  shiftOut(data, clock, MSBFIRST, b);
}

// sends character and multiplex bytes to the register
void doSend(byte character, byte multiplex){
  _doSend(multiplex);
  _doSend(character);
  fire();
}

// sends a message saved in the array to display
void sendMsg(byte msg[]){
  byte mask = B10000000;
  for(int i = 0; i < N; i++){
    doSend(~msg[i], mask);
    mask = mask >> 1;
  }
}

// shift bytes in buffer an add a new one at the head
void queue(byte b){
  for(int i = N - 1; i > 0; i--){
    buffer[i] = buffer[i-1];
  }
  buffer[0] = b;
}

// main loop
void loop(){
  now = micros();
  while((micros()-now) < 150000){
    sendMsg(buffer);
  }
  if(charIndex < L - 1){
    if(message[value] == 0){
      queue(noChar[charIndex]);
    } 
    else {
      queue(charset[message[value] - 65][charIndex]);
    }
    //queue(charset[value][charIndex]);
    charIndex++;   
  } 
  else {
    queue(B00000000);
    charIndex = 0;
    if(value < messageSize - 1){
      //if(value < 25){
      value++;
    } 
    else {
      value = 0;
      int msgIndex = 1;
      boolean updateMsg = false;
      while(Serial.available() > 0 && msgIndex < MAX_MESSAGE_SIZE - 1){
        updateMsg = true;
        byte readByte = Serial.read();
        EEPROM.write(MEMORY_START + msgIndex - 1, readByte);
        if(readByte >= 'A' && readByte <= 'Z'){
          message[msgIndex] = readByte;
        } 
        else {
          message[msgIndex] = 0;
        }
        msgIndex++;
      }
      if(updateMsg){
        messageSize = msgIndex;
        EEPROM.write(MEMORY_SIZE_ADDR, messageSize - 1);
      }
    }
  }
}

