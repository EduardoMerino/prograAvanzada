#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "fizz_buzz.h"

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
  char** result = fizzBuzz(1);
  printf("%s\n", result[0]);
  char* expected[1];
  expected[0] = "FizzBuzz";
  printf("%s", expected[0]);
  muAssert("error, result is NULL", result[0] != NULL);
  muAssert("error, result not expected", strcmp(result[0], expected[0]) == 0);
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
