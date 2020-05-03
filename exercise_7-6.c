//Compares two files and prints the first line where they differ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 500

int main(int argc, const char* argv[]) {
  FILE* f;
  FILE* s;
  char buf1[SIZE];
  char buf2[SIZE];

  if (argc == 3) {
    f = fopen(argv[1], "r");
    if(!f) {
      fprintf(stderr, "Error opening file\n");
      fclose(f);
      exit(1);
    }

    s = fopen(argv[2], "r");
    if(!s) {
      fprintf(stderr, "Error opening file\n");
      fclose(s);
      exit(1);
    }

    memset(buf1, 0, SIZE);
    memset(buf2, 0, SIZE);
    while(fgets(buf1, SIZE, f) != NULL && fgets(buf2, SIZE, s) != NULL)
    {
      if (strcmp(buf1, buf2) != 0) {
        printf("Lines differ at: \n");
        printf("File 1: %s\n", buf1);
        printf("File 2: %s\n", buf2);

        return 0;
      }
    }
    printf("Files are the same\n");

  }
  else {
    printf("Usage: ./program file1 file2\n");
    exit(2);
  }

  return 0;
}
