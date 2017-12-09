#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{

int n, fd0, fd1;

char buf[strlen(argv[2])];

  if(argc < 3){
    printf(2, "Usage: truncate size files...\n");
    exit();
  }
  
  if(argc > 3){
    printf(2, "Usage: truncate size files...\n");
  }

  if(open(argv[2],O_RDONLY) < 0){
    printf(1, "truncate: file %s not found.\n", argv[1]);
    exit();
  }

    fd0=open(argv[2], O_CREATE|O_RDWR);    
    fd1= *argv[2];

  while ( ( n = read (fd0, buf, fd1)) > 0 ){
	write ( fd0, buf, n );
  }

  exit();
}
