#include <iostream>

#include "./extends/extendFunctions.cpp"
#include "./extends/CountStudents.cpp"
#include "./extends/getCountsScore.cpp"
#include "./extends/printFromFile.cpp"
#include "./extends/ScoresCount.cpp"

using namespace std;

int main()
{
  setlocale(LC_CTYPE, "ukr");

  char fname[100] = "test";

  cout << endl;
  cout << "enter file name: "; cin >> fname;
  cout << endl;

  PrintFromFile(fname);

  cout << endl;

  cout << "Кількість кожної оцінки з фізики" << endl;

  ScoresCount scores = getCountsScore(fname);

  cout << " Кількість 3 з фізики: " << scores.three << endl;
  cout << " Кількість 4 з фізики: " << scores.four << endl;
  cout << " Кількість 5 з фізики: " << scores.five << endl;

  cout << endl;

  cout << "Кількість студентів в яких оцінка з фізики та математики 4 або 5: "
    << CountStudents(fname)
    << endl << endl;

  return 0;
}
