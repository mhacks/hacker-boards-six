#include "ledGrid.h"


void setup(){
  reset();
}

void loop(){
  int row = 4;
  int col = 4;
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      on(i,j);
      delay(100);
    }
  }
}

