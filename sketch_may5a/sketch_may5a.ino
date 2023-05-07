#include <mcp2515.h>

MCP2515 mcp2515(10);

void setup() {
  // put your setup code here, to run once:
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();

  Serial.begin(9600);
}

struct can_frame frame;
//int prevData = -1;

void loop() {
  // put your main code here, to run repeatedly:
  
  frame = can_frame();

  if (mcp2515.readMessage(&frame) == MCP2515::ERROR_OK && frame.can_id == 1){
    Serial.print("recv can req frame; data = ");
    Serial.println(frame.data[0]);

    /*if (prevData != -1 && frame.data[0] - 1 != prevData && !(frame.data[0] == 0 && prevData == 255)){
      Serial.print("MESSAGE SKIPPED = ");
      Serial.print(prevData);
      Serial.print(" : ");
      Serial.println(frame.data[0]);
    }
    
    prevData = frame.data[0];*/

    //

    frame = can_frame();

    frame.can_id = 2;
    frame.can_dlc = 1;
    frame.data[0] = 5;

    mcp2515.sendMessage(&frame);
  }

  delay(20);  
}
