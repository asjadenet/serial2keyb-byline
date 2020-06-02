#include <Keyboard.h>
HardwareSerial Serial2(PA3, PA2);
String in_string = "";

void setup()
{
  Keyboard.begin();
  Serial2.begin(115200);
  while (!Serial2)
  {
  }
  Serial2.println("Keyboard starting..");
  Serial2.setTimeout(10000);
}

void loop()
{
  if (Serial2.available() > 0)
  {
    in_string = Serial2.readStringUntil('\r');
    Serial2.println(in_string);
    Keyboard.println(in_string);
    Keyboard.write(KEY_RETURN);
  }
}