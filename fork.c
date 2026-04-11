#include<stdio.h>
#include<unistd.h>
int globvar=10;
int main(){
	int localvar=20;
	pid_t pid=fork(); //creates child process
	if(pid<0){
		printf("fork failed!");
		return 1;
	}
	else if(pid==0){
		//child process
		globvar++;
		localvar++;
		printf("child process: \n");
		printf("pid:%d, parent pid:%d \n",getpid(),getppid());
		printf("global var:%d, local var:%d \n",globvar,localvar);
	}
	else{
		globvar--;
		localvar--;
		printf("parent process:\n");
		printf("pid:%d, child pid:%d \n",getpid(),pid);
		printf("global var:%d, local var:%d \n",globvar,localvar);
	}
	return 0;
}
