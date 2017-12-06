#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2){
    printf(2, "Usage: truncate files...\n");
    exit();
  }

  for(i = 1; i < argc; i++){
    if(argv[i] < 0){
      printf(2, "truncate: %s failed to truncate\n", argv[i]);
      break;
    }
	unlink(argv[2]);
	open(argv[2], O_CREATE);
  }

  exit();
}
