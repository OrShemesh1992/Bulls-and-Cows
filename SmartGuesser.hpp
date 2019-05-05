#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <list>

namespace bullpgia {
class SmartGuesser : public bullpgia :: Guesser{
private:

  list<std::string> AllOption;// we didnt know the length option so we choice list
  std::string Help_guess;

public:
//void clearAllOption();
string guess() override;
void learn(string results) override;
void startNewGame(uint length) override;


void buildList();
void removeFromList(string results);
};
}
