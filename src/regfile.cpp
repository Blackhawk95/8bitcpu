#include "regfile.h"

regfile::regfile(){
  reg = {0,0,0,0,0,0,0,0,0,0};
  PC = {0};
  SP = {0};
  A = {0};
  flag = {0};
}
regfile::read(int addr,int *data){

}
