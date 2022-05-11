#include <gtest/gtest.h>
#include <fstream>

#include "../src/extends/CountStudents.cpp"
#include "../src/extends/getCountsScore.cpp"
#include "../src/extends/ScoresCount.cpp"

using namespace std;

struct WorkWithFile : public testing::Test
{
  char input_fname[30] = "unittests.temp.txt";

  ofstream fout;
  ScoresCount scores;

  string rawData = "\
Moroz, 1, 4, 4, 4, 5\n\
Tkachuk, 4, 3, 4, 3, 4\n\
Petrenko, 1, 0, 5, 4, 2\n\
Koval, 3, 4, 3, 3, 3\n\
Tkachenko, 4, 2, 5, 5, 2\n\
Rudenko, 1, 3, 3, 5, 5\n\
Boyko, 5, 2, 2, 4, 4\n\
Savchenko, 4, 1, 4, 3, 5\n\
Lysenko, 2, 3, 4, 5, 3\n\
Melnyk, 3, 2, 1, 3, 5\n\
";

  void SetUp() override {
    scores.one = 1;
    scores.two = 1;
    scores.three = 2;
    scores.four = 4;
    scores.five = 2;

    fout.open(input_fname);

    fout << rawData;

    fout.close();
  }

  void TearDown() override {
    remove(input_fname);
  }
};


TEST_F(WorkWithFile, CountStudents) {
  int actual = CountStudents(input_fname);

  EXPECT_EQ(actual, 4);
}

TEST_F(WorkWithFile, getCountsScore) {
  ScoresCount actual = getCountsScore(input_fname);

  EXPECT_EQ(actual.one, scores.one);
  EXPECT_EQ(actual.two, scores.two);
  EXPECT_EQ(actual.three, scores.three);
  EXPECT_EQ(actual.four, scores.four);
  EXPECT_EQ(actual.five, scores.five);
}
