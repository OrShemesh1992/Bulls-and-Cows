 #pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <string>
#include "Chooser.hpp"
//using std::string;
namespace bullpgia {
class SmartGuesser : public bullpgia :: Guesser{
public:
  void learn(string reply) override;
   void startNewGame(uint length) override;
   string guess() override;

};
}
