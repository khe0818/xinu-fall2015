 #include <xinu.h>

 syscall registercb( int (* func) (void) ) {
    proctab[currpid].cbfun = func;
    return OK;
  }