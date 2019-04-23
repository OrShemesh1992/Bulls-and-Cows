#pragma once
#include <string>
#include "calculate.hpp"

using std::string;
namespace bullpgia {

class Guesser {

public:
string replay;
uint length;
virtual void learn(string reply);
 virtual void startNewGame(uint length);
virtual string guess()=0;
};
}
