//  Programmer: ANTHONY ROBLES                     Date: 4/23/19
//  File: hw10.cpp                                 Class: cs 1570 section b
//  Purpose: This program is a driver to test the functionality of the
//  customer and business classes.

#include "customer.h"
#include "business.h"

using namespace std;

// Constants
  const int STREET_PEOPLE = 20;
  const string STORE1 = "Moe's Bar";
  const string STORE2 = "Comic Book Guy's Store";
  const string ITEMS1 = "moe_stuff.dat";
  const string ITEMS2 = "comic_stuff.dat";
  const string PEOPLE = "people.dat";
  const short MOE = -1;
  const short CBG = 1;
  const short MAX_LOOP = 20;

int main()
{
  srand(time(NULL));
  // Declarations
  business Moe_bar(STORE1, 0, ITEMS1), CBG_store(STORE2, 0, ITEMS2);
  customer street[STREET_PEOPLE], shell[STREET_PEOPLE];
  short streetNum = STREET_PEOPLE, shellNum = 0;
  ifstream fin;
  string name, stolen, hurled, winner;
  short inc, steal, hurlNum, bigHap, leaving[STREET_PEOPLE], leavingNum; 
  short counter = 0;
  bool willLeave = false, finished = false;

  // outputs two decimal places 
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  fin.open(PEOPLE);
  for (int i = 0; i < STREET_PEOPLE; i++) // assigns name and inclination
  {
    getline(fin,name,',');
    street[i].setName(name);
    fin >> inc;
    street[i].setInclination(inc);
    fin.ignore(500,'\n');
  }
  fin.close();

  for (int i = 0; i < streetNum; i++) // outputs street customers
        cout << street[i] << endl << endl;

  do
  {
    if (counter == MAX_LOOP || streetNum <=1) // checks counter
      finished = true;
    else
    {
      for (int i = 0; i < streetNum; i++) // adds customers to businesses
      {
        if (street[i].getInclination() == CBG)
          CBG_store.addCustomer(street[i]);
        else
          Moe_bar.addCustomer(street[i]);
      }
      streetNum = 0;

      Moe_bar.sell_stuff();
      CBG_store.sell_stuff();

      Moe_bar.customers_leave(street, streetNum);
      CBG_store.customers_leave(street, streetNum);

      for (int i = 0; i < streetNum; i++) // runs interactions
      {
        steal = rand() % streetNum;
        hurlNum = rand() % streetNum;
        if ( street[i].getInclination() == street[steal].getInclination())
        {
          if ((street[i].rob(street[steal], stolen)) == true)
          {
            cout << street[i].getName() << " steals a " << stolen << " from " 
                 << street[steal].getName() << endl << endl;
          }
        }  
        else
        {  
          if((street[i].hurl(street[hurlNum], hurled)) == true)
          {
            cout << street[i].getName() << " throws a " << hurled << " at "
                 << street[hurlNum].getName() << endl << endl;
          }
        }
      } 

      leavingNum = 0;
      for (int i = 0; i < streetNum; i++) // checks the leaving customers
      {
        willLeave = isLeaving(street[i], shell[i], shellNum);
        if (willLeave == true)
        {
          leaving[leavingNum] = i;
          leavingNum++;
        }
      }

      for (int i = 0; i < leavingNum; i++) // removes leaving customers
      {
        for (int j = 0; j < streetNum; j++)
        {
          if (j == leaving[i])
          {
            for (int l = j; l < streetNum-1; l++)
              street[l] = street[l+1];
          }
        }
        streetNum--;         
      }

      //for (int i = 0; i < streetNum; i++) // outputs customers
        //cout << street[i] << endl << endl;

      counter++;
    }
  } while (finished == false); // loops the interactions and shopping

  bigHap = shell[0].getHappiness();
  winner = shell[0].getName();   
  for (int i = 1; i < shellNum; i++) // checks shell for happiness
  {
    if (shell[i].getHappiness() > bigHap)
    {
      bigHap = shell[i].getHappiness();
      winner = shell[i].getName();
    }
  }  
  for (int i = 0; i < streetNum; i++) // checks street for happiness
  {
    if (street[i].getHappiness() > bigHap)
    {
      bigHap = street[i].getHappiness();
      winner = street[i].getName();
    }
  }
  cout << winner << " is the winner of Springfield store wars with " << bigHap 
       << " happiness!" << endl;

  return 0;
}
