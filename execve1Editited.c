#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    char cmd[]="./fork2";

    char *argv[]={"fork2", NULL};
    char *argc[]= {NULL}; 
    char *envp[]={NULL};

    printf("---------The beginning of the original program---------\n");
    if(execve(cmd,argv,argc)<0)
    {
        printf("%s : Command not found\n",cmd);
        exit(0);
    }

    printf("\n\nIf you reached here then smthn went wrong");

    return 0;


}
