/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 1/28/2020 16:56:36 PST
*/

#include "rims.h"

/*Define user variables and functions for this state machine here.*/
enum SM1_States { SM1_rideStop, SM1_rideStart, SM1_rideAlarm, SM1_buttonSetStart, SM1_buttonSetStop } SM1_State;

TickFct_SM_RideCtrl() {
   switch(SM1_State) { // Transitions
      case -1:
         SM1_State = SM1_rideStop;
         break;
         case SM1_rideStop: 
         if (A7 && (!A0 && !A1)) {
            SM1_State = SM1_rideStart;
         }
         break;
      case SM1_rideStart: 
         if (A0 || A1) {
            SM1_State = SM1_rideAlarm;
         }
         else if (!A7) {
            SM1_State = SM1_buttonSetStart;
         }
         break;
      case SM1_rideAlarm: 
         if (!A0 && !A1) {
            SM1_State = SM1_buttonSetStop;
         }
         break;
      case SM1_buttonSetStart: 
         if (A0 || A1) {
            SM1_State = SM1_rideAlarm;
         }
         else if (A7) {
            SM1_State = SM1_buttonSetStop;
         }
         break;
      case SM1_buttonSetStop: 
         if (!A7) {
            SM1_State = SM1_rideStop;
         }
         break;
      default:
         SM1_State = SM1_rideStop;
   } // Transitions

   switch(SM1_State) { // State actions
      case SM1_rideStop:
         B0=0;
         B1=0;
         break;
      case SM1_rideStart:
         B0=1;
         break;
      case SM1_rideAlarm:
         B1=1;
         B0 = 0;
         break;
      case SM1_buttonSetStart:
         break;
      case SM1_buttonSetStop:
         B0=0;
         B1 = 0;
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}

int main() {

   
   SM1_State = -1; // Initial state
   B = 0; // Init outputs

   while(1) {
      TickFct_SM_RideCtrl();} // while (1)
} // Main