#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){ //Cấp phát stack frame cho hàm main()
    pid_t child_pid;    //Save on stack frame of main()
    child_pid = fork(); //Creat childeren process
    if(child_pid >= 0){
        if(child_pid == 0){
            printf("I am children process, my PID is:%d\n",getpid());
            printf("My parent PID is:%d\n",getppid());
        }
        else{
            printf("I am parent process, my PID is %d\n",getpid());
        }
    }

}