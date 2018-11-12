class regfile{
  int reg[10];
  int PC;
  int SP;
  int A;
  int flag;
  int addr;
  public:
  regfile();
  void read(int addr,int *data);
  void write(int addr,int *data);
};
