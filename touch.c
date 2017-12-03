#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
char buf[512];

int main(int argc, char *argv[]){
    int fd;
    if(argc < 2){
        printf(1, "touch: the file not specified\n");
        exit();
    }
    else{
        fd=open(argv[1], O_CREATE);
        close(fd);
        exit();
    }
    
}
