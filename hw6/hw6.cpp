//  Programmer: ANTHONY ROBLES                     Date: 3/10/19
//  File: hw6.cpp                                 Class: cs 1570 section b
//  Purpose: This file contains the main function for the gambling machine
//  in Moe's bar.

#include <iostream>
#include <cstdlib>
#include "hw6.h"

using namespace std;

int main ()
{
  srand(67);

  // Declarations
  char choice; // menu option
  // sets starting balance
  float b_balance = (rand()%BALANCE_MAX_RANGE)+BALANCE_MIN_RANGE;
  short step_1 = 5; // checks for balance check
  short step_2 = 5; // checks for money transfer
  slot_machine player; // variable for game blance and slot letters
  bool quit = false;
  player.m_g_balance = 0.00; // sets game balance to 0

  // Greeting
  cout<<"\tHello!"<<endl;
  do
  {
    choice = menu();

    if (b_balance == NO_MONEY && player.m_g_balance == NO_MONEY) // forces user to leave
    {
       cout<<"You have no more money leave the machine!\n";
       quit = true;
    }
    switch (choice)  // Outputs options from menu
    {
      case '1':
            balance_check(b_balance, step_1);
            break;

      case '2':
            transfer(step_1, b_balance, player.m_g_balance, step_2);
            break;

      case '3':
            play(step_2, player);
            break;

      case '4':
            show_balance(player.m_g_balance, b_balance, quit);
            break;

      default:
             cout<<"Please choose a valid choice."<<endl;

    }
  } while (quit == false); // exits program after quit is true

  // Goodbye
  cout<<"\tHave a nice day!"<<endl;

  return 0;
}
