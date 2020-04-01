//  Programmer: ANTHONY ROBLES                     Date: 3/10/19
//  File: hw6_funct.cpp                           Class: cs 1570 section b
//  Purpose: This file contains the function definitions for the funnctions
//  in the program hw6.cpp.

#include <iostream>
#include <cstdlib>
#include "hw6.h"

using namespace std;

char menu()
{
  char option;

  cout<<"Please choose one of the following options (1-4)\n"
        <<"1. Check Bankk balance\n"
        <<"2. Transfer funds to game\n"
        <<"3. Play\n"
        <<"4. Leave\n"
        <<"What would you like to do?: ";
  cin>>option;

  return option;
}

void balance_check(const float balance, short & first_step)
{
  cout<<"Your Bankk balance is "<<balance<<endl;

  first_step = CHECK_1; // confirms balance check	

  return;	
}

void transfer(const short step_1_check, float & bankk, float & game, 
              short & step_2_check)
{
  float funds_trans;
  
  if (!(step_1_check == CHECK_1))  // makes the user check balance first
      cout<<"Please check your bankk balance first\n";
  else
  {
    cout<<"How much money would you like to transfer?\n"
        <<" [Funds Transfered]: ";
    cin>>funds_trans;

    if (funds_trans > bankk) // stops user from taking more than available
        cout<<"You can not exceed your balance!\n";
    else
    {
      bankk = bankk - funds_trans;
      game = game + funds_trans;

      cout<<"You have transfered $"<<funds_trans<<" to your game "
          <<"balance for a total game balance of $"<<game<<endl;
	  step_2_check = CHECK_2; // confirms transfer
    }
  }	
  return;	
}

void get_letter(const short number, char & letter)
{
  if (number == 1)
    letter = 'A';
  else 
  {
    if (number == 2)
      letter = 'B';
    else 
    {
      if (number == 3)
        letter = 'C';
      else 
        letter = 'D';		  
	}
  }		
  return;	
}

void get_letter(short numb1, short numb2, const char letter1, char & letter2, 
                                                              char & letter3)
{
  srand(67);
  
  get_letter(numb1, letter2);
  get_letter(numb2, letter3);
  
  while (letter2 == letter1) // loops until different letter
  {
    numb1 = (rand()%NUMBER_MAX_RANGE)+NUMBER_MIN_RANGE;
    get_letter(numb1, letter2);	
  }
  while (letter3 == letter1 || letter3 == letter2) // loops until different
  {
    numb2 = (rand()%NUMBER_MAX_RANGE)+NUMBER_MIN_RANGE;
    get_letter(numb2, letter3);
  }	  
  return;	
}

void spin(slot_machine & no_cheat, const short spin)
{
  srand(67);

  short num_1, num_2, num_3;
  
  for (short i = 1; i<= spin; i++) // loops spin amount
  {	
    num_1 = (rand()%NUMBER_MAX_RANGE)+NUMBER_MIN_RANGE;
    num_2 = (rand()%NUMBER_MAX_RANGE)+NUMBER_MIN_RANGE;
    num_3 = (rand()%NUMBER_MAX_RANGE)+NUMBER_MIN_RANGE;
	
    if (i > CHEAT_START && no_cheat.m_net_gain > NO_MONEY) // loops cheat spin 
    {
      get_letter(num_1, no_cheat.m_letter1);
      get_letter(num_2, num_3, no_cheat.m_letter1, no_cheat.m_letter2, 
                                                  no_cheat.m_letter3);
    }
    else
    { 
      get_letter(num_1, no_cheat.m_letter1);
      get_letter(num_2, no_cheat.m_letter2);
      get_letter(num_3, no_cheat.m_letter3);
    }
	  
    cout<<no_cheat.m_letter1<<" "<<no_cheat.m_letter2<<" "<<no_cheat.m_letter3
        <<endl;

    if (no_cheat.m_letter1 == no_cheat.m_letter2 && no_cheat.m_letter2 == 
	                                               no_cheat.m_letter3)
    {
      no_cheat.m_g_balance+=THREE_KIND;
      no_cheat.m_money_won+=THREE_KIND;
      cout<<"Your game balance has increases by $30!\n";
    }
    else
    {
      if (no_cheat.m_letter1 == no_cheat.m_letter2 || no_cheat.m_letter1 ==
    	  no_cheat.m_letter3 || no_cheat.m_letter2 == no_cheat.m_letter3)
      {
        no_cheat.m_g_balance++;
        no_cheat.m_money_won++;
        cout<<"Your game balance has increased by $1!\n";
      }
      else
      {
        no_cheat.m_g_balance-=NO_PAIR;
        no_cheat.m_money_lost+=NO_PAIR;
        cout<<"Your game balance has lowered by $5!\n";
      }
    }
    no_cheat.m_net_gain = no_cheat.m_money_won - no_cheat.m_money_lost; 
    // dollar net gain of user
  }
}

void play(const short step_2nd, slot_machine & normal)
{
  short spin_num; 

  if (!(step_2nd == CHECK_2))  // makes the user add funds first
      cout<<"Please add funds to your game balance\n";
	  
  else
  {
    if (normal.m_g_balance < BET_MONEY) // ensures user can take pontential
                                        // dollar loss
      cout<<"Please add more funds to your game balance\n";
		
    else
    {
      cout<<"\tHow many times do you want to spin?\n"
          <<"[Spin Number]: ";
      cin>>spin_num;
	  
      if (spin_num < MIN_SPIN) // forces user to spin the appropriate amount
        cout<<"\tPlease enter a valid number of spins.\n";
		
      else 
      {	
        if (normal.m_g_balance < (BET_MONEY*spin_num)) // ensures user can take
                                                      // pontential dollar loss
          cout<<"Please add more funds to your game balance\n";
		  
        else
          spin(normal, spin_num);
      }
    }
  }
  return;			
}

void show_balance(const float game_bal, const float bankk_bal, bool & quit)
{
  cout<<"Your game balance is "<<game_bal<<" and your bankk balance "
      <<"is "<<bankk_bal<<endl;

  quit = true;	

  return;	
}
