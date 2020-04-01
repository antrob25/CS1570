//  Programmer: ANTHONY ROBLES                     Date: 4/23/19
//  File: business.cpp                           Class: cs 1570 section b
//  Purpose: This file contains the function definitions for the funnctions
//  in the header business.h.

#include "business.h"

using namespace std;

business::business(const string n, const float m, const string t)
{
  m_name = n;
  m_cash = m;
  m_cust_num = 0;
  m_item_num = 0;
  ifstream fin;

  fin.open(t);
  for (int i = 0; i < ITEM_DATA; i++) // stores the items
  {
    fin >> m_items[i].m_price;
    fin.ignore(500,' ');
    getline(fin, m_items[i].m_name);
    m_item_num++;
  }
  fin.close();
}

void business::addCustomer(const customer& cs)
{
  if (m_cust_num < MAX_CUSTS)
  {
    m_customers[m_cust_num] = cs;
    m_cust_num++;
  }
  return;
}

void business::sell_stuff()
{
  short x;
  for (int i = 0; i < m_cust_num; i++) // runs the buy_something for customers
  {
    x = rand() % m_item_num;
    m_customers[i].buy_something(m_items[x], m_cash);
  }
  return;
}

void business::customers_leave(customer street[], short & street_num)
{
  short temp = m_cust_num;
  for (int i = 0; i < m_cust_num; i++ ) // adds customers to street
    street[i+street_num] = m_customers[i];

  m_cust_num = 0;
  street_num += temp;

  return;
}
