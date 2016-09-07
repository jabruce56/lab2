/********************* t.c file **************************/
#include <stdio.h>
#include <string.h>
int mymain(int argc, char *argv[ ], char *env[ ])
{
  int i = 0;

  //testing myprintf
  char *a = "and";
  char c = 'x';
  int b = 321;
  myprintf("\n    ----test----\n");
  myprintf("  ------test------\n");
  myprintf("--------test--------\n\n");
  myprintf("stuff %c and %d\n", c, b);
  myprintf("this is a string\n");
  myprintf("this is %c hi %d test %x\n", 'A', 1234, 100);
  myprintf("this is a test\n");
  myprintf("testing a=%d b=%x c=%c s=%s\n", 123, 123, 'a', "testing");
  myprintf("string=%s, a=%d  b=%u  c=%o  d=%x\n", "testing string", -1024, 1024, 1024, 1024);
  myprintf("mymain() return to main() in assembly\n");
  myprintf("hex=%x oct=%o char=%c int=%d string=%s unsigned=%u\n\n\n", 1024, 1024, 'v', 1024, "this is a string", 1024);
  //end testing

  char *PATH, *HOME;


  myprintf("in mymain(): argc = %d\n", argc);
  for(i=0; i<argc; i++){
      myprintf("in mymain(): argv[%d] = %s\n", i, argv[i]);
  }
  for(i=0; env[i]; i++){
      myprintf("in mymain(): env[%d] = %s\n", i, env[i]);
      if (!strncmp(env[i], "PATH", 4))
        PATH = env[i];
      if (!strncmp(env[i], "HOME", 4))
        HOME = env[i];

  }
  myprintf("PATH = %s\nHOME = %s\n", PATH, HOME);
//1. Use YOUR myprintf() to print command-line parameters as

    //   argv[0] = (a string)
    //   argv[1] = (a string)
    //   ............


//2. Use YOUR myprintf() to print the env[] strings

//3. use YOUR myprintf() to print your PATH and HOME environment variables:
    //   PATH=...........................
  //     HOME=..........................
    //myprintf("PATH=%s", $PATH);
    //myprintf("PATH=%s", $HOME);
//4.

    myprintf("---------- testing YOUR myprintf() ---------\n");
    myprintf("this is a test\n");
    myprintf("testing a=%d b=%x c=%c s=%s\n", 123, 123, 'a', "testing");
    myprintf("string=%s, a=%d  b=%u  c=%o  d=%x\n",
           "testing string", -1024, 1024, 1024, 1024);
    myprintf("mymain() return to main() in assembly\n");
}
