//  Programmer: ANTHONY ROBLES                     Date: 3/23/19
//  File: hw7_funct.cpp                     Class: cs 1570 section b
//  Purpose: This program contains a dart game for Moe's drunk customers.  

#include "hw7.h"

short get_beers()
{
  short beers;
  cout << "How many beers have you consumed?\n"
       << "[Beers]: ";
  cin >> beers;
  return beers;
}

void show_score(const float arr[])
{
  float score_h, avg, sum = 0, sum_2 = 0;
  for (short i = 0; i < NUM_SHOTS; i++)
    sum = sum + arr[i];
  avg = sum / NUM_SHOTS;
  for (short i = 0; i < NUM_SHOTS; i++)
    sum_2 = sum_2 + pow((avg - arr[i]), 2);
  score_h = sum_2/NUM_SHOTS;
  cout << "Your handicap score for this round is " << score_h << endl;
  return;
}
void show_score(const short num)
{
  short score;
  score = num * 0.5;
  cout << "Your score for this round is " << score << endl;
  return;
}

void show_score(const float arr[], const short num)
{
  float score, avg, sum = 0;
  for (short i = 0; i < NUM_SHOTS; i++)
    sum = sum + arr[i];
  avg = sum / NUM_SHOTS;
  score = avg / num;
  cout << "Your score for this round is " << score << endl;
  return;
}

void play(char arr_sounds[], float arr_scores[], const short num)
{
  float x, y, distance, a, a2;
  short angle_1, angle_2;
  for (short i = 0; i < NUM_SHOTS; i++)
  {
    angle_1 = rand()%(2*MAX_ANGLE*num+1) + (MIN_ANGLE*num);
    angle_2 = rand()%(2*MAX_ANGLE*num+1) + (MIN_ANGLE*num);
    a = .017453 * angle_1;
    a2 = .017453 * angle_2;
    x = DISTANCE_AWAY * sin(a2) / cos(a2);
    y = DISTANCE_AWAY * sin(a) / (cos(a) * cos(a2));
    distance = sqrt((pow(x, 2)) + (pow(y, 2)));
    arr_scores[i] = distance;
    cout << "x = " << x << ", y = " << y << "\tscore = " << arr_scores[i];
    if (distance <= RING_1)
    {
      strcpy(arr_sounds, "ding_ding_ding!");
      cout << "\t" << arr_sounds << endl;
    }
    else if (distance > RING_1 && distance <= RING_2)
    {
      strcpy(arr_sounds, "buuurrrrppp!");
      cout << "\t" <<arr_sounds << endl;
    }
    else if (distance > RING_2 && distance <= RING_3)
    {
      strcpy(arr_sounds, "Hey_hey!");
      cout << "\t" << arr_sounds << endl;
    }
    else if (distance > RING_3 && distance <= RING_4)
    {
      strcpy(arr_sounds, "Hmmmmmmm!");
      cout << "\t" << arr_sounds << endl;
    }
    else
    {
      strcpy(arr_sounds, "DOH!");
      cout << "\t" << arr_sounds << endl;
    }
  } 
  return;
}

void play(float arr_scores[])
{
  float distance;
  for (short i = 0; i < NUM_SHOTS; i++)
  {
    distance = rand() % RING_5 ;
    arr_scores[i] = distance;
  }
  return;
}
