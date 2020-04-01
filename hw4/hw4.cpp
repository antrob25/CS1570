//  Programmer: ANTHONY ROBLES                     Date: 2/24/19
//  File: hw4.cpp                                 Class: cs 1570 section b
//  Purpose: This file contains the main function for the gambling machine
//  in Moe's bar.

#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{
  srand(67);
  // Declarations
  const short BALANCE_RANGE = 1001;
  const short NUMBER_RANGE = 5;
  const float MONEY_WON_3 = 30;
  const float MONEY_LOSS = 5;
  const float NO_MONEY = 0.00;
  const float BET_MONEY = 5.00;
  const short CHECK_1 = 1;
  const short CHECK_2 = 2; 
  float g_balance = 0.00;   // game balance in dollars
  float b_balance = (rand()%BALANCE_RANGE);   // sets starting balance
  float funds_trans;   // amount of funds transfered to game balance 
  short choice, num_1, num_2, num_3;
  short step_1 = 5;
  short step_2 = 5;
  bool quit = false;

  // Menu Screen
  cout<<"\tHello!"<<endl;
  do 
  {
    cout<<"Please choose one of the following options (1-4)\n"
        <<"1. Check Bankk balance\n"
        <<"2. Transfer funds to game\n"
        <<"3. Play\n"
        <<"4. Leave\n"
        <<"What would you like to do?: ";
    cin>>choice; 

    if (b_balance == NO_MONEY && g_balance == NO_MONEY) // forces user to leave
    {
       cout<<"You have no more money leave the machine!\n";
       quit = true;
    }  
    switch (choice)  // Outputs options from menu
    {
      case 1:
            cout<<"Your Bankk balance is "<<b_balance<<endl;
            step_1 = CHECK_1;
            break;

      case 2:
            if (!(step_1 == CHECK_1))  // makes the user check balance first
               cout<<"Please check your bankk balance first\n";
            else
            {
              cout<<"How much money would you like to transfer?\n"
                  <<" [Funds Transfered]: ";
              cin>>funds_trans;

              if (funds_trans > b_balance)
                 cout<<"You can not exceed your balance!\n";
              else 
              {
                b_balance = b_balance - funds_trans;
                g_balance = g_balance + funds_trans;

                cout<<"You have transfered $"<<funds_trans<<" to your game "
                    <<"balance for a total game balance of $"<<g_balance<<endl;
                step_2 = CHECK_2;
              }
            }
            break;

      case 3:
            if (!(step_2 == CHECK_2))  // makes the user add funds first
               cout<<"Please add funds to your game balance\n";
            else
            {
              if (g_balance <= NO_MONEY || g_balance < BET_MONEY)
                 cout<<"Please add more funds to your game balance\n";
              else
              {
                num_1 = (rand()%NUMBER_RANGE);
                num_2 = (rand()%NUMBER_RANGE);
                num_3 = (rand()%NUMBER_RANGE);

                cout<<num_1<<" "<<num_2<<" "<<num_3<<endl;

                if (num_1 == num_2 && num_2 == num_3)
                {
                   g_balance+=MONEY_WON_3;
                   cout<<"Your game balance has increases by $30!\n";
                }
                else
                {
                  if (num_1 == num_2 || num_1 == num_3 || num_2 == num_3)
                  { 
                     g_balance++;
                     cout<<"Your game balance has increased by $1!\n";
                  }
                  else
                  {
                     g_balance-=MONEY_LOSS;
                     cout<<"Your game balance has lowered by $5!\n";
                  }
                }
              }
            }
            break;

      case 4:
            cout<<"Your game balance is "<<g_balance<<" and your bankk balance "
                <<"is "<<b_balance<<endl
                <<"Have a nice day!\n";
            quit = true;
            break;

      default:
             cout<<"Please choose a valid choice."<<endl;
           
    }
  } while (quit == false); // exits program after user inputs quit

  return 0;
}
