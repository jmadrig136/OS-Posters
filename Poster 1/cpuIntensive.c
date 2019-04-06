#include <stdio.h>
#include <limits.h>


void main(int argc, char **argv){
  //char command[INT_MAX];
  for(int i = 0; i < 500; i ++){
    system("(cd textFiles && ls) | shuf -n 100 | sort > cpuWrite.txt");
    //printf("Done with count %d\n", i);
  }
}
