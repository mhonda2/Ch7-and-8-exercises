//This program changes lower case to upper and upper case to lower
//depending on the command given
//Reads from stdin and writes to stdout

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
  int c;
  int flag = 0;

  if (argc == 2) {
      if (*argv[1] == 'l')
        flag = 1;
      else if (*argv[1] == 'u')
        flag = 2;
      else {
        printf("Unknown command\n");
        exit(2);
      }
    }
  else {
    printf("Usage: ./progam l(for tolower) or u(for toupper)\n");
    exit(1);
  }

  printf("Waiting for input...\n");

  while ((c = getchar()) != EOF) {
    if (flag == 1)
      putchar(tolower(c));

    if (flag == 2)
      putchar(toupper(c));
  }

  return 0;
}
