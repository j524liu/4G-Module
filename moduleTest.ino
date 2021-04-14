#include "module4g.h"

// SoftwareSerial mSerial(2, 3);
// module4g m4g(&mSerial);
module4g m4g(2, 3, 9600, "000001-01");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(100);
  Serial.print("SERIAL READY\n");
  // mSerial.begin(9600);
  delay(100);
  // mSerial.print("Soft READY\n");
  if(m4g.initModule())
  {
    Serial.print("----------Configuration SUCCEEDED----------\n");
  }
  else
  {
    Serial.print("----------Configuration FAILED----------\n");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  String str = "WAKEUP";
  // Serial.println(str);
  
  if(m4g.sendSetting(str))
  {
    Serial.print("Configuration SUCCEED.\n");
    delay(100);
    String rst = m4g.sendQuery("DTUID");
    if(rst != "\0")
    {
      Serial.print(rst);
      String res = m4g.sendData(m4g.getId() + "\n");
      Serial.print(res);
    }
    else
    {
      Serial.print("ERROR READING DATA.\n");
    }
  }
  else
  {
    Serial.print("TRY AGAIN PLEASE.\n");
  }
  // delay(1000);
  while(1);
}
