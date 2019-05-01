
#include "SmartGuesser.hpp"
#include <string>
using std::string;
using namespace bullpgia;

string SmartGuesser::guess() {
        string ans;
        if(this->length <= 4) {
                ans = algo_short();
        } else{
                ans = algo_long();
        }
        return ans;
}

SmartGuesser::SmartGuesser(){
        for (size_t i = 0; i < 10; i++) {
                for (size_t j = 0; j < length; j++) {
                        this->_guess[i]+=to_string(i);
                }
        }
        this->Index=0;
        this->Bull = 0;
        this->Pgia = 0;
}

void SmartGuesser::startNewGame(uint length) {
        this->length=length;
};

void SmartGuesser::learn(string results)
{
        string delimiter = ",";
        string pgia = results.substr(0, results.find(delimiter));
        string bull = results.substr(results.find(delimiter)+1);

        this->Pgia = stoi(pgia);
        this->Bull = stoi(bull);

        if(this->Index<=10){
        choice[this->Index]=this->Pgia+this->Bull;
        }

}

string SmartGuesser::algo_short(){

if(this->Index<=10){
return this->_guess[this->Index++];
}else{

for (size_t i = 0; i < 10; i++) {
  cout<< choice[i]<<endl;
}



}















        return "1234";
}
string SmartGuesser::algo_long(){



        return "1234";
}
