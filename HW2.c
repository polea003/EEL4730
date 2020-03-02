#include "rims.h"

void main()
{
    char ASnap, A5A4, A3A2, A1A0, Sum;

      ASnap = A;
      A5A4 = (ASnap >> 4) & 0x03;
      A3A2 = (ASnap >> 2) & 0x03;
      A1A0 =  ASnap & 0x03;
      Sum = A5A4 + A3A2 + A1A0;
      printf("%d", Sum);
   
}
