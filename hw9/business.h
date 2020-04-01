//  Programmer: ANTHONY ROBLES                     Date: 4/16/19
//  File: business.h                           Class: cs 1570 section b
//  Purpose: This file contains the function prototypes for the funnctions
//  in the program business.cpp.

#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "customer.h"

using namespace std;

// Constants
   const int MAX_ITEMS = 10;
   const int ITEM_DATA = 7;
   const int MAX_CUSTS = 10;

// Class Definitions and Functions

// The business() function sets the calling object's m_name to an empty string, 
// m_cash to 0, and m_item_num and m_cust_num to 0.
// Pre: None.
// Post: The calling object is changed.


// The business() function sets the calling object's m_name to n, m-cash to m, 
// and m_cust_num and m_item_num to 0. The calling object's m_items[] are stored
// with 7 items from the data file shelves.txt. 
// Pre: None.
// Post: The calling object is changed.


// The operator<<() function outputs b's m_name then m_customers[] 
// and m_items[] to the caling function.
// Pre: The value of m_cust_num and m_item_num must be more than 0.
// Post: The business b is outputed to the calling function. 


// The new_customer() function adds cs to the calling object's m_customers[]. 
// Pre: None.
// Post: The calling object has cs added to m_customers[].


// The make_a_sale() function computes the sale of an item in stock to every 
// customer in the business.
// Pre: m_cust_num must be more than 0.
// Post: The item is purchased by the customers.


class business
{
  private:
    string m_name;
    float m_cash;
    string m_items[MAX_ITEMS];
    customer m_customers[MAX_CUSTS];
    short m_item_num;
    short m_cust_num;

  public:
    business() : m_name(""), m_cash(0), m_item_num(0), m_cust_num(0){}
    business(const string n, const float m); 
    friend ostream& operator <<(ostream& os, const business& b);
    void new_customer(const customer& cs);
    void make_a_sale();

}; 

#endif
