#include <iostream>

inline
double fahr2cels(double i) {
    return (i+32)*5.0/9;
}

/*
std::ostream&
operator << (std::ostream &s, t x)
{
    ...
    return s;
}
*/


int main()
{
  for(int i=0; i<50; i+=10)
    std::cout<<i<<" F = "
             <<fahr2cels(i)
             <<" C"<<std::endl;
  return 0;
}
