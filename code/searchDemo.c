#include<stdio.h>
#include<stdlib.h>
#include<search.h>

#include "student.h"

int main(int argc, char **argv) {

  int n = 0;
  Student *roster = loadStudents("student.data", &n);
  int i;
  size_t numElems = n;


  printf("Roster: \n");
  printStudents(roster, n);

  /* Searching */
  Student *castro = NULL;
  Student *castroKey = NULL;
  Student *sandberg = NULL;
  char *str = NULL;

  castro = linearSearchStudentByNuid(roster, 10, 131313);
  str = studentToString(castro);
  printf("castro: %s\n", str);
  free(str);

  //create a key that will match according to the NUID
  int nuid = 23232323;
  Student * key = createEmptyStudent();
  key->nuid = nuid; 

  //use lfind to find the first such instance:
  //sandberg = 
  sandberg = lfind(key, roster, &numElems, sizeof(Student), studentIdCmp);
  str = studentToString(sandberg);
  printf("sandberg: %s\n", str);
  free(str);

  //create a key with only the necessary fields
  castroKey = createStudent("Starlin", "Castro", 0, 0.0);
  //sort according to a comparator function
  qsort(roster, n, sizeof(Student), studentLastNameCmp);

  castro = bsearch(castroKey, roster, n, sizeof(Student), studentLastNameCmp);
  str = studentToString(castro);
  printf("castro (via binary search): %s\n", str);
  free(str);

  //create a key with only the necessary fields
  castroKey = createStudent(NULL, NULL, 131313, 0.0);
  //sort according to a comparator function
  qsort(roster, n, sizeof(Student), studentIdCmp);

  castro = bsearch(castroKey, roster, n, sizeof(Student), studentIdCmp);
  str = studentToString(castro);
  printf("castro (via binary search): %s\n", str);
  free(str);

  return 0;
}
