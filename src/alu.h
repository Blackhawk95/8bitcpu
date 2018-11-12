class Alu{
  int inA;
  int inB;
  int* out;
  int* flagbuf; //flag resides in regsiters, this acts as a buffer before storing in reg
  /* micro-ops TODO: use enum here
   * 0 : nop, out = inA
   * 1 : add, out = inA + inB
   * 2 : sub, out = inA - inB
   * 3 : nand, out = ~(inA & inB)
   * 4 : xor, out = int&~inB + ~inA&inB
  */
  int op; //deals with microcode

  public:
  Alu();
  void compute(int op,int inA,int inB,int* out,int* flagbuf);
};
