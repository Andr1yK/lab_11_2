#pragma once
 
#ifndef _GETCOUNTSSCORE_
#define _GETCOUNTSSCORE_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "./ScoresCount.cpp"

using namespace std;

ScoresCount getCountsScore(char* filename)
{
  ScoresCount newCount;

  ifstream fromFile(filename, ios::binary);
  string str;
  char ch;

  int physics;

  int pos = 0;
  int posEnd = 0;

  string temp;

  while (fromFile.read((char*)&ch, sizeof(ch)))
  {
    do {
      str += ch;
    } while (fromFile.read((char*)&ch, sizeof(ch)) && ch != '\n');

    // lastname
    pos = str.find(", ", pos + 1);

    // rank
    pos = str.find(", ", pos + 1);

    // specialty
    pos = str.find(", ", pos + 1);
  
    // physics
    posEnd = str.find(", ", pos + 1);
    physics = stoi(temp.assign(str, pos + 2, posEnd - pos - 2));
    pos = posEnd;

    switch (physics)
    {
    case (1):
      newCount.one++;
      break;

    case (2):
      newCount.two++;
      break;

    case (3):
      newCount.three++;
      break;

    case (4):
      newCount.four++;
      break;

    case (5):
      newCount.five++;
      break;
    }

    str = "";
    pos = 0;
  }

  return newCount;
}

#endif
