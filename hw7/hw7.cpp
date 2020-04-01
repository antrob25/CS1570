//  Programmer: ANTHONY ROBLES                     Date: 3/23/19
//  File: hw7.cpp                                 Class: cs 1570 section b
//  Purpose: This program contains a dart game for Moe's drunk customers.

#include "hw7.h"

int main()
{
  srand(time(NULL));
  // declarations
  bool quit = false;
  char ans; // player's answer for playing again
  short beers; // number of beers consumed
  float scores[10]; // players scores
  char sounds[100]; // sounds for scores

  do
  {
    beers = get_beers();
    if (beers < MIN_BEERS)
      show_score(beers);
    else if (beers <= MAX_BEERS)
    {
      play(sounds, scores, beers);
      show_score(scores, beers);
      show_score(scores);
    }
    else
    {
      play(scores);
      show_score(scores);
    }
    cout << "Would you like to play again? (y/n)\n"
         << "[Anwser]: ";
    cin >> ans;
    if (ans == 'n')
      quit = true;
  } while (quit == false); // checks if the player still wants to play
  return 0;
}
