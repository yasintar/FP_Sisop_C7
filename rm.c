#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int i;

    if(argc < 2){
        printf(2, "rm: missing operand\n");
        exit();
    }

    for(i = 1; i < argc; i++){
        if(unlink(argv[i]) < 0){
            printf(2, "rm: cannot remove '%s' : No such file\n", argv[i]);
            break;
        }
    }
    exit();
}
