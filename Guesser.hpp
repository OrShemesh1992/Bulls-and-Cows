#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
using std::string;

namespace bullpgia {


class Guesser {
public:
unsigned int length;   //length
string bull_pgia; //[Bull,Pgia]



virtual string guess() = 0;
virtual void startNewGame(uint length) {
      this-> length=length;
};
virtual void learn(string results) {
        this->bull_pgia = results;
};
};
}
