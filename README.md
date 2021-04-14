# 4G Module for Arduino ![C++ Badge](https://img.shields.io/badge/language-C%2B%2B-%23F34B7D.svg)

Please read this file before using this module.

## Table of Contents

- [Install](#install)
- [Usage](#usage)
- [API](#api)
- [Contributing](#contributing)

## Install

This module depends upon [SoftwareSerial](https://www.arduino.cc/en/Reference/SoftwareSerial) class.

1. In your work directory or where you like, run ` git clone` to get this module:

   ```
   git clone https://github.com/j524liu/4G-Module.git
   ```

2. Copy `src/module4g.h` and `src/module4g.cpp` to your work directory:

   ```bash
   ##In case of Linux
   cp ./src/module4g.* <your_work_dir>/
   ##In case of Windows
   copy src/module4g.* <your_work_dir>/
   ```

3. In your Arduino project, include the header file `module4g.h`:

   ``` c++
   #include "module4g.h"
   //your codes...
   ```

4. Enjoy!

### If you don't have a Git client setup
You can also download the .zip file. If so, replace `step 1` with `Unzip .zip file`:
``` bash
unzip <file_name>.zip
```

## Usage

`module_test.ino` is a simple demo to show how to create and configure a 4G module, how to send data to it.

Notice: The 4G Module requires a valid connection to your server, please setup your server correctly.

## API

1. `module4g(SoftwareSerial * serial, String id)`: Constructor, construct a 4G Module binded to a software serial port. Usage:

   ``` c++
   SoftwareSerial serial(rx, tx);
   module4g m4g(&serial, id);
   ```

2. `module4g(uint8_t rx, uint8_t tx, int baud, String id)`: Constructor, construct a 4G Module binded to a software serial port whose RX port is `rx`, TX port is `tx` and baudrate is `baud`. Usage:

   ``` c++
   module4g m4g(rx, tx, baud, id);
   ```

3. `int initModule()`: Initialize 4G module to default work mode. See details in `4G_Module_Brief.md`. Return 1 if initialized successfully, else return 0. Usage:

   ```c++
   void setup()
   {
   	if(m4g.initModule())  //m4g is a 4G module defined and initialized before;
       {
           //TODO: Handle SUCCEEDED boot
       }
       else
       {
           //TODO: Handle FAILED boot
       }
   }
   ```

4. `int sendSetting(String setting)`: Send a setting string to 4G module. Return 1 if succeed, else return 0. Usage:

   ``` c++
   void loop()
   {
       String setting = "WKMODE=0";  //Set work mode to 0;
       if(m4g.sendSetting(setting))  //m4g is a 4G module defined and initialized before;
       {
           //TODO: Handle success;
       }
       else
       {
           //TODO: Handle failure;
       }
   }
   ```

5. `String sendQuery(String query)`: Send a setting string to 4G module. Return response from 4G module if succeed, else return "\0". Usage:

   ``` c++
   void loop()
   {
       String query = "DTUID";  //Query ID of DTU;
       String res = m4g.sendSetting(query);  //m4g is a 4G module defined and initialized before;
       if(res != "\0")
       {
           //TODO: Handle success;
       }
       else
       {
           //TODO: Handle failure;
       }
   }
   ```

6. `String sendData(String mdata)`: Send data to 4G module, and send it to server. Return server's response. Usage:

   ```c++
   void loop()
   {
       String mdata = "data_to_be_sent_to_server_in_JSON";
       String res = m4g.sendData(mdata);  //m4g is a 4G module defined and initialized before;
       switch(res)
       {
           case CASE1:
               //TODO: Handle CASE1;
               break;
           case CASE2:
               //TODO: Handle CASE2;
               break;
               .
               .
               .
           default:
               //TODO: Handle default;
               break;
       }
   }
   ```

   

## Contributing

See [the contributing file](CONTRIBUTING.md)!

PRs accepted.

Small note: If editing the Readme, please conform to the [standard-readme](https://github.com/RichardLitt/standard-readme) specification.
