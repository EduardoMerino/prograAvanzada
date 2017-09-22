#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "dict.h"

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

static char* testInitDictionary() {
  unsigned int size = 4;
  int errorCode;
  Dict *myDictionary = initDictionary(size, &errorCode);

  muAssert("myDictionary should be of the correct size", myDictionary->size == 4);
  muAssert("myDictionary's errorCode must be 0", errorCode == 0);
  return 0;
}

static char* testUpsertDictionary() {
  unsigned int size = 1;
  int errorCode;
  Dict *myDictionary = initDictionary(size, &errorCode);
  int value = 1;
  upsertDictionary(myDictionary, "uno", (void *)&value, sizeof(int), &errorCode);

  muAssert("myDictionary errorCode must be 0", errorCode == 0);
  muAssert("Strings aren't equal", strcmp(myDictionary->elements[0].key, "uno") == 0);
  muAssert("Value wasn't expected", *((int *)myDictionary->elements[0].value) == value);

  return 0;
}

static char* testGetDictionary(){
  unsigned int size = 1;
  int errorCode;
  Dict *myDictionary = initDictionary(size, &errorCode);
  int value = 1;
  upsertDictionary(myDictionary, "uno", (void*) &value, sizeof(int), &errorCode);
  void *result = getDictionary(myDictionary, "uno", sizeof(int), &errorCode);

  muAssert("myDictionary's errorCode must be 0", errorCode == 0);
  muAssert("Result must be equal to value.", *((int*)result) == value);

  return 0;
}

static char* testGetDictionaryNull(){
  unsigned int size = 100;
  int errorCode;
  Dict *myDictionary = initDictionary(size, &errorCode);
  int value = 1;
  upsertDictionary(myDictionary, "uno", (void*) &value, sizeof(int), &errorCode);
  void *result = getDictionary(myDictionary, "dos", sizeof(int), &errorCode);

  muAssert("myDictionary's errorCode must be 200", errorCode == 200);
  muAssert("Result must be equal to NULL.", result == NULL);

  return 0;
}

static char* allTests() {
  muRunTest(testInitDictionary);
  muRunTest(testUpsertDictionary);
  muRunTest(testGetDictionary);
  muRunTest(testGetDictionaryNull);
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
