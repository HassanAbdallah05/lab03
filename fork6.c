#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int n; 

    printf("Enter the number of children: ");
    scanf("%d", &n); 

    if (n > 10){
        printf("Number of children exceeds 10\n");
        exit(1);
    }    

    pid_t pid; 
    int i; 

    for (i = 0; i < n; i++){
        pid = fork();
        if (pid < 0){
            perror("Fork doesn't work");
            exit(1);
        }
        if (pid == 0){
            printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }
    }
    int s;
    pid_t ch_pid;
    
    for (i = 0; i < n; i++){
        ch_pid = wait(&s);
        if (ch_pid > 0) {
            if (WIFEXITED(s)){
                printf("Child PID: %d terminated normally and the exit status: %d\n",
                       ch_pid, WEXITSTATUS(s));
            } else if (WIFSIGNALED(s)) {
                printf("Child PID: %d terminated abnormally by signal: %d\n",
                       ch_pid, WTERMSIG(s));
            }
        } else {
            perror("wait");
            exit(1);
        }
    }

    return 0;
}
