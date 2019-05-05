
#include <string>
#include "iostream"
using namespace std;
namespace bullpgia {
string calculateBullAndPgia(string choice,string guess){
        int bull = 0;
        int pgia = 0;
        int num[10] = {0};
        for(int i=0; i<choice.length(); i++)
        {
                if(choice.at(i) == guess.at(i))
                {
                        bull++;
                }
                else
                {
                        if(num[guess.at(i) - '0']++ < 0) pgia++;
                        if(num[choice.at(i) - '0']-- > 0) pgia++;
                }
        }
        return to_string(bull) + "," +to_string(pgia);
}
}
