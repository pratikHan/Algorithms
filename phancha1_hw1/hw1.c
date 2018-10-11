#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char *argv[]) {
	int h=0,c=0,i;
	pid_t pid_x,pids[c];


h=atoi(argv[1]);
c=atoi(argv[2]);


printf("(%d): Process starting..\n",getpid());
printf("(%d): Parent's id= (%d)\n",getpid(),getppid());
printf("(%d): Height in the tree = %d\n",getpid(),h);
printf("(%d): Creating %d children at height %d\n",getpid(),c,h-1);


if(h>1){


for (i=0;i<c; i++){

pids[i]=fork();


if(pids[i]<0){
	perror("Fork Failed Try again ");
	}

if(pids[i]==0){
	printf("Current Process is of child %d with pid: %d\n",c,(int)getpid );

	char _h[5];
	sprintf(_h,"%d",h-1);

printf("Arg 0: %s\n",argv[0] );

	if(execlp(argv[0],argv[0],_h,argv[2],(char *) NULL) == -1) {
		perror( "exec failed");
	}
	exit(0);


	}

if(pids[i]>0){
	printf("Parent of child %d with pid %d\n ",c,(int)getpid );
}

}

while(c>0){
		pid_x=wait(NULL);
		c--;
}

printf("(%d):Terminating at height %d\n",getpid(),h);

}else {
	printf("(%d):Terminating at height %d\n",getpid(),h);
}

return 0;
  }
