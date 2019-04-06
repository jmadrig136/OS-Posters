#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void main(int argc, char **argv){
  int numPTs = 10;
  time_t t;
  /*Below are 10 arrays each the size of one page table 4MB*/
  long *longArr0 = (long*)calloc(1000000, sizeof(long));
  long *longArr1 = (long*)calloc(1000000, sizeof(long));
  long *longArr2 = (long*)calloc(1000000, sizeof(long));
  long *longArr3 = (long*)calloc(1000000, sizeof(long));
  long *longArr4 = (long*)calloc(1000000, sizeof(long));
  long *longArr5 = (long*)calloc(1000000, sizeof(long));
  long *longArr6 = (long*)calloc(1000000, sizeof(long));
  long *longArr7 = (long*)calloc(1000000, sizeof(long));
  long *longArr8 = (long*)calloc(1000000, sizeof(long));
  long *longArr9 = (long*)calloc(1000000, sizeof(long));
  
 
  srand((unsigned)time(&t)); /*Initialize rand()*/
 
  for(int i = 0; i < 50000; i++ ){
    int pickPT = rand() % numPTs;
    int delta = rand() % 1000000;
    long placement = pickPT+delta;
    //above won't actually go from 0 to a billion-1, rand range (0,32767)
    //but since I'm using it as an offset to the array it won't really matter
    
    switch(pickPT){
      case 0:
	longArr0[placement] = i + 1000;
	break;
      case 1:
	longArr1[placement] = i + 1000;
	break;
      case 2:
	longArr2[placement] = i + 1000;
	break;
      case 3:
	longArr3[placement] = i + 1000;
	break;
      case 4:
	longArr4[placement] = i + 1000;
	break;
      case 5:
	longArr5[placement] = i + 1000;
	break;
      case 6:
	longArr6[placement] = i + 1000;
	break;
      case 7:
	longArr7[placement] = i + 1000;
	break;
      case 8:
	longArr8[placement] = i + 1000;
	break;
      default:
	longArr9[placement] = i + 1000;
    }
    //printf("a = %d, b = %d, place = %ld\n",pickPT, delta, placement); 
  }

  system("cat /proc/meminfo");
  printf("////////////////////////////my divider///////////////////\n");

  free(longArr0);
  free(longArr1);
  free(longArr2);
  free(longArr3);
  free(longArr4);
  free(longArr5);
  free(longArr6);
  free(longArr7);
  free(longArr8);
  free(longArr9);
}
