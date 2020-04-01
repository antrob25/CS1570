//  Programmer: ANTHONY ROBLES                     Date: 4/16/19
//  File: customer.h                           Class: cs 1570 section b
//  Purpose: This file contains the function prototypes for the functions
//  in the program customers.cpp.

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <cstdlib>
 
using namespace std;

// Constants
  const int MAX_PURCHASES = 20;
  const int MIN_MONEY = 4;
  const int MAX_MONEY = 250;
  const float ITEM_COST = 40;
  const string CANNOT_BUY = "nothing.";

// Class Definition and Functions

// The customer() function sets the calling object's m_purchases[] to blank 
// strings, sets m_name to an empty string, and sets m_money to a random number 
// between MIN_MONEY and MAX_MONEY. 
// Pre: None.
// Post: The calling object has been changed.

// The customer() function sets the calling object's m_name to name, 
// sets m_money to cash, and sets m_pnum to 0.
// Pre: None.
// Post: The calling object has been changed.

// The purchase() function returns a true if the customer can buy the item 
// or false if they cannot buy the item.
// Pre: None.
// Post: True is returned to the calling function if the item is bought or 
// false if they could not buy it.

// The getName() function returns the calling object's m_name to the calling 
// function.
// Pre: None.
// Post: The calling object's m_name is returned to the calling function.

// The getMoney() function returns the calling object's m_money to the calling
// function.
// Pre: None.
// Post: The calling object's m_money is returned to the calling function.

// The setMoney() function sets the value of the calling object's m_money to 
// the value of cash.
// Pre: None.
// Post: The value of the calling object's m_money is set to the value of cash.

// The operator <<() function outputs the customer data on one line to the 
// calling function.
// Pre: The value of one.m_pnum must be more than 0.
// Post: The customer data is outputed on one line to the calling function. 

class customer
{
  private:
    string m_purchases[MAX_PURCHASES];
    short m_pnum;
    float m_money;
    string m_name;

  public: 
    customer(); 
    customer(const string name, const float cash) : m_name(name), 
             m_money(cash), m_pnum(0){}
    bool purchase(const string item);
    string getName() const {return m_name;}
    float getMoney() const {return m_money;}
    void setMoney(const float cash) {m_money = cash;}
    friend ostream& operator <<(ostream& os, const customer& one);

};

#endif
