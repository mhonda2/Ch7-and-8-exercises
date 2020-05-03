//Program to print all files with a title and page count

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 500

void print_file(const char* file) {
  char line[SIZE];
  memset(line, 0, SIZE);

  FILE* f = fopen(file, "r");
  if(!f) {
    fprintf(stderr, "Error opening file\n");
    fclose(f);
    exit(1);
  }

  while (fgets(line, SIZE, f) != NULL) {
    printf("%s", line);
  }

  fclose(f);
}

int main(int argc, const char* argv[]) {

  if (argc == 1) {
    printf("Usage: ./program file1 file2 file3...\n");
    exit(1);
  }

  for (int i = 1; i < argc; ++i) {
    const char* filename = argv[i];
    printf("> File: %s\n", filename);   //title
    print_file(filename);
    printf("\n> Page #: %d\n\n", i);    //page number
  }


  return 0;
}
