
#include <string>
#include "iostream"
using namespace std;
namespace bullpgia {
string calculateBullAndPgia(string choice,string guess){
        int length  =choice.length();
        bool * cheack = new bool[length];
        for (size_t i = 0; i < length; i++) {
                cheack[i]=false;
        }
 
        int bull=0;
        int pgia=0;
 
        for (size_t i = 0; i < length; i++) {
                if(choice.at(i)==guess.at(i)) {
                        bull++;
                        cheack[i]=true;
                }
        }
        for (size_t i = 0; i < length; i++) {
                for (size_t j = 0; j < length; j++) {
                        if(choice.at(i)==guess.at(j)&&!cheack[i]&&!cheack[j]) {
                                pgia++;
                                break;
                        }
                }
        }
        delete[] cheack;
        return to_string(bull)+","+to_string(pgia);
}
}
