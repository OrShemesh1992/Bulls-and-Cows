#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
using std::string;

namespace bullpgia {


class Guesser{

public:

 unsigned  int length; //length
  // int Bull;
  // int Pgia;

	virtual string guess() = 0;
        virtual void startNewGame(uint length) {
            length=length;
        };
        virtual void learn(string results) {};
};
}
