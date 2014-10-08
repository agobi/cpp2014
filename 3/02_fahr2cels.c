#include <stdio.h>

#define FAHR2CELS_COEFF (5.0/9)
#define FAHR2CELS_BIAS -32

int main()
{
  int i;
  for(i=0; i<50; i+=10)
    printf("%d F = %f C\n", i,
            (i-FAHR2CELS_BIAS)*FAHR2CELS_COEFF);
  return 0;
}
