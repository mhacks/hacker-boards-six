

#include "ledGrid.h"


int colPins[rows] = {8,9,11,12};
int rowPins[cols] = {4,5,6,7};
//int rowPins[rows]={3,4,5,2};
//int colPins[cols]={7,8,9,10};
int pinmode[15];
void setmode(){
  for (int i = 0; i < rows; i++){
    pinMode(rowPins[i], pinmode[rowPins[i]]);
  }  
  for (int i = 0; i < cols; i++){
   pinMode(colPins[i], pinmode[colPins[i]]);
  }
  
    
}
void reset(){
  for (int i = 0; i < rows; i++){
    digitalWrite(rowPins[i], LOW);
    pinmode[rowPins[i]] = INPUT;
  }  
  for (int i = 0; i < cols; i++){
    digitalWrite(colPins[i], LOW);
    pinmode[colPins[i]] = INPUT;
  }
    setmode();
}



void on(int r, int c){
  reset();
  pinmode[rowPins[r]] = OUTPUT;
  pinmode[colPins[c]] = OUTPUT;
  setmode();
  digitalWrite(rowPins[r], HIGH);
  digitalWrite(colPins[c], LOW);
}


 uint16_t CountSetsBits (uint16_t  x){
      uint16_t count;
      for (count = 0; x; count++)
          x &= x - 1; 
      return count;
    }

//writes an image from a 16-bit string and display it in time in mill
void writeImage(uint16_t hexVal, int time) {
  signed int imageTime;
  imageTime = time * 10; 
  while (imageTime > 0){
    int i = 0;
     for (uint16_t mask = 00000001; mask>0; mask <<= 1) { //iterate through bit mask
       if (hexVal & mask){
         on(i/4,i%4);
         delayMicroseconds(250);
      }
      i++;
    }
    imageTime--;
  }
}

void writeAnimation(uint16_t *hexVals, int size, int time, int reverse){
  if (reverse == 0) {
    for (int i =0; i < size; i++){
      writeImage(hexVals[i], time);
    }
  } else {
     for (int i =size-1; i >= 0; i--){
      writeImage(hexVals[i], time);
     }
  }
}