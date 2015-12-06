#include <xinu.h>

syscall registercbsig( uint16 asig, int (* func) (void), uint32 optarg ) {

	if(asig == MYSIGRECV){
		proctab[currpid].cbfun = func;
		proctab[currpid].prhasmsg = FALSE;
	}

	if(asig == MYSIGXCPU){
		proctab[currpid].cpufun = func;
		proctab[currpid].cpuflag = FALSE;
		proctab[currpid].cpuval = optarg;
	}
	
	return OK;
}