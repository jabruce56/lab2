typedef unsigned int u32;
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
  {
    putchar('0');
  }
  else
  {
    if(x/10)
  {
    printd(x/10);
  }
  putchar(x%10 + '0');
  }
  return x;
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
main ()
{
  printx(123);
  //char *s = "hello";
  //prints(s);


  //printd(4);
  //printd(4);
  //printd(0);
  //printd(1);
  //printo(2305);
}
