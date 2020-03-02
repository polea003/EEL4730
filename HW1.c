#include "rims.h"

void main()
{
    while(1){
        B0 = 0;
        if (A0 && !A1){
        B0 = 1;
        while (A0 || A1)
        B0 = 1;
        }
    }
}
