//  Programmer: ANTHONY ROBLES                          Date: 2/12/19
//  File: hw3.cpp                                      Class: section b
//  Purpose: a program that serves customers alcohol if they are old enough and
//  have the money to pay for the alcohol

#include <iostream>
#include <string>

using namespace std;

int main()
{
  const float BEER_PRICE = 2.00;  // dollar price of one drink beer
  const float LIQUOR_PRICE = 4.25;  // dollar price of one drink hard liquor
  const short MIN_DRINKS = 1;
  const short MIN_AGE = 10;
  const short MIN_DRINKING_AGE = 21;
  const short MAX_AGE = 122;
  const short PATRONS = 1;
  const string BARNEY = "Barney"; // Barney is a loyal customer

  // the strings represent the choices of beverages for the customer
  const string CHOICE_ONE = "beer";
  const string CHOICE_TWO = "liquor";
  const string CHOICE_THREE = "soda";
  
  // Inputs
  string fname, ans;
  short age;
  bool teetotaler; // someone who does not drink alcohol
  float drinking_cash;  // amount of dollars the customer can spend on drinks

  // forces two decimal points to be shown
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  // Outputs
  
  short max_drinks, drinks;
  short patron_left = 1;

  do 
  {
    cout << "\t\tWelcome to Springfield's best bar Moe's bar!\n"
         << "Please enter your first name\n"
         << "  [First Name]: ";
    cin >> fname;

    if ( fname == BARNEY )
       cout << "\tC'mon in Barney\n";  // Barney is a regular

    else // prompts users that are not Barney
    {
      cout << fname << " are you a teetotaler?\n"
           << "\t0 (No)\n\t1 (Yes)\n"
           << " [Teetotaler]: ";
      cin >> teetotaler;

      if ( teetotaler == PATRONS) // handles teetotaler
         cout << "\tGET OUT OF HERE! THE BAR IS NO PLACE FOR YOU!\n";

      else // serves users who are not teetotalers 
      { 
        cout << fname << " how old are you?\n"
             << " [Age]: ";
        cin >> age;
 
        while ( age < MIN_AGE || age > MAX_AGE ) // prompts for valid age
        { 
          cout << "\tPlease enter valid age\n";
          cout << fname << " how old are you?\n"
               << " [Age]: ";
          cin >> age;
        }
        if ( age < MIN_DRINKING_AGE ) // handles underage users
        cout << "\tYOU ARE TOO YOUNG TO DRINK! GET OUT OF HERE!\n";

        else // serves age drinking users
        { 
          cout << fname << " what type of drink do want to purchase today?\n"
               << "Your choices for beverages are:\n"
               << "\t"<< CHOICE_ONE << " [" << BEER_PRICE << "]\n\t"
               << CHOICE_TWO << " [" << LIQUOR_PRICE << "]\n\t" 
               << CHOICE_THREE << "\n"
               << " [Beverage Choice]: ";
          cin >> ans;

          if ( ans == CHOICE_THREE ) // handles soda drinkers
             cout << "\tWE DONT'T SOYRV YOU SISSIES IN DIS PLACE!\n";

          else // serves alcohol drinking users
          {
            cout << fname << " how much money do you have to spend?\n"
                 << " [Spending Cash ($)]: ";
            cin >> drinking_cash;
            
            if ( ans == CHOICE_ONE ) // serves beer drinking users
            {
              max_drinks = static_cast<short>(drinking_cash/BEER_PRICE);

              if ( max_drinks < MIN_DRINKS ) // handles bum users
                 cout << "\tGET OUTTA HERE, YA BUM!\n";

              else // serves users with money
              {
                cout << fname << " you can purchase " << max_drinks                      
                     << " beers. [" << BEER_PRICE*max_drinks << "]\n"<< fname 
                     << " how many beers do you want to buy?\n"
                     << " [Number of Beers]: ";
                cin >> drinks;

                if ( drinks < max_drinks ) // handles cheap customers
                   cout << "\tCOME BACK WHEN YOU WANT TO SPEND ALL YOUR MONEY!"
                        << "\n";
                else // serves users that spend money 
                   cout << fname << " come right in, step up to the bar!\n";
              } 
            } 
            else // serves liquor drinking users
            {
              max_drinks = static_cast<short>(drinking_cash/LIQUOR_PRICE);

              if ( max_drinks < MIN_DRINKS ) // handles bum users
                 cout << "\tGET OUTTA HERE, YA BUM!\n";

              else // serves paying customers
              {
                cout << fname << " you can purchase " << max_drinks << " drinks"
                     << "[" << LIQUOR_PRICE*max_drinks << "]\n"
                     << fname << " how many drinks do you want to buy?\n"
                     << " [Number of Drinks]: ";
                cin >> drinks;

                if ( drinks < max_drinks ) // handles cheap customers
                   cout << "\tCOME BACK WHEN YOU WANT TO SPEND ALL YOUR MONEY!"
                        << "\n";
                else // serves users that spend money
                   cout << fname << " come right in, step up to the bar1\n";
              }
            }
          }
        }
      } 
    } cout << "Anyone else there?\n"
           << "\t0 (No)\n\t1 (Yes)\n";
      cin >> patron_left; 

  } while ( patron_left == PATRONS ); // prompts the interview process for user

  return 0;
}
