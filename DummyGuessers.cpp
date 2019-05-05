#include "DummyGuessers.hpp"
#include <stdlib.h>

std::string RandomGuesser::guess() {
	std::string r="";
	cout << "random guess length=" << this->length << endl;
	for (uint i=0; i<this->length; ++i) {
		char c = '0' + (rand()%10);
		r += c;
	}
	return r;
}
