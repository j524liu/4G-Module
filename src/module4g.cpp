#include "module4g.h"

module4g::module4g(SoftwareSerial * serial, String id)
{
  mSerial = serial;
  this -> id = id;
//  Serial.print("Soft READY\n");
}

module4g::module4g(uint8_t rx, uint8_t tx, int baud, String id)
{
  mSerial = new SoftwareSerial(rx, tx);
  mSerial -> begin(baud);
  this -> id = id;
//  Serial.print("Soft READY\n");
}

int module4g::initModule()
{
  int initFlag = 0;
  /*****************************
  * Configuration of 4g module,
  * See details in docs/4G_Module_Brief.md
  ******************************/
  if(this -> sendSetting("WKMODE=1"))
    if(this -> sendSetting("GPRSMODE=3"))
      if(this -> sendSetting("CHMODE=0"))
        if(this -> sendSetting("DBGMODE=0"))
          if(this -> sendSetting("DTUID=" + this -> id))
            if(this -> sendSetting("DATAID=0"))
              if(this -> sendSetting("SERVER1=0,49.232.152.70,3389"))
                if(this -> sendSetting("REGPKG=0"))
                  if(this -> sendSetting("DATAMD=0"))
                    if(this -> sendSetting("GPSCFG=4,0"))
                      initFlag = 1;
  return initFlag;
}

int module4g::sendSetting(String setting)
{
  String str = "AT*" + setting + "#\n";
  String rst = "";
  mSerial -> print(str);
  while (!mSerial -> available());
  while (mSerial -> available())
  {
    rst += char(mSerial -> read());
    delay(2);
  }
  // Serial.print(rst);
  // mSerial -> print(rst);
  if (rst == "OK\r\n")
  {
    // Serial.print("HELLOOOOOOO\n");
    return 1;
  }
  // Serial.print("WHYYYYYYYYYY\n");
  return 0;
}

String module4g::sendQuery(String query)
{
  String str = "AT*" + query + "?\n";
  String rst = "";
  mSerial -> print(str);
  while (!mSerial -> available());
  while (mSerial -> available())
  {
    rst += char(mSerial -> read());
    delay(2);
  }
  // return rst;
  if (rst.substring(rst.length() - 4, rst.length() - 2) == "OK")
  {
    return rst.substring(0, rst.length() - 5);
  }
  return "\0";
}

String module4g::sendData(String mdata)
{
  mSerial -> print(mdata);
  String rst = "";
  while(!mSerial -> available());
  while(mSerial -> available())
  {
    rst += char(mSerial -> read());
    delay(2);
  }
  return rst;
}

String module4g::getId()
{
  return this -> id;
}