#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "keyboard_row.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

static char * testUnit() {
  char* input[] = {"hello", "alaska", "dad", "peace"};
  char* expected[] = {"alaska", "dad"};
  char** result = findWords(input, 4, 2);
  printf("expected[0] = %s, result[0] = %s \n", expected[0], result[0]);
  muAssert("Result wasn't the one expected", strcmp(expected[0], result[0]) == 0);
  return 0;
}

static char * allTests() {
  muRunTest(testUnit);
  return 0;
}

int main(int argc, char **argv) {
  char *result = allTests();
  if (result != 0) {
    printf("        __       _\n");
    printf("     __/~~\\-- _ | \\ \n");
    printf("__- - {            \\ \n");
    printf("     /             \\  xx\n");
    printf("    /       ;X    X }\n");
    printf("    |              ;\n");
    printf("                   |  \n");
    printf("       \\_       (..)\n");
    printf("         -_ _ _ /\n");
    printf("           /\n");
    printf("          /\n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else {
    printf("        __       _\n");
    printf("     __/~~\\-- _ | \\ \n");
    printf("__- - {            \\ \n");
    printf("     /             \\  !!\n");
    printf("    /       ;^    ^ }\n");
    printf("    |              ;\n");
    printf("                   |  \n");
    printf("       \\_       (..)\n");
    printf("         -_ _ _ /\n");
    printf("           /\n");
    printf("          /\n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", testsRun);
  return result != 0;
}
