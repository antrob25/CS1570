//  Programmer: ANTHONY ROBLES                     Date: 4/23/19
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
  const int MIN_HAP = 0;
  const int MAX_HAP = 100;
  const float ITEM_COST = 40;
  const int BUY = 15;
  const int NO_BUY = 15;
  const int HURL = 5;
  const int NO_HURL = 25;
  const int HIT = 20;
  const int STEAL = 25;
  const int NO_STEAL = 5;
  const int ROBBED = 20;
  const int HAP_LEAVE = 10;
  const int HAP_LEAVE2 = 90;

// Structs

struct product
{
  string m_name;
  float m_price;
};

// Class Definition and Functions

// The customer() function sets the calling object's m_money to a random number
// between MIN_MONEY and MAX_MONEY, sets m_happiness to a random number between 
// MAX_HAP and MIN_HAP, and sets m_pnum to 0.
// Pre: None.
// Post: The calling object has been changed.

// The customer() function sets the calling object's m_name to name,
// sets m_money to cash, and sets m_pnum to 0.
// Pre: None.
// Post: The calling object has been changed.

// The buy_something() function returns a true if the customer can buy the item
// or false if they cannot buy the item. If true, the customer's m_happiness 
// increases by BUY, m_money decreases by ITEM_COST, and the purchases is 
// outputed to the screen. If false, the customer's m_happiness decreases 
// by NO_BUY.
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

// The getInclination() function returns the calling object's m_inclination 
// to the calling function.
// Pre: None.
// Post: The calling object's m_inclination is returned to the calling function.

// The getHappiness() function returns the calling object's m_happiness to 
// the calling function.
// Pre: None.
// Post: The calling object's m_Happiness is returned to the calling function.

// The setMoney() function sets the value of the calling object's m_money to
// the value of cash.
// Pre: None.
// Post: The value of the calling object's m_money is set to the value of cash.

// The setName() function sets the value of the calling object's m_name to
// the value of name.
// Pre: None.
// Post: The value of the calling object's m_name is set to the value of name.

// The setInclination() function sets the value of the calling object's 
// m_inclination to the value of in.
// Pre: None.
// Post: The value of the calling object's m_inclination is set to the value 
// of in.

// The hurl() function returns true if the throw is successful or false if 
// it was not successful. If true, the calling object removes a random 
// product from  m_purchases, increases m_happiness by HURL and decreases 
// victim.m_happiness by HIT. If false, decreases the calling object's 
// m_happiness by NO_HURL.
// Pre: None.
// Post: True is returned if the product is thrown and false is returned 
// if the product was not thrown.

// The rob() function returns a true if the steal is successful or false if
// the steal was not successful. 
// Pre: None.
// Post: True is returned if the product is stolen and false is returned if 
// the product was not stolen.

// The isLeaving() function returns true if spr is leaving the business or 
// false if spr is not leaving the business.
// Pre: None.
// Post: True is returned if spr is leaving and false is returned if spr is 
// not leaving.

// The operator <<() function outputs the customer data on one line to the
// calling function.
// Pre: The value of one.m_pnum must be more than 0.
// Post: The customer data is outputed on one line to the calling function.

class customer
{
  private:
    product m_purchases[MAX_PURCHASES];
    short m_pnum;
    float m_money;
    string m_name;
    short m_happiness;
    short m_inclination;

  public:
    customer();
    customer(const string name, const float cash) : m_purchases(), m_pnum(0),
             m_money(cash), m_name(name), m_happiness(), m_inclination() {}
    bool buy_something(const product& one, float profit);
    string getName() const {return m_name;}
    float getMoney() const {return m_money;}
    short getInclination() const {return m_inclination;}
    short getHappiness() const {return m_happiness;}
    void setMoney(const float cash) {m_money = cash;}
    void setName(const string name) {m_name = name;}
    void setInclination(const short in) {m_inclination = in;}
    bool hurl(customer& victim, string & toss);
    bool rob(customer& victim, string & stolen);
    friend bool isLeaving(const customer& left, customer& shell, short & 
                                                              shellNum);
    friend ostream& operator <<(ostream& os, const customer& one);
};

#endif
