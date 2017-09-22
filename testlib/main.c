#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dict.h"

typedef struct a {
  char* name;
  int semestre;
}Student;

int main(int argc, char **argv) {
  Dict *students;
  Student st;
  Student *newStudent;
  int errorCode;
  students = initDictionary(100, &errorCode);
  char studentId[100];

  st.name = strdup("Pepe Perez");
  st.semestre = 6;
  upsertDictionary(students,  "0101", (void*) &st, sizeof(Student), &errorCode);

  st.name = strdup("Maria Lopez");
  st.semestre = 7;
  upsertDictionary(students,  "0202", (void*) &st, sizeof(Student), &errorCode);


  st.name = strdup("Carla Ramirez");
  st.semestre = 5;
  upsertDictionary(students,  "0303", (void*) &st, sizeof(Student), &errorCode);

  printf("What's the student's id? : ");
  scanf("%s", studentId);

  //if(studentId[0] == ''){
    //printf(" No student id declared.\n Use: ./students.exe 'student id' \n");
    //return 0;
  //}
  
  newStudent = (Student*) getDictionary(students, studentId, sizeof(Student), &errorCode);
  if(newStudent == NULL){
    printf(" Student %s not found.\n", studentId);
  }else{
    printf(" name: %s, semestre: %d\n", newStudent->name, newStudent->semestre);
  }

  return 0;
}
