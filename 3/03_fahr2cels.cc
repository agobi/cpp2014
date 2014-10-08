#include <iostream>

#define FAHR2CELS_COEFF (5.0/9)
#define FAHR2CELS_BIAS -32

int main()
{
  for(int i=0; i<50; i+=10)
    std::cout<<i<<" F = "
             <<(i-FAHR2CELS_BIAS)*FAHR2CELS_COEFF
             <<" C"<<std::endl;
  return 0;
}
