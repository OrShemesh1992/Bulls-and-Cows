#pragma once
#include <string>
using std::string;
namespace bullpgia {

class Guesser {
private:

public:
uint length;
void learn(int * reply);
void startNewGame(uint length);
virtual string guess();
};
}
