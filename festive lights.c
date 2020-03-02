/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 3/2/2020 11:2:20 PST
*/

#include "rims.h"

/*Define user variables and functions for this state machine here.*/
unsigned char SM1_Clk;
void TimerISR() {
   SM1_Clk = 1;
}

enum SM1_States { SM1_init, SM1_s2, SM1_s4, SM1_s5, SM1_s6, SM1_s7, SM1_s3 } SM1_State;

TickFct_State_machine_1() {
   switch(SM1_State) { // Transitions
      case -1:
         SM1_State = SM1_init;
         break;
         case SM1_init: 
         if (A0) {
            SM1_State = SM1_s2;
         }
         break;
      case SM1_s2: 
         if (A0) {
            SM1_State = SM1_s3;
         }
         else if (!A0) {
            SM1_State = SM1_s6;
         }
         break;
      case SM1_s4: 
         if (A0) {
            SM1_State = SM1_s5;
         }
         else if (!A0) {
            SM1_State = SM1_s6;
         }
         break;
      case SM1_s5: 
         if (1) {
            SM1_State = SM1_s6;
         }
         break;
      case SM1_s6: 
         if (1) {
            SM1_State = SM1_s7;
         }
         break;
      case SM1_s7: 
         if (A0) {
            SM1_State = SM1_s2;
         }
         else if (!A0) {
            SM1_State = SM1_init;
         }
         break;
      case SM1_s3: 
         if (A0) {
            SM1_State = SM1_s4;
         }
         else if (!A0) {
            SM1_State = SM1_s6;
         }
         break;
      default:
         SM1_State = SM1_init;
   } // Transitions

   switch(SM1_State) { // State actions
      case SM1_init:
         B=0;
         break;
      case SM1_s2:
         B = 0x81;
         break;
      case SM1_s4:
         B =  0x24;
         break;
      case SM1_s5:
         B = 0x18;
         break;
      case SM1_s6:
         B = 0x24;
         break;
      case SM1_s7:
         B =  0x42;
         break;
      case SM1_s3:
         B = 0x42;
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}

int main() {

   const unsigned int periodState_machine_1 = 1000; // 1000 ms default
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