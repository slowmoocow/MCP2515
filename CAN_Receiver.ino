#include <SPI.h>
#include <mcp2515.h>

#include <Wire.h> 

struct can_frame canMsg;
MCP2515 mcp2515(10);

void setup() 
{

  Serial.begin(9600);
  SPI.begin();          //Starter SPI kommunikasjon

  mcp2515.reset();

  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);  //Setter CAN speed
  mcp2515.setNormalMode();
}

void loop()
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)
  {
    if(canMsg.can_id==0x036)
    {
      int x = canMsg.data[0];
      Serial.println(x);
      delay(2000);
    }
  }
}
