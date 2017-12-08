#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
  //validasi input
  if(argc<2)
  {
    printf(1,"need 2 arguments\n");
    exit();
  }
  //cd
  if(chdir(argv[1])<0)
  {
    printf(1,"can't change directory\n");
  }

  exit();
}
