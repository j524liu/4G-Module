#ifndef MODULE4G_H_
#define MODULE4G_H_

#include <Arduino.h>
#include <SoftwareSerial.h>

class module4g
{
  public:
    /*******
     * 
     * Constructor
     */
    module4g(SoftwareSerial * serial, String id);
    /*******
     * 
     * Constructor
     */
    module4g(uint8_t rx, uint8_t tx, int baud, String id);
    /*******
     *
     * Initiate module
    */
    int initModule();    
    /*******
     * 
     * Send a Setting cmd to 4g module
     */
    int sendSetting(String setting);
    /*******
     * 
     * Send a Query cmd to 4g module
     */
    String sendQuery(String query);
    /*******
     * 
     * Send Data to 4g module
     */
    String sendData(String mdata);
    /*******
     *
     *Get device ID
     */
    String getId();
  private:
    SoftwareSerial * mSerial;
    String id;
};

#endif
