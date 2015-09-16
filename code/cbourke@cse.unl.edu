#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<errno.h>

int main(int argc, char **argv) {

  double a = -1, b = 2, c = 0.0;
  double x;

  //okay
  x = sqrt(b);
  printf("result: %.4f, error: %d\n", x, errno);

  //NaN and EDOM error...
  x = sqrt(a);
  printf("result: %.4f, error: %d\n", x, errno);

  //make a comparison
  if(errno == EDOM) {
    printf("it was an EDOM error\n");
  }

  //error messages can be accessed via:
  char *errMsg = strerror(errno);
  printf("Error Message: %s\n", errMsg);

  //ERANGE error
  x = log(c);
  printf("result: %.4f, error: %d\n", x, errno);

  if (errno == ERANGE) {
    printf("it was an ERANGE error\n");
  }

  //error messages can be accessed via:
  errMsg = strerror(errno);
  printf("Error Message: %s\n", errMsg);

  return 0;

}
