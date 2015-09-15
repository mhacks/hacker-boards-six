#ifndef LedGrid_H
#define LedGrid_H
#include <Stdint.h>
#include <Arduino.h>

 
#define rows 4
#define cols 4

void setmode();
void reset();
void on(int r, int c);
uint16_t CountSetBits (uint16_t  x);
void writeImage(uint16_t hexVal, int time);
void writeAnimation(uint16_t *hexVals, int size, int time, int reverse);


#endif	