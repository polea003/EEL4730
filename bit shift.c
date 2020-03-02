/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/18/2020 8:21:13 PST
*/

#include "rims.h"

char cnt;
unsigned char SM1_Clk;
void TimerISR() {
   SM1_Clk = 1;
}

enum SM1_States { SM1_init, SM1_off, SM1_blinkOn, SM1_shiftUp, SM1_blinkOff, SM1_shiftDown } SM1_State;

TickFct_State_machine_1() {
   switch(SM1_State) { // Transitions
      case -1:
         SM1_State = SM1_init;
         break;
         case SM1_init: 
         if (1) {
            SM1_State = SM1_off;
         }
         break;
      case SM1_off: 
         if (A0) {
            SM1_State = SM1_blinkOn;
            cnt = 0;
         }
         break;
      case SM1_blinkOn: 
         if (A0 && A1) {
            SM1_State = SM1_shiftUp;
            B = 0x01;
            cnt = 0;
         }
         else if ((A0 && !A1) && (cnt  > 9)) {
            SM1_State = SM1_blinkOff;
            cnt = 0;
         }
         else if (!A0) {
            SM1_State = SM1_off;
         }
         break;
      case SM1_shiftUp: 
         if ((A0 && A1) && (cnt > 7)) {
            SM1_State = SM1_shiftDown;
            cnt = 1;
         }
         else if (A0 && !A1) {
            SM1_State = SM1_blinkOn;
            cnt = 0;
         }
         break;
      case SM1_blinkOff: 
         if ((A0 && !A1) && (cnt > 9)) {
            SM1_State = SM1_blinkOn;
            cnt = 0;
         }
         else if (A0 && A1) {
            SM1_State = SM1_shiftUp;
            B = 0x01;
            cnt = 0;
         }
         else if (!A0) {
            SM1_State = SM1_off;
         }
         break;
      case SM1_shiftDown: 
         if ((A1 && A0) && (cnt  > 6)) {
            SM1_State = SM1_shiftUp;
            cnt = 0;
         }
         else if (!A0) {
            SM1_State = SM1_off;
         }
         else if (A0 && !A1) {
            SM1_State = SM1_blinkOn;
         }
         break;
      default:
         SM1_State = SM1_init;
   } // Transitions

   switch(SM1_State) { // State actions
      case SM1_init:
         break;
      case SM1_off:
         B = 0;
         break;
      case SM1_blinkOn:
         B = 0xFF;
         cnt++;
         break;
      case SM1_shiftUp:
         B = 0x01;
         B = B << cnt;
         cnt++;
         break;
      case SM1_blinkOff:
         B = 0x00;
         cnt++;
         break;
      case SM1_shiftDown:
         B = 0x80;
         B = B >> cnt;
         cnt++;
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}

int main() {

   const unsigned int periodState_machine_1 = 100;
   TimerSet(periodState_machine_1);
   TimerOn();
   
   SM1_State = -1; // Initial state
   B = 0; // Init outputs

   while(1) {
      TickFct_State_machine_1();
      while(!SM1_Clk);
      SM1_Clk = 0;
   } // while (1)
} // Main