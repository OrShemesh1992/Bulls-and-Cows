#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"


namespace bullpgia {
class SmartGuesser : public bullpgia :: Guesser{
private:

  string s;
  int place;


public:
      SmartGuesser(){//default
        s = "0000";
        place = 0;
      }
string guess() override;
};
}
