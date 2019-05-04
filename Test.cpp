/**
 * A demo program for bull-pgia.
 *
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#include "calculate.hpp"
#include "Guesser.hpp"
#include "Chooser.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

badkan::TestCase testcase;
int grade=0;
int signal = setjmp(badkan::longjmp_buffer);
if (signal == 0) {

																// BASIC TESTS - DO NOT CHANGE
ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
																ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

																testcase.setname("Calculate bull and pgia")
																.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0") // 4 bull, 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4") // 0 bull, 4 pgia
																;

																testcase.setname("Play with dummy choosers and guessers")
																.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1) // guesser wins in one turn.
																.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101) // guesser loses by running out of turns
																.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101) // guesser loses technically by making an illegal guess (too long).
																.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0) // chooser loses technically by choosing an illegal number (too long).
																;

																testcase.setname("Play with smart guesser");
																RandomChooser randy;
																SmartGuesser smarty;
																for (uint i=0; i<100; ++i) {
																								testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true); // smarty should always win in at most 10 turns!
																}
															                            	// My Test //
																RandomChooser randy1;
																SmartGuesser smarty1;
																for (uint i=0; i<100; ++i) {
																								testcase.CHECK_EQUAL(play(randy1, smarty1, 3, 100)<=80, true); // smarty should always win in at most 10 turns!
																}
																RandomChooser randy2;
																SmartGuesser smarty2;
																for (uint i=0; i<100; ++i) {
																								testcase.CHECK_EQUAL(play(randy2, smarty2, 2, 100)<=60, true); // smarty should always win in at most 10 turns!
																}
																RandomChooser randy3;
																SmartGuesser smarty3;
																for (uint i=0; i<100; ++i) {
																								testcase.CHECK_EQUAL(play(randy3, smarty3, 1, 100)<=40, true); // smarty should always win in at most 10 turns!
																}

																testcase.setname("Test CalculateBull Succes")
																.CHECK_OUTPUT(calculateBullAndPgia("123456789","123456789"),"9,0") // 9 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("123","321"),"1,2")//2 pgia 1 bull
																.CHECK_OUTPUT(calculateBullAndPgia("123456789","123456780"),"8,0") // 8 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("123","321"),"1,2")//1 bull 2 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("1234","1204"),"3,0") // 3 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("7777","0000"),"0,0")// 0 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("2020", "0202"), "0,4") // 0 bull, 4 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("1010", "0000"), "2,0") // 2 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("1013", "1023"), "3,0") // 3 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("5555", "4445"), "1,0") // 1 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("5749", "5749"), "4,0") // 4 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("5749", "5479"), "2,2") // 2 bull 2 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("15", "10"), "1,0") // 1 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("14", "41"), "0,2") // 0 bull 2 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("15", "15"), "2,0") // 2 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("8", "5"), "0,0") // 0 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("8", "8"), "1,0") // 1 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("123", "102"), "1,1") // 1 bull 1 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("123", "120"), "2,0") // 2 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("123", "045"), "0,0") // 0 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("123", "321"), "1,2") // 1 bull 2 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("22222","22222"),"5,0")//4 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("930","338"), "1,0")//1 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("42","40"),"1,0")//1 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("111","101"),"2,0")//2 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("123","310"),"0,2")//0 bull 2 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("71","10"),"0,1")//0 bull 1 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("2341324","9876300"),"1,0")//1 bull 0 pgia
																.CHECK_OUTPUT(calculateBullAndPgia("68","92"),"0,0")//0 bull 0 pgia
															.CHECK_OUTPUT(calculateBullAndPgia("1234","4214"),"2,1"); //1 bull 2 pgia


											ConstantChooser  c111111{"111111"}, c12{"12"},c334{"334"},c0{"0"},c8989898989{"8989898989"},c1{"1"},c98{"98"},c232323{"232323"},c567{"567"};
											ConstantGuesser g111111{"111111"},	g12{"12"},g334{"334"},g0{"0"},g8989898989{"8989898989"},g1{"1"},g98{"98"},g232323{"232323"},g567{"567"};
											testcase.setname("Play with dummy choosers and guessers-guesser wins")
											.CHECK_EQUAL(play(c1234, g1234, 4, 40), 1) // guesser wins in one turn.
											.CHECK_EQUAL(play(c9999, g9999, 4, 30), 1) // guesser wins in one turn.
											.CHECK_EQUAL(play(c12345, g12345, 5, 30), 1) // guesser wins in one turn.
											.CHECK_EQUAL(play(c12, g12, 2, 15), 1) // guesser wins in one turn.
											.CHECK_EQUAL(play(c334, g334, 3,100), 1) // guesser wins in one turn.
											.CHECK_EQUAL(play(c0, g0, 1, 10), 1) // guesser wins in one turn.
											.CHECK_EQUAL(play(c8989898989, g8989898989, 10, 100), 1) // guesser wins in one turn.
											.CHECK_EQUAL(play(c111111, g111111, 6, 100), 1); // guesser wins in one turn.

											testcase.setname("Play with dummy choosers and guessers-chooser loses technically")
											.CHECK_EQUAL(play(c111111, g111111, 4, 100), 0) // chooser loses technically by choosing an illegal number (too long).
											.CHECK_EQUAL(play(c0, g12, 2, 100), 0) // chooser loses technically by choosing an illegal number (too long).
											.CHECK_EQUAL(play(c334, g1234, 4, 100), 0)// chooser loses technically by choosing an illegal number (too long).
											.CHECK_EQUAL(play(c8989898989, g1234,5, 100), 0) // chooser loses technically by choosing an illegal number (too long).
											.CHECK_EQUAL(play(c9999, g1234,3, 100), 0); // chooser loses technically by choosing an illegal number (too long).

											testcase.setname("Play with dummy choosers and guessers-// guesser loses by running out of turns")
											.CHECK_EQUAL(play(c1, g0, 1, 100), 101) // guesser loses technically by making an illegal guess (too long).
											.CHECK_EQUAL(play(c98, g12, 2, 100), 101) // guesser loses technically by making an illegal guess (too long).
											.CHECK_EQUAL(play(c111111, g232323, 6, 100), 101) // guesser loses technically by making an illegal guess (too long).
											.CHECK_EQUAL(play(c334, g567, 3, 40), 41) // guesser loses technically by making an illegal guess (too long).


;





																grade = testcase.grade();
								} else {
																testcase.print_signal(signal);
																grade = 0;
								}
								cout << "Your grade is: "  << grade << endl;
								return 0;
}
