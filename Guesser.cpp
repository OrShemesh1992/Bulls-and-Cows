#include "Guesser.hpp"

void bullpgia::Guesser::learn(string results)
{

          string delimiter = ",";
          string pgia = results.substr(0, results.find(delimiter));
          string bull = results.substr(results.find(delimiter)+1);

          this->countPgia = stoi(pgia);
          this->countBull = stoi(bull);
}
