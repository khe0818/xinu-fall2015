/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

void cb(){
  kprintf("pid %d rec at time %s\n", currpid, receive());
}

process rec_process(){
  registercbsig(MYSIGRECV, &cb, 0);
 // kprintf("pid %d is going to sleep at time %d\n",currpid, clktimefine);
 // sleep(10000);
  while(1); 
}


process	main(void)
{
	/*kprintf("\nHello World!\n");
	kprintf("\nI'm the first XINU app and running function main() in system/main.c.\n");
	kprintf("\nI was created by nulluser() in system/initialize.c using create().\n");
	kprintf("\nMy creator will turn itself into the do-nothing null process.\n");
	kprintf("\nI will create a second XINU app that runs shell() in shell/shell.c as an example.\n");
	kprintf("\nYou can do something else, or do nothing; it's completely up to you.\n");
	kprintf("\n...creating a shell\n");
	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));
	*/
	pid32 p1 = create(rec_process, 4096, 20, "rec_test", 1, NULL);
	resume(p1);
	send(p1, "rec123");

	/* Wait for shell to exit and recreate it */

	/*while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	*/
	return OK;
}
