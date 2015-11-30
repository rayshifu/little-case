#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int i=0,sum=0;
void sig_alarm_handler(int signal){
	++i;
	sum += i;
	if(i<100)
		alarm(1);
	else{
		printf("%d\n",sum);
		exit(0);
	}
}

int main(){
	signal(SIGALRM,sig_alarm_handler);
	alarm(1);
	int x;
	scanf(" %d",&x);
	return 0;
}
