#include "mm.h"
#define SIZE 4096

Mm::Mm(){
  int* mm = new int[4096];//(int*)malloc( sizeof(int) * SIZE);
  mmPtr = mm;
}
void Mm::read(int addr, int* data){
  *data = mmPtr[addr];
}

void Mm::write(int addr,int *data){
  mmPtr[addr] = *data;
}
