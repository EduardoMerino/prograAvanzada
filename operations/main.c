#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"
#define MAX_LENGTH 12
#define printDebug(msg) do { char *value = getenv("OPER_DEBUG"); if(!strcmp(value, "t")) printf("%s", msg); } while (0)

int subtract(int a, int b){
  return a - b;
}

int sum(int a, int b){
  return a + b;
}

char *operationNames_ES[] = {"suma", "resta"};
char *operationNames_EN[] = {"sum", "subtract"};
char *operationNames_FR[] = {"somme", "reste"};

char *messages_ES = "Nombre de la operación : ";
char *messages_EN = "What operation : ";
char *messages_FR = "Nom de l'opération : ";

/* Add function signatures here */
int main(int argc, char **argv) {
  /* Start your code here */
  char message[200];
  int operator1, operator2;
  int (*operation) (int, int);
  char* operationName = malloc(sizeof(char) * MAX_LENGTH);

  char** operationNames;
  char* messages;
  char* lang;

  lang = getenv("OPER_LANG");
  if((lang != NULL) && !strcmp(lang, "EN")){
    operationNames = operationNames_EN;
    messages = messages_EN;
  }else if((lang != NULL) && !strcmp(lang, "ES")){
    operationNames = operationNames_ES;
    messages = messages_ES;
  }else if((lang != NULL) && !strcmp(lang, "FR")){
    operationNames = operationNames_FR;
    messages = messages_FR;
  }

  printf("%s\n", messages);
  scanf("%s", operationName);
  scanf("%d", &operator1);
  scanf("%d", &operator2);

  sprintf(message, "Operation name : %s\n", operationName);
  printDebug(message);
  sprintf(message, "operator1 : %d\n", operator1);
  printDebug(message);
  sprintf(message, "operator2 : %d\n", operator2);
  printDebug(message);

  if (!strcasecmp(operationName, operationNames[0])){
    operation = sum;
  }
  if(!strcasecmp(operationName, operationNames[1])){
    operation = subtract;
  }

  printf("%d\n", operation(operator1, operator2));

  return 0;
}
