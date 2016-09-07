#include <string.h>
#include <stdlib.h>
typedef unsigned short u16;
typedef unsigned int u32;
int BASE = 10;
char *table = "0123456789ABCDEF";
int rpu(u32 x){
  char c;
  if (x){
     c = table[x % BASE];
     rpu(x / BASE);
     putchar(c);
  }
}
int printu(u32 x){
  if (x)
     rpu(x);
  else
     putchar('0');
  putchar(' ');
}
void prints(char *s){
  int i=0;
  while(i<strlen(s))
    putchar(s[i++]);
}
int rpd(int x){
  char c;
  if(x){
    c = table[x % 10];
    rpd(x/10);
    putchar(c);
  }
}
int printd(int x){//print signed integer
  if(x<0){
      x=-x;
      putchar('-');
  }
  if(x)
    rpd(x);
  else
    putchar('0');
  //return x;
}
int rpo(u32 x){
  char c;
  if(x){
    c = table[x%8];
    rpo(x/8);
    putchar(c);
  }
}
int printo(u32 x){//print octal
  putchar('0');
  if(x)
    rpo(x);
  else
    putchar('0');
}
int rpx(u32 x){
  char c;
  if(x){
    c = table[x%16];
    rpx(x/16);
    putchar(c);
  }
}
int printx(u32 x){//print hex
  putchar('0'); putchar('x');
  if(x)
    rpx(x);
  else
    putchar('0');
}
int myprintf(char *fmt, ...){
  char *cp = fmt;
  u32 *ip = (u32 *)&fmt + 1;//points to first variable
  while(*cp){
    if(*cp!='%'){//put all but %
      putchar(*cp);
      if (*cp=='\n')//if newline put return carriage instead
        putchar('\r');
      cp++; continue;
    }
    cp++;//move one past %
    switch(*cp){
      case 'c': putchar(*ip); break;
      case 's': prints((char *)*ip); break;
      case 'u': printu(*ip); break;
      case 'd': printd(*ip); break;
      case 'o': printo(*ip); break;
      case 'x': printx(*ip); break;
    }
    cp++;
    ip++;
    }
  }
int testmyprintf(){
  char *a = "and";
  char c = 'x';
  int b = 321;
  myprintf("\n----test----\n");
  myprintf("----test----\n");
  myprintf("----test----\n\n");
  myprintf("stuff %c and %d\n", c, b);
  myprintf("this is a string\n");
  myprintf("this is %c hi %d test %x\n", 'A', 1234, 100);
  myprintf("this is a test\n");
  myprintf("testing a=%d b=%x c=%c s=%s\n", 123, 123, 'a', "testing");
  myprintf("string=%s, a=%d  b=%u  c=%o  d=%x\n", "testing string", -1024, 1024, 1024, 1024);
  myprintf("mymain() return to main() in assembly\n");
  myprintf("hex=%x oct=%o char=%c int=%d string=%s unsigned=%u\n", 1024, 1024, 'v', 1024, "tessstt", 1024);
}
main (){
  testmyprintf();
}
