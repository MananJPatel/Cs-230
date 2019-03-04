#include <stdio.h>

void print_it() {
  // TODO
  printf("Bit operations are fun!\n");
}

void print_int() {
  // TODO
  int x = 10;
  int y = 13;
  printf("x = %d\n",x);
  printf("y = %d\n",y);
  printf("size of signed int in bytes is %d.\n",(int)sizeof(x));
  printf("size of signed int in bits is %lu.\n",sizeof(y)*8);
  printf("%d + %d = %d.\n",x,y,x+y);
}

void print_float() {
  // TODO
  float x = 10.000000;
  float y = 13.000000;
  printf("x = %f\n",x);
  printf("y = %f\n",y);
  printf("size of single float in bytes is %lu.\n",sizeof(x));
  printf("size of single float in bits is %lu.\n",sizeof(y)*8);
  printf("%f + %f = %f.\n",x,y,x+y);
  printf("%f + %f = %d.\n",x,y,(int)(x+y));
}

void print_char() {
  // TODO
  char c = 'C';
  char a = 65;
  char f = 'F';
  char e = 'E';
  char b = 'B';
  printf("c = %c\n", c);
  printf("a = %c\n", a);
  printf("%c%c%c%c%c%c%c%c\n",c,a,f,e,b,a,b,e);
  printf("number of bytes: %lu.\n", sizeof(c)+sizeof(a)+sizeof(f)+sizeof(e)+sizeof(b)+sizeof(a)+sizeof(b)+sizeof(e)+1);
}

void packing_bytes() {
  // TODO
  unsigned char b3 = 202;
  unsigned char b2 = 254;
  unsigned char b1 = 186;
  unsigned char b0 = 190;
  unsigned int u = b0;
  u |= b1 << 8;
  u |= b2 << 16;
  u |= b3 << 24;
  printf("%X\n", u);
}

void unpacking_bytes() {
  // TODO
  unsigned int i1 = 1835098984u;
  unsigned int i2 = 1768842611u;
  unsigned char a1 = i1 >> 24;
  unsigned char a2 = i1 >> 16;
  unsigned char a3 = i1 >> 8;
  unsigned char a4 = i1;
  unsigned char a5 = i2 >> 24;
  unsigned char a6 = i2 >> 16;
  unsigned char a7 = i2 >> 8;
  unsigned char a8 = i2;
  printf("%c%c%c%c%c%c%c%c\n",a1,a2,a3,a4,a5,a6,a7,a8);
}

void print_bits() {
  // TODO
  unsigned char a = 181;
  unsigned char b = -75;
  unsigned b7,b6,b5,b4,b3,b2,b1,b0;  
  b7 = (a >> 7) & 0x1;
  b6 = (a >> 6) & 0x1; 
  b5 = (a >> 5) & 0x1;
  b4 = (a >> 4) & 0x1; 
  b3 = (a >> 3) & 0x1;
  b2 = (a >> 2) & 0x1; 
  b1 = (a >> 1) & 0x1;
  b0 = a & 0x1;  
  printf("%d%d%d%d%d%d%d%d\n", b7,b6,b5,b4,b3,b2,b1,b0);
  b7 = (b >> 7) & 0x1;
  b6 = (b >> 6) & 0x1;
  b5 = (b >> 5) & 0x1;
  b4 = (b >> 4) & 0x1;
  b3 = (b >> 3) & 0x1;
  b2 = (b >> 2) & 0x1;
  b1 = (b >> 1) & 0x1;
  b0 = b & 0x1;
  printf("%d%d%d%d%d%d%d%d\n", b7,b6,b5,b4,b3,b2,b1,b0);
}

void extracting_fields() {
  // TODO
  unsigned int cb = 0xCAFEBABE;
  unsigned int a1 = cb >> 29;
  unsigned int a2 = (cb << 3) >> 28;
  unsigned int a3 = (cb << 7) >> 28;
  unsigned int a4 = (cb << 11) >> 29;
  unsigned int a5 = (cb << 14) >> 29;
  unsigned int a6 = (cb << 17) >> 28;
  unsigned int a7 = (cb << 21) >> 28;
  unsigned int a8 = (cb << 25) >> 29;
  unsigned int a9 = (cb << 28) >> 30;
  unsigned int a10 = (cb << 30) >> 30;
  printf("%d %d %d %d %d %d %d %d %d %d\n",a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);
}

void updating_fields() {
  // TODO
  unsigned int result = 17512807u;
  result &= ~(15u << 18); 
  result |= (8u << 18);
  result &= ~(31u << 10);
  result |= (17u << 10);  
  printf("%08x\n",result);
}
