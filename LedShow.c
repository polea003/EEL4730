/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 3/1/2020 19:38:54 PST
*/

#include "rims.h"

/*This code will be shared between state machines.*/
unsigned char TimerFlag = 0;
void TimerISR() {
   TimerFlag = 1;
}


enum SM1_States { SM1_Init, SM1_LedOff, SM1_LedOn } SM1_State;

TickFct_BlinkLed() {
   /*VARIABLES MUST BE DECLARED STATIC*/
/*e.g., static int x = 0;*/
/*Define user variables for this state machine here. No functions; make them global.*/
   switch(SM1_State) { // Transitions
      case SM1_Init:
         SM1_State = SM1_LedOff;
         break;
      case SM1_LedOff:
         if (1) {
            SM1_State = SM1_LedOn;
         }
         break;
      case SM1_LedOn:
         if (1) {
            SM1_State = SM1_LedOff;
         }
         break;
      default:
         SM1_State = SM1_LedOff;
      } // Transitions

   switch(SM1_State) { // State actions
      case SM1_LedOff:
         B0=0;
         break;
      case SM1_LedOn:
         B0=1;
         break;
      default: // ADD default behaviour below
         break;
   } // State actions
}

enum SM2_States { SM2_Init, SM2_T0, SM2_T1, SM2_T2 } SM2_State;

TickFct_ThreeLeds() {
   /*VARIABLES MUST BE DECLARED STATIC*/
/*e.g., static int x = 0;*/
/*Define user variables for this state machine here. No functions; make them global.*/
   switch(SM2_State) { // Transitions
      case SM2_Init:
         SM2_State = SM2_T0;
         break;
      case SM2_T0:
         if (1) {
            SM2_State = SM2_T1;
         }
         break;
      case SM2_T1:
         if (1) {
            SM2_State = SM2_T2;
         }
         break;
      case SM2_T2:
         if (1) {
            SM2_State = SM2_T0;
         }
         break;
      default:
         SM2_State = SM2_T0;
      } // Transitions

   switch(SM2_State) { // State actions
      case SM2_T0:
         B5=1;
         B6=0;
         B7=0;
         break;
      case SM2_T1:
         B5=0;
         B6=1;
         B7=0;

         break;
      case SM2_T2:
         B5=0;
         B6=0;
         B7=1;
         break;
      default: // ADD default behaviour below
         break;
   } // State actions
}
int main() {
   B = 0; //Init outputs
   TimerSet(500);
   TimerOn();
   SM1_State = SM1_Init;
   SM2_State = SM2_Init;
   while(1) {
      TickFct_BlinkLed();
      TickFct_ThreeLeds();
      while (!TimerFlag);
      TimerFlag = 0;
   }
}
