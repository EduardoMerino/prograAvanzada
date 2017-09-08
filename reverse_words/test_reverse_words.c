#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "reverse_words.h"

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
  char *words = "hola profesor soy lalo hola";
  char *result = reverseWords(words);
  char *expected = "aloh roseforp yos olal aloh";
  printf("RESULT: %s, EXPECTED : %s\n", result, expected);
  muAssert("the string wasnt reversed properly", strcmp(result, expected) == 0);
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
