#include <stdio.h>
#include <stdlib.h>


void main(int argc, char **argv){
  int numPTs = 10;
  /*long = 4bytes, 1PT = 4MB = 4 billion bytes*/
  long *longArr = (long*)calloc(numPTs * 1000000, sizeof(long));
  for(int i = 0; i < 50000; i++){
    longArr[i] = i + 1000; //just store some long
    // if(i > 49994) printf("arr[%d] = %ld\n", i, longArr[i]);
  }
  system("cat /proc/meminfo");
printf("////////////////////////////my divider///////////////////\n");
  free(longArr);
}
