/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/18/2020 23:51:3 PST
*/

#include "rims.h"

char flag_g;
unsigned char TimerFlag = 0;
void TimerISR() {
   TimerFlag = 1;
}


enum SM1_States { SM1_detectOff, SM1_detectOn } SM1_State;

TickFct_detect() {
   /*VARIABLES MUST BE DECLARED STATIC*/
/*e.g., static int x = 0;*/
/*Define user variables for this state machine here. No functions; make them global.*/
   switch(SM1_State) { // Transitions
      case -1:
         SM1_State = SM1_detectOff;
         break;
      case SM1_detectOff:
         if (A0) {
            SM1_State = SM1_detectOn;
         }
         break;
      case SM1_detectOn:
         if (!A0) {
            SM1_State = SM1_detectOff;
         }
         break;
      default:
         SM1_State = SM1_detectOff;
      } // Transitions

   switch(SM1_State) { // State actions
      case SM1_detectOff:
         flag_g = 0;
         break;
      case SM1_detectOn:
         flag_g = 1;
         break;
      default: // ADD default behaviour below
         break;
   } // State actions
}

enum SM2_States { SM2_ledOff, SM2_ledOn } SM2_State;

TickFct_blink() {
   /*VARIABLES MUST BE DECLARED STATIC*/
/*e.g., static int x = 0;*/
/*Define user variables for this state machine here. No functions; make them global.*/
   switch(SM2_State) { // Transitions
      case -1:
         SM2_State = SM2_ledOff;
         break;
      case SM2_ledOff:
         if (1) {
            SM2_State = SM2_ledOn;
         }
         break;
      case SM2_ledOn:
         if (1) {
            SM2_State = SM2_ledOff;
         }
         break;
      default:
         SM2_State = SM2_ledOff;
      } // Transitions

   switch(SM2_State) { // State actions
      case SM2_ledOff:
         B1 = 0;
         break;
      case SM2_ledOn:
         B1 = 1;
         break;
      default: // ADD default behaviour below
         break;
   } // State actions
}

enum SM3_States { SM3_toneOff, SM3_toneOn } SM3_State;

TickFct_tone() {
   /*VARIABLES MUST BE DECLARED STATIC*/
/*e.g., static int x = 0;*/
/*Define user variables for this state machine here. No functions; make them global.*/
   switch(SM3_State) { // Transitions
      case -1:
         SM3_State = SM3_toneOff;
         break;
      case SM3_toneOff:
         if (flag_g) {
            SM3_State = SM3_toneOn;
         }
         break;
      case SM3_toneOn:
         if (!(flag_g)) {
            SM3_State = SM3_toneOff;
         }
         break;
      default:
         SM3_State = SM3_toneOff;
      } // Transitions

   switch(SM3_State) { // State actions
      case SM3_toneOff:
         B0=0;
         break;
      case SM3_toneOn:
         B0 =1;
         break;
      default: // ADD default behaviour below
         break;
   } // State actions
}
int main() {
   B = 0; //Init outputs
   TimerSet(1000);
   TimerOn();
   SM1_State = -1;
   SM2_State = -1;
   SM3_State = -1;
   while(1) {
      TickFct_detect();
      TickFct_blink();
      TickFct_tone();
      while (!TimerFlag);
      TimerFlag = 0;
   }
}