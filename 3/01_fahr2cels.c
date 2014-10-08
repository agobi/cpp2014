#include <stdio.h>

#define FAHR2CELS_COEFF (5/9)
#define FAHR2CELS_BIAS -32
//#define FAHR2CELS(i) (((i)-FAHR2CELS_BIAS)*FAHR2CELS_COEFF);

int main()
{
  int i;
  for(i=0; i<50; i+=10)
    printf("%d F = %d C\n", i,
            (i-FAHR2CELS_BIAS)*FAHR2CELS_COEFF);
  return 0;
}
