//  Programmer: ANTHONY ROBLES                     Date: 4/16/19
//  File: customer.cpp                           Class: cs 1570 section b
//  Purpose: This file contains the function definitions for the functions
//  prototypes in the header customer.h.

#include "customer.h"

using namespace std;

customer::customer()
{
  for (int i = 0; i < MAX_PURCHASES; i++)
    m_purchases[i] = "";
  m_name = "";
  m_money = rand() % ((MAX_MONEY - MIN_MONEY)+1) + MIN_MONEY;
}

bool customer::purchase(const string item)
{
  bool canbuy = false;
  if (m_pnum < MAX_PURCHASES && m_money >= (ITEM_COST*(m_pnum + 1)))
  {
    m_purchases[m_pnum] = item;
    m_pnum++;
    canbuy = true;
  }
  return canbuy;
}

ostream& operator <<(ostream& os, const customer& one)
{
  os << one.m_name << " has $" << one.m_money << " and purchases ";
  if (one.m_pnum == 0)
    os << CANNOT_BUY  << endl;
  for (int i = 0; i < one.m_pnum; i++) // outputs purchased items
  {
    if ((i == (one.m_pnum - 1)))
      os << one.m_purchases[i] << "." << endl;
    else 
      os << one.m_purchases[i] << ", ";
  }
  return os;
}
