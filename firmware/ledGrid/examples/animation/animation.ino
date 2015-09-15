#include "ledGrid.h"

uint16_t animation1[8]={
  0x1000,
  0x2100,
  0x4210,
  0x8421,
  0x0842,
  0x0084,
  0x0008,
  0x0000
};

uint16_t animation2[2]={
  0xf99f,
  0x0660
};



void setup() {                
  // initialize the digital pin as an output.
  reset();

}
// the loop routine runs over and over again forever:
void loop() {
writeAnimation(animation1, 8, 5, 0);
writeAnimation(animation1, 8, 5, 1);
writeAnimation(animation1, 8, 5, 0);
writeAnimation(animation1, 8, 5, 1);
  for (int i = 0; i < 10; i++){
    writeAnimation(animation2, 2, 5, 0);
    writeAnimation(animation2, 2, 5, 1);
  }
}
