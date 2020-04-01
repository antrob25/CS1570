//  Programmer: ANTHONY ROBLES                     Date: 3/23/19
//  File: hw7.h                                 Class: cs 1570 section b
//  Purpose: This program contains a dart game for Moe's drunk customers.

#ifndef HW7_H
#define HW7_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

// Global Constants

const short MIN_BEERS = 2;
const short MAX_BEERS = 12;
const short MIN_ANGLE = -2;
const short MAX_ANGLE = 2;
const float NUM_SHOTS = 10;
const float PI = 3.14159;
const float DISTANCE_AWAY = 11;
const short RING_1 = 1;
const short RING_2 = 2;
const short RING_3 = 3;
const short RING_4 = 4;
const short RING_5 = 6;

// Prototypes

// The get_beers() function prompts for an amount of beers and returns the
// amount to the screen.
// Pre: None.
// Post: The amount of beers is returned to the screen. 
short get_beers();

// The show_score() function computes the score for the round and outputs 
// the result to the screen.
// Pre: The arr[] must have a data size of 10.
// Post: The result of the score is outputed to the screen.
void show_score(const float arr[], const short num);

// The show_score() function computes the score for the round for sober 
// customers and outputs the result to the screen.
// Pre: None. 
// Post: The score is outputed to the screen. 
void show_score(const short num);

// The show_score() function computes the handicap scores for the round 
// for drunk customers and outputs the result to the screen.
// Pre: arr[] must have a data size of 10.
// Post: The score is outputed to the screen.
void show_score(const float arr[]);

// The play() function computes the scores for 10 shots and outputs the 
// results to the screen.
// Pre: The arr_scores[] must have a data size of 10.
// Post: The scores have been outputed to the screen.
void play(char arr_sounds[], float arr_scores[], const short num);

// The play() function computes the scores for 10 shots and outputes 
// the results to the screen.
// Pre: arr_scores[] must have a data size of 10.
// Post: The scores have been outputed to the screen.
void play(float arr_scores[]);

#endif
