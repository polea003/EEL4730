/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/18/2020 23:40:19 PST
*/

#include "rims.h"

char flag_g;
unsigned char TimerFlag = 0;
void TimerISR() {
   TimerFlag = 1;
}


enum SM1_States { SM1_ledOff, SM1_ledOn } SM1_State;

TickFct_led_blink() {
   /*VARIABLES MUST BE DECLARED STATIC*/
/*e.g., static int x = 0;*/
/*Define user variables for this state machine here. No functions; make them global.*/

   switch(SM1_State) { // Transitions
      case -1:
         SM1_State = SM1_ledOff;
         break;
      case SM1_ledOff:
         if (1) {
            SM1_State = SM1_ledOn;
         }
         break;
      case SM1_ledOn:
         if (1) {
            SM1_State = SM1_ledOff;
         }
         break;
      default:
         SM1_State = SM1_ledOff;
      } // Transitions

   switch(SM1_State) { // State actions
      case SM1_ledOff:
         B = 0;
         break;
      case SM1_ledOn:
         B1 = 1;
         break;
      default: // ADD default behaviour below
         break;
   } // State actions
}

enum SM2_States { SM2_setOff, SM2_setOn } SM2_State;

TickFct_temp_detect() {
   
   switch(SM2_State) { // Transitions
      case -1:
         SM2_State = SM2_setOff;
         break;
      case SM2_setOff:
         if ((A >> 4) < (A & 0x0F) ) {
            SM2_State = SM2_setOn;
         }
         break;
      case SM2_setOn:
         if ((A >> 4) >= (A & 0x0F) ) {
            SM2_State = SM2_setOff;
         }
         break;
      default:
         SM2_State = SM2_setOff;
      } // Transitions

   switch(SM2_State) { // State actions
      case SM2_setOff:
         flag_g = 0;
         break;
      case SM2_setOn:
         flag_g = 1;
         break;
      default: // ADD default behaviour below
         break;
   } // State actions
}

enum SM3_States { SM3_heatOff, SM3_heatOn } SM3_State;

TickFct_heat_on() {
   /*VARIABLES MUST BE DECLARED STATIC*/
/*e.g., static int x = 0;*/
/*Define user variables for this state machine here. No functions; make them global.*/
   switch(SM3_State) { // Transitions
      case -1:
         SM3_State = SM3_heatOff;
         break;
      case SM3_heatOff:
         if (flag_g) {
            SM3_State = SM3_heatOn;
         }
         break;
      case SM3_heatOn:
         if (!(flag_g)) {
            SM3_State = SM3_heatOff;
         }
         break;
      default:
         SM3_State = SM3_heatOff;
      } // Transitions

   switch(SM3_State) { // State actions
      case SM3_heatOff:
         B0 = 0;
         break;
      case SM3_heatOn:
         B0 = 1;
         break;
      default: // ADD default behaviour below
         break;
   } // State actions
}
int main() {
   B = 0; //Init outputs
   TimerSet(300);
   TimerOn();
   SM1_State = -1;
   SM2_State = -1;
   SM3_State = -1;
   while(1) {
      TickFct_led_blink();
      TickFct_temp_detect();
      TickFct_heat_on();
      while (!TimerFlag);
      TimerFlag = 0;
   }
}