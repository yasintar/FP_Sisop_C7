#include "types.h"
#include "stat.h"
#include "user.h"
char buf[512],inp[10];

int main(int argc, char *argv[]){
    int fd, i,line=5,awal=1;
    if(argc <= 1){
        printf(1,"head: file tidak jelas\n");
        exit();
    }
    
    if(argv[1][0]=='-')
    {
        //printf(1,"ini angka\n");
        awal= 2;
        line=0;
        int temp =strlen(argv[1]),j=0;
        for(i=1; i<temp; i++){
            inp[j]=argv[1][i];
            j++;
        }
        line =  atoi(inp);
      //  printf(1,"line %d\n",line);
    }
    
    for(i = awal; i < argc; i++){
        if((fd = open(argv[i], 0)) < 0){
            printf(1, "head: cannot open %s\n", argv[i]);
            exit();
        }
        if((awal==2 && argc>3) || (awal==1 && argc>2)) printf(1,"==> %s <==\n",argv[i]);
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
