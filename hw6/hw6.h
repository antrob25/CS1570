//  Programmer: ANTHONY ROBLES                     Date: 3/10/19
//  File: hw6.h                                 Class: cs 1570 section b
//  Purpose: This file contains the constants and prototypes for the functions
//  in the program hw6.cpp.

#ifndef HW6_H
#define HW6_H
#include <iostream>

using namespace std;

// Global Constants
  const float NO_MONEY = 0.00; // dollar amount needed to be removed from game
  const float BET_MONEY = 5.00; // amount of potential dollar loss from spin
  const short CHECK_1 = 1; // check for checking balance
  const short CHECK_2 = 2; // check for transfering money
  const short BALANCE_MAX_RANGE = 801; // maximum balance assigned
  const short BALANCE_MIN_RANGE = 200; // minimum balance assigned
  const short NUMBER_MAX_RANGE = 4; // maximum number generated for spin
  const short NUMBER_MIN_RANGE = 1; // minimum number generated for spin
  const short MIN_SPIN = 1; // minimum spin number
  const float NO_PAIR = 5; // dollar amount lost for no match
  const float THREE_KIND = 30; // dollar amount won for three of a kind
  const short CHEAT_START = 5; // amount of rounds passed to activate cheat

// Structures

struct slot_machine // variable for slot machine values
{
  float m_g_balance; // game balance
  char m_letter1; // first letter  for machine
  char m_letter2; // second letter for machine
  char m_letter3; // third letter for machine
  float m_net_gain; // net gain of player
  float m_money_won; // money gained by player
  float m_money_lost; // money lost by player
};

  
// Prototypes

// The char menu() function outputs a menu to the screen and returns a
// char representing the option chosen.
// Pre: None.
// Post: The menu is outputed to the screen and the char is returned.
char menu();
  
// The void balance_check() function outputs the bankk balance to the screen
// and passes the value of the short to the calling functions.
// Pre: None.
// Post: The bankk balance is outputed to the screen and the value of the short
// is passed back to the calling function.
void balance_check(const float balance, short & first_step);
  
// The get_letter() function computes the value of the char and passes the 
// value to the calling function.
// Pre: None.
// Post: The value of the char is passed to the calling function. 
void get_letter(const short number, char & letter);
  
// The get_letter() funcntion computes the values of the chars to ensure the 
// values do not match and passes the values to the calling funcntion.
// Pre: None.
// Post: The value of the char is passed to the calling function.
void get_letter(short numb1, short numb2, const char letter1, char & letter2, 
                                                              char & letter3);
  
// The void transfer() function computes the transfer of money from the bankk
// balance to the game balance, outputs the result to the screen and the value
// of the result is passed to the calling function..
// Pre: None.
// Post: The transfer is computed, the result is outputed to the screen and the
// value of the result is passed to the calling function.
void transfer(const short step_1_check, float & bankk, float & game, short & 
                                                              step_2_check);
															  
// The void spin() function outputs the slot machine results to the
// screen and passes the value of the float to the caling function.
// Pre: None.			  
// Post: The results are outputed to the screen and the value of the float is
// passed to the calling function.			  		  
  void spin(slot_machine & no_cheat, const short spin);		  
			  
// The void play() function outputs a prompt for the amount of spins that is 
// requested by the player and check if the player has money for the spin.
// Pre: None.
// Post: The prompt is outputed and the spin amount is recorded.	  
  void play(const short step_2nd, slot_machine & normal);
  
// The void show_balance() function outputs the bankk balance and game balance
// to the screen. The function also passes the value of a bool back to the
// calling function.
// Pre: None.
// Post: The bankk balance and game balance are outputed to the screen and the
// value of the bool is passed to the calling function.
   void show_balance(const float game_bal, const float bankk_bal, bool & quit);
  
#endif
