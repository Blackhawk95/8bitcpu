class Mm{
  int *mmPtr;
  int addr;
  int *data;
  public:
  Mm();
  void read(int addr,int *data);
  void write(int addr,int *data);
};
