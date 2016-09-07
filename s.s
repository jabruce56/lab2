#--------------------- s.s file --------------------------
    .global main, mymain, myprintf
main:
    pushl  %ebp
    movl   %esp, %ebp

#-------------------------- DO THESE --------------------------------
# (2). Write ASSEMBLY code to call mymain(argc, argv, env)
#                     HELP:
#  When crt0.o calls main(int argc, char *argv[], char *env[]),
#  it passes argc, argv, env to main().
#  Draw a diagram to see where are argc, argv, env?
#--------------------------------------------------------------------

# (4). Return to caller
    movl  %ebp, %esp
	  popl  %ebp
	  ret
#---------  end of s.s file ----------------------------
