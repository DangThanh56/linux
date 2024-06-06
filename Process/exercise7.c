#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void func(int signum){
    printf("I am in func()\n");
    wait(NULL);
}

int main(int argc, char *argv[]){
    pid_t child_pid;
    child_pid = fork();

    if(child_pid >= 0){
        if(child_pid == 0){
            printf("I am children process with PID: %d\n",getpid());
            exit(0);
        }
        else{
            printf("I am parent process with PID: %d\n",getpid());
            signal(SIGCHLD, func);
            while(1);
        }
    }
    else{
        printf("fork() unsuccessfully\n");
    }
}