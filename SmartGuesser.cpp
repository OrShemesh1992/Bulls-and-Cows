
#include "SmartGuesser.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <string>
using std::string;
using namespace std;
using namespace bullpgia;




string SmartGuesser::guess() {
        std::list<std::string>::iterator it = AllOption.begin();
         if(AllOption.size()==0){
              buildList();       
        }
        if(AllOption.size()>1) {
                std::advance(it, rand()%(AllOption.size()-1));
                this->Help_guess = *it;
        }
        else if(AllOption.size()==1){
                this->Help_guess = *AllOption.begin();
        }
        return Help_guess;
}
void SmartGuesser::startNewGame(uint length) {
        AllOption.clear();
        this->length=length;
        buildList();
}

 void SmartGuesser::buildList(){
        int size= pow(10,length);
        for (size_t i = 0; i < size; i++) {
                stringstream stream;
                stream << setw(length) << setfill('0') << i;  //http://www.cplusplus.com/reference/iomanip/setfill/
                string s = stream.str();
                AllOption.push_front(s); //http://www.cplusplus.com/reference/list/list/insert/
        }
 }

void SmartGuesser::removeFromList(string results){
        list<string>::iterator itr;
        for(itr = AllOption.begin(); itr != AllOption.end();)
        {
                string back=calculateBullAndPgia(*itr,Help_guess);
                if(back.compare(results)!=0) {
                        itr=AllOption.erase(itr);
                }
                else{
                        ++itr;
                }
        }
      this-> AllOption.remove(Help_guess);
}


void SmartGuesser::learn(string results)

{
        removeFromList(results);
}
