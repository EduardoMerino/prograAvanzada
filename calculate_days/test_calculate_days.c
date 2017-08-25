#include <stdio.h>
#include "minunit.h"
#include "calculate_days.h"

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
  Month month = MAR;
  int year = 2016;
  int monthDay = 10;
  int expected = 70;
  int result = calculateDays(month, monthDay, year);
  muAssert("number of days must isn't the expected one", result == expected);
  return 0;
}

static char * testYear() {
  int year = 2016;
  int expected = 1;
  int result = isLeap(year);
  muAssert("Must return 1, it's a leap year", result == expected);
  return 0;
}

static char * allTests() {
  muRunTest(testUnit);
  muRunTest(testYear);
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
    printf("     __/~~\\-- _ | \\\n");
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
