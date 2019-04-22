#pragma once
#include <string>
#include "calculate.hpp"

using std::string;
namespace bullpgia {

class Chooser {

public:
virtual string choose(uint length)=0;
};
}
