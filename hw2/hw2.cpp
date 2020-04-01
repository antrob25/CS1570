// Programmer: Anthony Robles                       Date: 2/4/19
// File: hw2.cpp                                   Class: cs1570 section b
// Purpose: Determines user's phone number using their height, gender and
// wavelength of eye color

#include  <iostream>

using namespace std;

int main()
{
  // Declarations

  string first_name = "Krusty"; // user's first name
  string last_name = "Clown"; // user's last name
  const short PNGF = 78; // Phone Number Gender Factor
  short wavelength = 0; // eye color wavelength of user in nanometers
  short gender = 0; // user's gender
  float height = 0; // user's height in meters
  
  // Greetings and Input

  cout<< "Welcome to Moe's Phone Service, please enter your first name" << endl;
  cin>> first_name;

  cout<< first_name << " please enter your last name" << endl;
  cin>> last_name;

  cout<< first_name <<" "<< last_name << " please enter your eye color (475 "
         "for blue, 510 for green, 590 for orange):" << endl;
  cin>> wavelength;

  cout<< first_name <<" "<< last_name << " please enter your gender (0 for "
         "male or 1 for female):" << endl;
  cin>> gender;

  cout<< first_name <<" "<< last_name << " please enter your height in meters"
  << endl;
  cin >> height; 

  // Computations

  short abc = wavelength;
  short def = static_cast<short>(height*wavelength)%1000;
  short hijk = (10*wavelength)+(PNGF*gender)+ static_cast<short>(height*height);

  // Closing and Output

  cout<< "Name:           " << first_name <<" "<< last_name << endl;

  cout<< "Phone Number:   " << abc <<"-"<< def <<"-"<< hijk << endl;

  cout<< "Have a nice day " << first_name <<" "<< last_name <<"!"<< endl;

  return 0;  
}
