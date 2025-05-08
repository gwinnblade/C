#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_signal (int sig){
	printf("Signal recieved %d\n", sig);
	exit(sig);
}

int main(){
	signal(SIGABRT, handle_signal);
	signal(SIGFPE,  handle_signal);
	signal(SIGILL,  handle_signal);
	signal(SIGINT,  handle_signal);
	signal(SIGSEGV, handle_signal);
	signal(SIGTERM, handle_signal);
	
	int choice;
	printf("	Choose signal:\n \
	1) SIGABRT \n \
	2) SIGFPE \n \
	3) SIGILL \n \
	4) SIGINT \n \
	5) SIGSEGV \n \
	6) SIGTERM \n \
	0) Exit\n");
	scanf("%d", &choice);
	
	switch (choice){
		case 1:
			raise (SIGABRT);
			break;
		case 2:
			raise (SIGFPE);
			break;
		case 3:
			raise (SIGILL);
			break;
		case 4:
			raise (SIGINT);
			break;
		case 5:
			raise (SIGSEGV);
			break;
		case 6:
			raise (SIGTERM);
			break;
		case 0:
			printf("Exit from programm \n");
			break;
		default:
			printf("Wrong choice. \n");
	}
	return 0;
}
