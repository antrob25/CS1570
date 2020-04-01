//  Programmer: ANTHONY ROBLES                     Date: 4/16/19
//  File: business.cpp                           Class: cs 1570 section b
//  Purpose: This file contains the function definitions for the funnctions
//  in the header business.h.

#include "business.h"

using namespace std;

business::business(const string n, const float m)
{
  m_name = n;
  m_cash = m;
  m_cust_num = 0;
  m_item_num = 0;
  ifstream fin;

  fin.open("shelves.txt");
  for (int i = 0; i < ITEM_DATA; i++) // stores the items 
  {
    fin >> m_items[i];
    m_item_num++;
  }
  fin.close();
}

ostream& operator <<(ostream& os, const business& b)
{
  os << b.m_name << endl;

  for (int i = 0; i < b.m_cust_num; i++) // outputs customers
    os << b.m_customers[i];

  os << "These are the items in stock: ";
  for (int i = 0; i < b.m_item_num; i++) // outputs items in stock
  {
   if ((i == (b.m_item_num -1)))
     os << b.m_items[i] << "." << endl;
   else
     os << b.m_items[i] << ", ";
  }

  return os;
}

void business::new_customer(const customer& cs)
{
  if (m_cust_num < MAX_CUSTS)
  {
    m_customers[m_cust_num] = cs;
    m_cust_num++;
  } 
  return;
}

void business::make_a_sale()
{
  int x;
  for (int i = 0; i < m_cust_num; i++)
  {
    x = rand() % m_item_num;
    m_customers[i].purchase(m_items[x]);
  }
  return;
}
