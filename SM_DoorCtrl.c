/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 1/28/2020 16:22:9 PST
*/

#include "rims.h"

/*Define user variables and functions for this state machine here.*/
enum SM1_States { SM1_doorClose, SM1_doorOpen } SM1_State;

TickFct_SM_DoorCtrl() {
   switch(SM1_State) { // Transitions
      case -1:
         SM1_State = SM1_doorClose;
         break;
         case SM1_doorClose: 
         if (A1 && !A0) {
            SM1_State = SM1_doorOpen;
         }
         break;
      case SM1_doorOpen: 
         if (!A0 && !A1) {
            SM1_State = SM1_doorClose;
         }
         break;
      default:
         SM1_State = SM1_doorClose;
   } // Transitions

   switch(SM1_State) { // State actions
      case SM1_doorClose:
         B0 = 0;
         break;
      case SM1_doorOpen:
         B0 = 1;
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}

int main() {

   
   SM1_State = -1; // Initial state
   B = 0; // Init outputs

   while(1) {
      TickFct_SM_DoorCtrl();} // while (1)
} // Main