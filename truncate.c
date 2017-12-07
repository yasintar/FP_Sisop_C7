#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];

int
main(int argc, char *argv[])
{

int n, fd0;

  if(argc < 2){
    printf(2, "Usage: truncate files...\n");
    exit();
  }
  
  if(argc > 1){
    printf(2, "Usage: truncate files...\n");
  }

  if(open(argv[1],O_RDONLY) < 0){
    printf(1, "truncate: file %s not found.\n", argv[1]);
    exit();
  }

    unlink(argv[1]);
    fd0=open(argv[1], O_CREATE);    


  while ( ( n = read (fd0, buf, sizeof(buf))) > 0 ){
	write ( fd0, buf, n );
  }

  exit();
}
