#include "alu.h"

Alu::Alu(): op(0),inA(0),inB(0),out(0),flagbuf(0) {}
void Alu::compute(int op,int inA,int inB,int* out,int* flagbuf) {
  switch(op){
    case 0: *out = inA; //NOP
            break;
    case 1: *out = inA + inB; //ADD
            break;
    case 2: *out = inA - inB; //SUB
            break;
    case 3: *out = ~((inA&0xFF)&(inB&0xFF)); //NAND
            break;
    case 4: *out = ((~(inA&0xFF))&(inB&0xFF)) + ((~(inB&0xFF))&(inA&0xFF)); //XOR
            break;
    default: *out = inA; //NOP
  }
  //checking for zero
  if(*out == 0){
    *flagbuf = *flagbuf | 1; // ZERO BIT
  }
  //checking for overflow
  if(*out > 0xFF){
    *flagbuf = *flagbuf | 2; // CARRY BIT
    *out = *out&0xFF;
  }
  //checking for negative
  if(*out < 0){
    *flagbuf = *flagbuf | 4; // NEGATIVE BIT
    *out = 0xFF + ~(*out&0xFF); //ensuring it stays inside the limit
  }
  if(*out == 0 && op == 2){
    *flagbuf = *flagbuf | 8; // EQUALS BIT
  }
}
