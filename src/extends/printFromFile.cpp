#pragma once

#ifndef _PRINT_FROM_FILE_
#define _PRINT_FROM_FILE_

#include <iostream>
#include <fstream>
#include <string>
#include "Student.hpp"

using namespace std;

void printHeader() {
  cout << "===========================================================================================================" << endl;

  cout << "| " << setw(2) << "№ " << " | "
    << setw(12) << left << "Прізвище" << " | "
    << setw(4) << "Курс" << " | "
    << setw(20) << "Спеціальність" << " | "
    << setw(6) << "Фізика" << " | "
    << setw(6) << "Матем." << " | "
    << setw(8) << "Програм." << " | "
    << setw(11) << "Чис. методи" << " | "
    << setw(10) << "Педагогіка" << " |"
    << endl;

  cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}

void printRow(Student student, int index) {
  string specialtyList[] = {
    "Матем. та економіка",
    "Трудове навчання",
    "Фізика та інформ.",
    "Інформатика",
    "Комп’ютерні науки"
  };

  cout << "|" << setw(2) << right << index + 1 << " "
      << " | " << setw(12) << left << student.lastName
      << " | " << setw(4) << right << student.rank
      << " | " << setw(20) << left << specialtyList[student.specialty]
      << " | " << setw(6) << right << student.physics
      << " | " << setw(6) << right << student.mathematics;

    switch (student.specialty)
    {
    case KN:
      cout << " | " << setw(8) << right << student.programing
        << " | " << setw(14)
        << " | " << setw(12)
        << " |"
        << endl;
      break;

    case INF:
      cout << " | " << setw(11)
        << " | " << setw(11) << right << student.numMethods
        << " | " << setw(12)
        << " |"
        << endl;
      break;

    default:
      cout << " | " << setw(11)
        << " | " << setw(14)
        << " | " << setw(10) << right << student.pedagogy
        << " |"
        << endl;
    }

    cout << "-----------------------------------------------------------------------------------------------------------" << endl;

} 

Student PrintFromFile(const char* filename)
{
  ifstream fromFile(filename, ios::binary);
  string str;
  char ch;

  Student student;

  int pos = 0;
  int posEnd = 0;
  int index = 0;

  string temp;

  printHeader();

  while (fromFile.read((char*)&ch, sizeof(ch)))
  {
    do {
      str += ch;
    } while (fromFile.read((char*)&ch, sizeof(ch)) && ch != '\n');

    // lastname
    posEnd = str.find(", ", pos + 1);
    student.lastName.assign(str, pos, posEnd - pos);
    pos = posEnd;

    // rank
    posEnd = str.find(", ", pos + 1);
    student.rank = stoi(temp.assign(str, pos + 2, posEnd - pos - 2));
    pos = posEnd;

    // specialty
    posEnd = str.find(", ", pos + 1);
    student.specialty = (Specialty)stoi(temp.assign(str, pos + 2, posEnd - pos - 2));
    pos = posEnd;
  
    // physics
    posEnd = str.find(", ", pos + 1);
    student.physics = stoi(temp.assign(str, pos + 2, posEnd - pos - 2));
    pos = posEnd;

    // mathematics
    posEnd = str.find(", ", pos + 1);
    student.mathematics = stoi(temp.assign(str, pos + 2, posEnd - pos - 2));
    pos = posEnd;

    // union subject
    posEnd = str.find("\n", pos + 1);
    temp.assign(str, pos + 2, posEnd - pos - 2);

    switch (student.specialty) {
      case KN:
        student.programing = stoi(temp);
        break;

      case INF:
        student.numMethods = stoi(temp);
        break;

      default:
        student.pedagogy = stoi(temp);
        break;
    }
    
    printRow(student, index);

    str = "";
    pos = 0;
    index++;
  }

  fromFile.close();

  return student;
}

#endif