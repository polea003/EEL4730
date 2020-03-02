/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/18/2020 13:44:43 PST
*/

#include "rims.h"

char i;
unsigned char SM1_Clk;
void TimerISR() {
   SM1_Clk = 1;
}

enum SM1_States { SM1_ledON, SM1_ledOFF } SM1_State;

TickFct_State_machine_1() {
   switch(SM1_State) { // Transitions
      case -1:
         B=0;
         i=0;
         SM1_State = SM1_ledON;
         break;
         case SM1_ledON: 
         if (i > 7) {
            SM1_State = SM1_ledOFF;
            i = 0;
         }
         break;
      case SM1_ledOFF: 
         if (i > 1) {
            SM1_State = SM1_ledON;
            i=0;
         }
         break;
      default:
         SM1_State = SM1_ledON;
   } // Transitions

   switch(SM1_State) { // State actions
      case SM1_ledON:
         B0 = 1;
         i++;
         break;
      case SM1_ledOFF:
         B0 = 0;
         i++;
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