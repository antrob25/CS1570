//  Programmer: ANTHONY ROBLES                     Date: 4/16/19
//  File: hw9.cpp                                 Class: cs 1570 section b
//  Purpose: This program is a driver to test the functionality of the 
//  customer and business classes.

#include "customer.h"
#include "business.h"

using namespace std;

int main()
{
  srand(time(NULL));
  customer one("Bob", 150), two("Rob", 50), three("Zob", 30);
  business b("Stuff", 0);
    
  b.new_customer(one);
  b.new_customer(two);
  b.new_customer(three);

  for (int i = 0; i < 3; i++)
    b.make_a_sale();

  cout << b;

  return 0;
}
