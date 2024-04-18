#include<stdio.h>
#include<stdlib.h>

#include "student.h"


int main(int argc, char **argv) {

  int n = 0;
  Student *roster = loadStudents("student.data", &n);
  int i;
  size_t numElems = n;

  printf("Roster: \n");
  printStudents(roster, n);

  printf("\n\n\nSorted by last name/first name: \n");
  qsort(roster, numElems, sizeof(Student), studentLastNameCmp);
  printStudents(roster, n);

  printf("\n\n\nSorted by ID: \n");
  qsort(roster, numElems, sizeof(Student), studentIdCmp);
  printStudents(roster, n);

  printf("\n\n\nSorted by ID, descending: \n");
  qsort(roster, numElems, sizeof(Student), studentIdCmpDesc);
  printStudents(roster, n);

  printf("\n\n\nSorted by GPA: \n");
  qsort(roster, numElems, sizeof(Student), studentGPACmp);
  printStudents(roster, n);

  return 0;
}
