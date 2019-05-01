#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"


namespace bullpgia {
class SmartGuesser : public bullpgia :: Guesser{
private:
  int Bull;
  int Pgia;
  int Index;
  string * _guess = new string[10];
  int * choice = new int [10];
  string * allOption;

  string str;
public:

string guess() override;
void learn(string results) override;
void startNewGame(uint length) override;

SmartGuesser();
string algo_short();
string algo_long();
};
}
