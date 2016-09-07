/********************* t.c file **************************/
#include <stdio.h>
#include <string.h>
#include "myprintf.c"
int mymain(int argc, char *argv[ ], char *env[ ])
{
  int i = 0;
   myprintf("in mymain(): argc = %d\n", argc);
   for(i=0; i<strlen(*argv); i++){
      myprintf("in mymain(): argv[", i);
      myprintf("] = %s\n", argv[0]);
    }
   myprintf("in mymain(): argv[1] = %d\n", argv[1]);
   myprintf("in mymain(): argv[2] = %d\n", argv[2]);
//1. Use YOUR myprintf() to print command-line parameters as

    //   argv[0] = (a string)
    //   argv[1] = (a string)
    //   ............


//2. Use YOUR myprintf() to print the env[] strings

//3. use YOUR myprintf() to print your PATH and HOME environment variables:
    //   PATH=...........................
  //     HOME=..........................

//4.

    myprintf("---------- testing YOUR myprintf() ---------\n");
    myprintf("this is a test\n");
    myprintf("testing a=%d b=%x c=%c s=%s\n", 123, 123, 'a', "testing");
    myprintf("string=%s, a=%d  b=%u  c=%o  d=%x\n",
           "testing string", -1024, 1024, 1024, 1024);
    myprintf("mymain() return to main() in assembly\n");
}
