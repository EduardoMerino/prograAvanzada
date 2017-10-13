#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "qsort.h"
#define  MAX_LENGTH_ORDER 20
#define  STUDENTS_LENGTH 3

typedef struct student {
  char* name;
  int id;
}Student;

/* Add function signatures here */
int cmpStudent(void const *element1, void const *element2, int attribute){
  Student* student1 = (Student*) element1;
  Student* student2 = (Student*) element2;

  switch (attribute) {
    case 0: //name
      return strcmp(student1->name, student2->name);
    case 1: //student id
      return (student1->id - student2->id);
  }
}

int cmpNames(void const *element1, void const *element2){
  return cmpStudent(element1, element2, 0);
}

int cmpId(void const *element1, void const *element2){
  return cmpStudent(element1, element2, 1);
}

int main(int argc, char **argv) {
  char order[MAX_LENGTH_ORDER];
  int i;
  int neededStudent;
  Student group[STUDENTS_LENGTH];
  Student key;
  Student* foundStudent;

  group[0].name = strdup("Jhonny");
  group[0].id = 17;

  group[1].name = strdup("Peter");
  group[1].id = 14;

  group[2].name = strdup("Maria");
  group[2].id = 20;

  printf("Give me the order: ");
  scanf("%s", order);

  if(!strcmp(order, "id")){
    qsort(group, STUDENTS_LENGTH, sizeof(Student), cmpId);
  }

  if(!strcmp(order, "name")){
    qsort(group, STUDENTS_LENGTH, sizeof(Student), cmpNames);
  }

  for(i = 0; i < STUDENTS_LENGTH; i++){
    printf("Student %s %d \n", group[i].name, group[i].id);
  }

  printf("Which is the id? ");
  scanf("%d", &neededStudent);
  key.id = neededStudent;

  foundStudent = bsearch(&key, group, STUDENTS_LENGTH, sizeof(Student), cmpId);
  if(foundStudent != NULL){
    printf("Student %s %d \n", foundStudent->name, foundStudent->id);
  }else{
    printf("Student with id: %d not found\n", neededStudent);
  }

  return 0;
}
