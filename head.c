#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

int main(int argc, char *argv[]){
    int fd, i,line=5;
    if(argc <= 1){
        printf(1,"head: file tidak jelas\n");
        exit();
    }

    for(i = 1; i < argc; i++){
        if((fd = open(argv[i], 0)) < 0){
            printf(1, "head: cannot open %s\n", argv[i]);
            exit();
        }
        printf(1,"==> %s <==\n",argv[i]);
        int n=read(fd, buf, sizeof(buf));
        int count=0;
        if(n < 0){
            printf(1, "head: read error\n");
            exit();
        }
        for(int j=0;j<n;j++){
                if(buf[j]=='\n') {
            //        printf(1,"ini enter\n");
                    count++;
                }
                if(count==line) {
                    printf(1,"\n");
                    break;
                }
            //printf(1,"ini count%d\n",count);
            printf(1,"%c",buf[j]);
        }
        close(fd);
        if(i!=argc-1) printf(1,"\n");
    }
    exit();
}
