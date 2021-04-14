#include "src/module4g.h"

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
      String mData = "{\"id\":\"" + m4g.getId() + "\",\"data\":{\"geo\":\"11635.8418,3995.5835\",\"t\":\"120421132710\",\"temp\":\"165\",\"pm25\":\"930\",\"wind\":\"40NE\"}}";
      String res = m4g.sendData(mData + "\n");
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
