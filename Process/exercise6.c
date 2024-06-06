#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]){ //Allocate stack frame for main() func
    pid_t chid_pid;     //Save on stack frame main() func
    chid_pid = fork();  //Creat childern process
    int status, retPID; //Inititalize status of children process

    if(chid_pid >= 0){
        if(chid_pid == 0){  //Childern process
            printf("I am children process, my PID is:%d\n",getpid());
            while(1); //Can be kill by signal
            exit(1);
        }
        else{                       //Parent process            
            retPID = waitpid(chid_pid, &status, 0);
            if(retPID == -1){
                printf("wait() unsuccessfuly\n");
            }
            printf("I am parent process, my PID children process is:%d\n",retPID);
            printf("my PID is %d\n", getpid());
            if(WIFEXITED(status)){
                printf("Normally termination, status = %d\n",WEXITSTATUS(status));
            }
            if(WIFSIGNALED(status)){
                printf("killed by signal, status = %d\n",WTERMSIG(status));
            }
        }
    }
    else{
        printf("fork() unsuccessfully\n");      //fork() return -1 neu loi
    }
    return 0;
}