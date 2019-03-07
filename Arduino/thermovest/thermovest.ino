#include <OneWire.h>
#include <DallasTemperature.h>

#define MAX_INPUT A0
#define MIN_INPUT A1
#define REQUESTED_INPUT A2

#define SENSOR_DATA_PIN 2
#define MIN_LED 3
#define MAX_LED 4

#define OUTPUT_PIN 9

#define MIN_TEMPERATURE 20.0
#define MAX_TEMPERATURE 40.0
#define TEMPERATURE_FINE_AMPL 2.0

#define MAX_TEMPERATURE_DIFF 5.0

long last = -1;
bool debug = true;
double temperature = -100;

OneWire oneWireDS(SENSOR_DATA_PIN);
DallasTemperature temp(&oneWireDS);

void setup()
{
  pinMode(OUTPUT_PIN, OUTPUT_PIN);
  digitalWrite(OUTPUT_PIN, LOW);

  pinMode(MIN_LED, OUTPUT_PIN);
  digitalWrite(MIN_LED, LOW);

  pinMode(MAX_LED, OUTPUT_PIN);
  digitalWrite(MAX_LED, LOW);

  pinMode(A0, INPUT);

  setPwmFrequency(OUTPUT_PIN, 1024);

  temp.begin();
  
  if (debug)
  {
    Serial.begin(9600);
  }
}

void loop()
{
  long tick = millis();
  if ((tick - last) > 1000)
  {
    ln("Reading temperature from sensor...");
    temp.requestTemperatures();
    delay(100);
    temperature = temp.getTempCByIndex(0);
    last = tick;
  }

  if (temperature <= -100){
    return;
  }
  double imin = convert(round(minT(analogRead(MIN_INPUT)) * 100), 0, 100, MIN_TEMPERATURE - TEMPERATURE_FINE_AMPL, MIN_TEMPERATURE + TEMPERATURE_FINE_AMPL);
  double imax = convert(round(maxT(analogRead(MAX_INPUT)) * 100), 0, 100, MAX_TEMPERATURE - TEMPERATURE_FINE_AMPL, MAX_TEMPERATURE + TEMPERATURE_FINE_AMPL);
  l("imin=");
  l(imin);
  l(", imax=");
  l(imax);
  l(", t=");
  l(temperature);
  double req = convert(round(reqT(analogRead(REQUESTED_INPUT)) * 100), 0, 100, imin, imax);
  l(", req=");
  l(req);
  l(", temperature=");
  l(temperature);
  l(", D_temp=");
  double dtemp = req - temperature;
  l(dtemp);
  l("=>");
  int out = convert(dtemp, 0, MAX_TEMPERATURE_DIFF, 0, 255);
  ln(out);
  if (out <= 0)
  {
    analogWrite(MIN_LED, 32);
    digitalWrite(MAX_LED, LOW);
  }
  else if (out >= 255)
  {
    analogWrite(MIN_LED, 0);
    digitalWrite(MAX_LED, HIGH);
  }
  else
  {
    digitalWrite(MIN_LED, LOW);
    digitalWrite(MAX_LED, LOW);
  }

  analogWrite(OUTPUT_PIN, out);
  delay(1000);
}

double minT(double in)
{
  double in2 = in * in;
  return 1.0 - (0.0000000217 * in2 * in - 0.0000344 * in2 + 0.0187 * in - 3.473);
}

double maxT(double in)
{
  double in2 = in * in;
  return 1.0 - (0.0000000368 * in2 * in - 0.0000675 * in2 + 0.0422 * in - 8.86);
}

double reqT(double in)
{
  if (in < 900)
  {
    return 1.01 - (1.116102 * pow(10, -21) * pow(in, 6.930044));
  }
  else
  {
    double r = 0.97 - (0.1596545 - 3.2456864 * pow(10, -10) * (1 - exp(0.02225626 * in)));
    if (r <= 0)
    {
      return 0;
    }
    else
    {
      return r;
    }
  }
}

double convert(double in, double imin, double imax, double omin, double omax)
{
  if (in <= imin)
  {
    return omin;
  }
  else if (in >= imax)
  {
    return omax;
  }

  double id = imax - imin;
  double od = omax - omin;
  double r = od / id;

  return (in - imin) * r + omin;
}

/**
 * Divides a given PWM pin frequency by a divisor.
 * 
 * The resulting frequency is equal to the base frequency divided by
 * the given divisor:
 *   - Base frequencies:
 *      o The base frequency for pins 3, 9, 10, and 11 is 31250 Hz.
 *      o The base frequency for pins 5 and 6 is 62500 Hz.
 *   - Divisors:
 *      o The divisors available on pins 5, 6, 9 and 10 are: 1, 8, 64,
 *        256, and 1024.
 *      o The divisors available on pins 3 and 11 are: 1, 8, 32, 64,
 *        128, 256, and 1024.
 * 
 * PWM frequencies are tied together in pairs of pins. If one in a
 * pair is changed, the other is also changed to match:
 *   - Pins 5 and 6 are paired on timer0
 *   - Pins 9 and 10 are paired on timer1
 *   - Pins 3 and 11 are paired on timer2
 * 
 * Note that this function will have side effects on anything else
 * that uses timers:
 *   - Changes on pins 3, 5, 6, or 11 may cause the delay() and
 *     millis() functions to stop working. Other timing-related
 *     functions may also be affected.
 *   - Changes on pins 9 or 10 will cause the Servo library to function
 *     incorrectly.
 * 
 * Thanks to macegr of the Arduino forums for his documentation of the
 * PWM frequency divisors. His post can be viewed at:
 *   http://forum.arduino.cc/index.php?topic=16612#msg121031
 */
void setPwmFrequency(int pin, int divisor)
{
  byte mode;
  if (pin == 5 || pin == 6 || pin == 9 || pin == 10)
  {
    switch (divisor)
    {
    case 1:
      mode = 0x01;
      break;
    case 8:
      mode = 0x02;
      break;
    case 64:
      mode = 0x03;
      break;
    case 256:
      mode = 0x04;
      break;
    case 1024:
      mode = 0x05;
      break;
    default:
      return;
    }
    if (pin == 5 || pin == 6)
    {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    }
    else
    {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  }
  else if (pin == 3 || pin == 11)
  {
    switch (divisor)
    {
    case 1:
      mode = 0x01;
      break;
    case 8:
      mode = 0x02;
      break;
    case 32:
      mode = 0x03;
      break;
    case 64:
      mode = 0x04;
      break;
    case 128:
      mode = 0x05;
      break;
    case 256:
      mode = 0x06;
      break;
    case 1024:
      mode = 0x07;
      break;
    default:
      return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

void l(const char msg[])
{
  if (debug)
  {
    Serial.print(msg);
  }
}

void ln(const char msg[])
{
  if (debug)
  {
    Serial.println(msg);
  }
}

void l(const int msg)
{
  if (debug)
  {
    Serial.print(msg);
  }
}

void ln(const int msg)
{
  if (debug)
  {
    Serial.println(msg);
  }
}

void l(const long msg)
{
  if (debug)
  {
    Serial.print(msg);
  }
}

void ln(const long msg)
{
  if (debug)
  {
    Serial.println(msg);
  }
}

void l(const float msg)
{
  if (debug)
  {
    Serial.print(msg);
  }
}

void ln(const float msg)
{
  if (debug)
  {
    Serial.println(msg);
  }
}

void l(const double msg)
{
  if (debug)
  {
    Serial.print(msg);
  }
}

void ln(const double msg)
{
  if (debug)
  {
    Serial.println(msg);
  }
}
