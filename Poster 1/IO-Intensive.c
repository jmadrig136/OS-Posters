#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

void main(int argc, char **argv){
  FILE* file_ptr;
  FILE* randFile_ptr;
  FILE* wrt_ptr;
  char* data;
  char* randData;
  char* fullDir;
  char readFile[] = "randFile.txt";
  char writeFile[] = "writeFile.txt";
  char dirStr[] = "./textFiles/";
  long fsize;
  long randFSize;
  int dirLen = strlen(dirStr);
  
  
  for(int i = 0; i < 500; i++){
    system("(cd textFiles && ls) | shuf -n 1 > randFile.txt");
    file_ptr = fopen(readFile, "r");  //contains random file name
    wrt_ptr = fopen(writeFile, "w");  //write results
    if(file_ptr == NULL){
      printf("Cannot find randFile\n");
      exit(0);
    }else if(wrt_ptr == NULL){
      printf("Cannot find writeFile\n");
      exit(0);
    }

    
    fseeko(file_ptr, 0, SEEK_END);
    fsize = ftello(file_ptr) - 1; 
    rewind(file_ptr);
    data = (char*)calloc(fsize, sizeof(data));
    data[fsize] = '\0';
    fread(data, sizeof(char), fsize, file_ptr); //reading random file name
    rewind(file_ptr);
   
    /*Store path*/
    fullDir = (char*)calloc(fsize + dirLen, sizeof(fullDir));
    strcpy(fullDir, dirStr);
    strcat(fullDir, data);
    fullDir[fsize + dirLen] = '\0';
    // printf("fsize = %ld, dirLen = %d, fullDirLen = %ld\nfullDir (%s)\n", fsize, dirLen, strlen(fullDir), fullDir);
    
    randFile_ptr = fopen(fullDir, "r");
    if(randFile_ptr == NULL){
      printf("Cannot find randFile_ptr (%s)\n", fullDir);
      exit(0);
    }

    fseeko(randFile_ptr, 0, SEEK_END);
    randFSize = ftello(randFile_ptr);
    rewind(randFile_ptr);
    randData = (char*)calloc(randFSize, sizeof(randData));
    randData[randFSize] = '\0';
    fread(randData, sizeof(char), randFSize, randFile_ptr); //reading random file content
    //printf("strLength = %ld, my String: %s\n", randFSize,randData);
    fwrite(randData, sizeof(char), randFSize, wrt_ptr); //writting random file content
   
    fclose(file_ptr);
    fclose(wrt_ptr);
    fclose(randFile_ptr);
    free(data);
    free(randData);
    free(fullDir);
    }
}
