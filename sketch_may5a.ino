#include <mcp2515.h>

MCP2515 mcp2515(10);

void setup() {
  // put your setup code here, to run once:
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();

  Serial.begin(9600);
}

uint8_t c = 0;

void loop() {
  // put your main code here, to run repeatedly:
  struct can_frame frame;
  frame.can_id = 0x001;
  frame.can_dlc = 1;
  frame.data[0] = c;

  mcp2515.sendMessage(&frame);

  Serial.print("sent msg = ");
  Serial.println(c);
  c++;
  delay(50);  
}
