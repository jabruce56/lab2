#include <stdio.h>
#include <stdlib.h>
typedef unsigned short u16;
typedef unsigned int u32;
int BASE = 10;
char *table = "0123456789ABCDEF";
int rpu(u32 x)
{
  char c;
  if (x){
     c = table[x % BASE];
     rpu(x / BASE);
     putchar(c);
  }
}
int printu(u32 x)
{
  if (x==0)
     putchar('0');
  else
     rpu(x);
  putchar(' ');
}
void prints(char *s)
{
  int i=0;
  while(i<strlen(s))
    putchar(s[i++]);
}
int printd(int x)//print signed integer
{
  if(x<0)
  {
      x=-x;
      putchar('-');
  }
  if(x==0)
    putchar('0');
  else
  {
    if(x/10)
      printd(x/10);
    putchar(x%10 + '0');
  }
  //return x;
}
int printo(u32 x)//print octal
{
  if(x!=0)
  {
    printo(x/8);
    printd(x%8);
  }
  //return x;
}
int printx(u32 x)//print hex
{
  if(x!=0)
  {
    printx(x/16);
    if((x%16)>9)
      putchar((x%16)+55);
    else
      printd(x%16);
  }
}
int myprintf(char *fmt, ...)
{
  char *cp = fmt;
  u16 *ip = (u16 *)&fmt + 1;//points to first variable
  u32 *up;
  while(*cp)
  {
    if(*cp!='%')
    {
      putchar(*cp);
      if (*cp=='\n')
        putchar('\r');
      cp++; continue;
    }
    cp++;
    switch(*cp)
    {
      case 'c':
        putchar(*ip); break;
      case 's':
        prints(*ip); break;
      case 'u':
        printu(*ip); break;
      case 'd':
        printd(*ip); break;
      case 'o':
        printo(*(u32 *)(ip++)); break;
      case 'x':
        printx(*(u32 *)(ip++)); break;
    }
    cp++;
    ip++;
    }
  }

main ()
{
  char *a = "and";
  char c = 'x';
  int b, i = 321;
  // for (i=0;i<300;i++)
  // {
  //   printd(rand()%100);
  //   putchar('\n');
  // }

  myprintf("stuff %d t %c g %c", 56, 'p', 'Z');
  //printx(123);
  //char *s = "hello";
  //prints(s);


  //printd(4);
  //printd(4);
  //printd(0);
  //printd(1);
  //printo(2305);
}
