#include <iostream>
#include "alu.h"
#include "mm.h"

using namespace std;

//g++ src/cpu.cpp src/alu.cpp
//./a.out 2 255 255
int main(int argc, char** argv){
  int a,b,c,d,e;
  int *p,*q;
  p = &d;
  q = &e;
  *p = 0;
  *q = 0;
  a = atoi(argv[2]);
  b = atoi(argv[3]);
  c = atoi(argv[1]);
  Alu alu;
  Mm mm;


  alu.compute(c,a,b,p,q);
  cout<<c<<" "<<a<<" "<<b<<" "<<*p<<" ";
  printf("%x\n",*q);
  mm.write(0,p);
  alu.compute(3,a,b,p,q);
  cout<<c<<" "<<a<<" "<<b<<" "<<*p<<" ";
  printf("%x\n",*q);
  mm.write(1,p);
  cout<<c<<" "<<a<<" "<<b<<" "<<*p<<" ";
  printf("%x\n",*q);

  mm.read(0,p);
  printf("%x\n",*p);

  mm.read(1,p);
  printf("%x\n",*p);
}
