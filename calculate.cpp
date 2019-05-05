
#include <string>
#include "iostream"
using namespace std;
namespace bullpgia {
string calculateBullAndPgia(string choice,string guess){
        cout << "start calc" << endl;
        int length  =choice.length();
        bool * cheack = new bool[length];
        for (size_t i = 0; i < length; i++) {
                cout << "  i=" << i << endl;
                cheack[i]=false;
        }
 
        int bull=0;
        int pgia=0;
 
        cout << "length=" << length << endl;
        for (size_t i = 0; i < length; i++) {
                cout << "  i=" << i << endl;
                if(choice.at(i)==guess.at(i)) {
                        bull++;
                        cheack[i]=true;
                }
        }
        for (size_t i = 0; i < length; i++) {
                cout << "  i2=" << i << endl;
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
