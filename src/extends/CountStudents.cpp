#pragma once
 
#ifndef _COUNTSTUDENTS_
#define _COUNTSTUDENTS_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int CountStudents(char* fname)
{
  int count = 0;
  
  ifstream fromFile(fname, ios::binary);
  string str;
  char ch;

  int physics;
  int mathematics;
  bool physicCond;
  bool mathCond;

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

    // mathematics
    posEnd = str.find(", ", pos + 1);
    mathematics = stoi(temp.assign(str, pos + 2, posEnd - pos - 2));
    pos = posEnd;

    physicCond = physics == 4 || physics == 5;
    mathCond = mathematics == 4 || mathematics == 5;

    count += mathCond && physicCond;

    str = "";
    pos = 0;
  }

  return count;
}

#endif
