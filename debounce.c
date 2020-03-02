/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/18/2020 23:13:18 PST
*/

#include "rims.h"

char i;
unsigned char SM1_Clk;
void TimerISR() {
   SM1_Clk = 1;
}

enum SM1_States { SM1_off, SM1_filter, SM1_on } SM1_State;

TickFct_State_machine_1() {
   switch(SM1_State) { // Transitions
      case -1:
         SM1_State = SM1_off;
         break;
         case SM1_off: 
         if (A1) {
            SM1_State = SM1_filter;
            i = 0;
         }
         break;
      case SM1_filter: 
         if (A1 && (i >2)) {
            SM1_State = SM1_on;
            i = 0;
         }
         else if (!A1) {
            SM1_State = SM1_off;
         }
         break;
      case SM1_on: 
         if (!A1) {
            SM1_State = SM1_off;
         }
         break;
      default:
         SM1_State = SM1_off;
   } // Transitions

   switch(SM1_State) { // State actions
      case SM1_off:
         B=0;
         break;
      case SM1_filter:
         i++;
         break;
      case SM1_on:
         B1 =1;
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}

int main() {

   const unsigned int periodState_machine_1 = 50;
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