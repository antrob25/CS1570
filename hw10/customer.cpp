//  Programmer: ANTHONY ROBLES                     Date: 4/23/19
//  File: customer.cpp                           Class: cs 1570 section b
//  Purpose: This file contains the function definitions for the functions
//  prototypes in the header customer.h.

#include "customer.h"

using namespace std;

customer::customer()
{
  m_money = rand() % ((MAX_MONEY - MIN_MONEY)+1) + MIN_MONEY;
  m_happiness = rand() % ((MAX_HAP-MIN_HAP)+1) + MIN_HAP;
  m_pnum = 0;
}

bool customer::buy_something(const product& one, float profit)
{
  bool willbuy = rand()%2;
  bool canbuy = false;
  if (willbuy == true)
  {
    if (m_pnum < MAX_PURCHASES && m_money >= ITEM_COST)
    {
      m_purchases[m_pnum] = one;
      m_pnum++;
      m_money -= ITEM_COST;
      profit += ITEM_COST;
      m_happiness += BUY;
      canbuy = true;
      //cout << m_name << " purchases a " << one.m_name << " for $" 
           //<< one.m_price << endl << endl;
    }
    else
      m_happiness -= NO_BUY;
  }
  return canbuy;
}

ostream& operator <<(ostream& os, const customer& one)
{
  os << one.m_name << " has $" << one.m_money << " with " << one.m_happiness 
     << " happiness and has ";
  if (one.m_pnum == 0)
    os << "nothing.";
  else
  {
    for (int i = 0; i < one.m_pnum; i++) // outputs purchased items
    {
      if ((i == (one.m_pnum - 1)))
        os << "and a " << one.m_purchases[i].m_name << ".";
      else
        os << "a " << one.m_purchases[i].m_name << ", ";
    }
  }
  return os;
}

bool customer::hurl(customer& victim, string & toss)
{
  bool success = false;
  short x;
  if (m_pnum == 0)
    m_happiness -= NO_HURL;
  else
  { 
    x = rand() % m_pnum;
    toss = m_purchases[x].m_name;
    m_happiness += HURL;
    victim.m_happiness -= HIT;
    m_pnum--;
    for (int i=x; i < m_pnum; i++ )
      m_purchases[i] = m_purchases[i+1];
    success = true;
  }
  return success;
}

bool customer::rob(customer& victim, string & stolen)
{
  bool success = false;  
  short x;
  if (m_pnum < MAX_PURCHASES && victim.m_pnum > 0)
  {
    x = rand() % victim.m_pnum;
    stolen = victim.m_purchases[x].m_name;
    victim.m_happiness -= ROBBED;
    m_happiness += STEAL;
    if (m_name != victim.m_name)
    {
      m_purchases[m_pnum] = victim.m_purchases[x];
      victim.m_pnum--;
      m_pnum++;
      if (victim.m_pnum > 1)
      {
        for (int i=x; i < victim.m_pnum; i++)
          victim.m_purchases[i] = victim.m_purchases[i+1];
      }
    }
    success = true;
  }
  else
    m_happiness -= NO_STEAL;
  return success;
}

bool isLeaving(const customer& spr, customer& shell, short & shellNum)
{
  bool leaving = false;
  if (spr.m_happiness < HAP_LEAVE || spr.m_happiness >= HAP_LEAVE2)
  {
    shell = spr;
    shellNum++;
    leaving = true;
  }
  return leaving;
}
