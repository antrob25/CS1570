//  Programmer: ANTHONY ROBLES                       Date: 2/26/19
//  File: hw6.cpp                                   class: section b 
//  Purpose: This program add, divides, and simplifies two fractions.

#include<iostream>

using namespace std;

// The greeting() function outputs a greeting to the screen.
// Pre: None.
// Post: Greeting is outputed to the screen.
void greeting();

// The goodbye() function outputs a goodbye to the screen. 
// Pre: None.
// Post: Goodbye is outputed the screen.
void goodbye();

// The menu() function outputs a menu to the screen and return a character type
// for that menu.
// Pre: None.
// Post: Returns character representing menu choice.
char menu();

// The get_fract() function outputs a prompt to the screen to store a fraction.
// Pre: None.
// Post: The fraction value is passed to the calling fuction.
void get_fract(short & numer, short & denom);

// The show_fract() function outputs the fraction to the screen.
// Pre: None.
// Post: Outputs fraction to the screen.
void show_fract(const short numer, const short denom);

// The add_fract() function computes the sum of the two fractions and passes
// the value to the calling function..
// Pre: None.
// Post: The value of the sum is passed to the calling function. 
void add_fract(const short num1, const short den1, const short num2,
               const short den2, short & a_num, short & a_den);

// The divide_fract() function computes the quotient of the two fractions and 
// passes the value to the calling function.
// Pre: None.
// Post: The value of the quotient is passed to the calling function. 
void divide_fract(const short num1, const short den1, const short num2,
                  const short den2, short & d_num, short & d_den);

// The simplify_fract() function computes the fractions simplified form and
// passed the value to the calling function.
// Pre: None.
// Post: The value of the simplified fraction is passed to the calling function.
void simplify_fract(short & numer, short & denom);

int main()
{
  // declarations
  bool quit = false, fract = false; // fract checks for entered fractions
  char choice;
  short numer1, denom1, numer2, denom2, d_numer, d_denom, a_numer, a_denom;
  // d_numer is divided numerator, d_denom is divided denominator, a_numer is
  // added numerator and a_denom is added denominator. 

  greeting();

  do // loops menu
  {
    choice = menu();

    switch (choice) 
    {
      case '1':
            get_fract(numer1, denom1);
            get_fract(numer2, denom2);
            fract = true;
            break;
      case '2':
            if (fract == true)
            {
               add_fract(numer1, denom1, numer2, denom2, a_numer, a_denom);
               simplify_fract(a_numer, a_denom);
               show_fract(a_numer, a_denom);
            }
            else 
              cout<<"Please enter fractions first.\n";
            break;
      case '3':
            if (fract == true)
            {
               divide_fract(numer1, denom1, numer2, denom2, d_numer, d_denom);
               simplify_fract(d_numer, d_denom);
               show_fract(d_numer, d_denom);
            }
            else 
               cout<<"Please enter fractions first.\n";
            break;
      case '4':
            if (fract == true)
            {
               simplify_fract(numer1, denom1);
               simplify_fract(numer2, denom2);
               show_fract(numer1, denom1);
               show_fract(numer2, denom2);
            }
            else
               cout<<"Please enter fractions first.\n";
            break;
      case '5':
            quit = true;
            break;
      default:
            cout<<"Please enter a valid choice\n";
    }	
  } while (quit == false); // quits the program when the user is finished

  goodbye();
		
  return 0;	
}	
void greeting()
{
  cout<<"Hello!\n";
  return;
}
void goodbye()
{
  cout<<"Goodbye!\n";
  return;
}
char menu()
{
  char choice;
  cout<<"\tMenu\n"
      <<"Please choose an option (1-5):\n"
	  <<"1. Enter Fractions\n"
	  <<"2. Add Fractions\n"
	  <<"3. Divide Fractions\n"
	  <<"4. Display Simplified Fractions\n"
	  <<"5. Quit\n"
	  <<"[Choice]: ";
  cin>>choice;  
  return choice;
}

void get_fract(short & numer, short & denom)
{
  cout<<"Please enter a numerator for the fraction.\n"
      <<"[Numerator]: ";
  cin>>numer;
  cout<<"Please enter a denominator for the fraction.\n"
      <<"[Denominator]: ";
  cin>>denom;
  return;
}	
  
void show_fract(const short numer, const short denom)
{
  cout<<numer<<"/"<<denom<<endl;
  return; 
}
  
void add_fract(const short num1, const short den1, const short num2,
               const short den2, short & a_num, short & a_den)
{
  short temp_num1, temp_num2;
  a_den = den1 * den2;
  temp_num1 = num1 * den2; 
  temp_num2 = num2 * den1;
  a_num = temp_num1 + temp_num2;
  return;
}

void divide_fract(const short num1, const short den1, const short num2,
                  const short den2, short & d_num, short & d_den)
{
  d_num = num1 * den2;
  d_den = den1 * num2;
  return;	
}
  
void simplify_fract(short & numer, short & denom)
{
  // declarations 
  short big, small, ans, gcd, s_numer, s_denom;//gcd is greatest common divisor 
  big = denom;
  small = numer;

  do
  {
    ans = big % small;
    if (!(ans == 0))
    {
       big = small;
       small = ans;
    }
    else
       gcd = small;
  } while (!(ans == 0)); // loops until the greatest common divisor is found

  s_numer = numer/gcd; // s_numer is simplified numerator
  s_denom = denom/gcd; // s_denom is simplified denominator
  numer = s_numer;
  denom = s_denom;

  return;	
}
  
  
  
  
  
  
  
