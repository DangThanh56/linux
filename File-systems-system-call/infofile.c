#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
    int fd;
    int numb_write;
    char buf1[20] = "Thanh master linux  ";
    fd = open("text.txt", O_RDWR | O_APPEND, 0667 );
    if(fd == -1){
        printf("open() text.txt failed\n");
    }

    numb_write = write(fd, buf1, strlen(buf1));
    printf("Write %d bytes to text.txt\n", numb_write);

    lseek(fd, 0, SEEK_SET);
    write(fd, "Hello\n", strlen("Hello\n"));

    close(fd);
    return 0;

}
//Although you use set seek of position 0, data is still being added at the end of text.txt
//As you use O_APPEND flag