#include<stdio.h>
#include<stdlib.h>

int function01(int a, double b);
void function02(double x, char y);

void runAFunction(int (*theFunc)(int, double));

int main(int argc, char **arg) {

  int i = 5;
  double d = 3.14;
  char c = 'Q';

  //calling a function normally...
  int j = function01(i, d);
  function02(d, c);

  //function pointer declaration
  int (*pt2Func01)(int, double) = NULL;
  void (*pt2Func02)(double, char) = NULL;

  //assignment
  pt2Func01 = function01;  
  //or: 
  pt2Func01 = &function01;
  pt2Func02 = &function02;

  //you can invoke a function using a pointer to it:
  j = pt2Func01(i, d);
  pt2Func02(d, c);

  //alternatively, you can invoke a function by dereferencing it:
  j = (*pt2Func01)(i, d);
  (*pt2Func02)(d, c);

  //With function pointers, you can now pass entire functions as arguments to another function!
  printf("Calling runAFunction...\n");
  runAFunction(pt2Func01);
  //we should not pass in the second pointer as it would not match the signature:
  //syntactically okay, compiler warning, undefined behavior
  //runAFunction(pt2Func02);
}

void runAFunction(int (*theFunc)(int, double)) {

  printf("calling within runAfunction...\n");
  int result = theFunc(20, .5);
  printf("the result was %d\n", result);

  return;
}

int function01(int a, double b) {
  printf("You called function01 on a = %d, b = %f\n", a, b);
  return a + 10;
}

void function02(double x, char y) {

  printf("You called function02 on x = %f, y = %c\n", x, y);

}
