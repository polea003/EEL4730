/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 2/4/2020 21:53:11 PST
*/

#include "rims.h"

int timer;
unsigned char SM1_Clk;
void TimerISR() {
   SM1_Clk = 1;
}

enum SM1_States { SM1_monitor, SM1_alarm, SM1_timer } SM1_State;

TickFct_baby_monitor() {
   switch(SM1_State) { // Transitions
      case -1:
         SM1_State = SM1_monitor;
         break;
         case SM1_monitor: 
         if (!A0) {
            SM1_State = SM1_timer;
         }
         break;
      case SM1_alarm: 
         if (A1 || A0) {
            SM1_State = SM1_monitor;
         }
         break;
      case SM1_timer: 
         if (A0) {
            SM1_State = SM1_monitor;
         }
         else if (timer > 90) {
            SM1_State = SM1_alarm;
         }
         break;
      default:
         SM1_State = SM1_monitor;
   } // Transitions

   switch(SM1_State) { // State actions
      case SM1_monitor:
         timer = 0;
         B0 = 0;
         break;
      case SM1_alarm:
         B0 = 1;
         break;
      case SM1_timer:
         timer++;
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}

int main() {

   const unsigned int periodbaby_monitor = 1000; // 1000 ms default
   TimerSet(periodbaby_monitor);
   TimerOn();
   
   SM1_State = -1; // Initial state
   B = 0; // Init outputs

   while(1) {
      TickFct_baby_monitor();
      while(!SM1_Clk);
      SM1_Clk = 0;
   } // while (1)
} // Main