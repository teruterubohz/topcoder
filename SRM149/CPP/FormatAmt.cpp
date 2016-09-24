#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class FormatAmt {
public:
	string amount(int dollars, int cents) {

		locale::global(locale("japanese"));
		ostringstream oss;
		stringstream  tempss;

		tempss << setfill('0') << setw(2) << cents;
		
		oss << "$" <<dollars << "." << tempss.str();

		return oss.str();
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	FormatAmt *obj;
	string answer;
	obj = new FormatAmt();
	clock_t startTime = clock();
	answer = obj->amount(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
		if (hasAnswer) {
			cout << "Desired answer:" << endl;
			cout << "\t" << "\"" << p2 << "\"" << endl;
		}
		cout << "Your answer:" << endl;
		cout << "\t" << "\"" << answer << "\"" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	int p0;
	int p1;
	string p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 123456;
	p1 = 0;
	p2 = "$123,456.00";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 49734321;
	p1 = 9;
	p2 = "$49,734,321.09";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 0;
	p1 = 99;
	p2 = "$0.99";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 249;
	p1 = 30;
	p2 = "$249.30";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 1000;
	p1 = 1;
	p2 = "$1,000.01";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// In documents, it is frequently necessary to write monetary amounts in a 
// standard format.  We have decided to format amounts as follows:
//     the amount must start with '$'
//     the amount should have a leading '0' if and only if it is less then 1 dollar.
//     the amount must end with a decimal point and exactly 2 following digits.
//     the digits to the left of the decimal point must be separated into groups of three by commas (a group of one or two digits may appear on the left).
// 
// 
// Create a class FormatAmt that contains a method amount that takes two int's, dollars and cents, as inputs and returns the properly formatted string.
// 
// 
// 
// DEFINITION
// Class:FormatAmt
// Method:amount
// Parameters:int, int
// Returns:string
// Method signature:string amount(int dollars, int cents)
// 
// 
// NOTES
// -One dollar is equal to 100 cents.
// 
// 
// CONSTRAINTS
// -dollars will be between 0 and 2,000,000,000 inclusive
// -cents will be between 0 and 99 inclusive
// 
// 
// EXAMPLES
// 
// 0)
// 123456
// 0
// 
// Returns: "$123,456.00"
// 
// Note that there is no space between the $ and the first digit.
// 
// 1)
// 49734321
// 9
// 
// Returns: "$49,734,321.09"
// 
// 2)
// 0
// 99
// 
// Returns: "$0.99"
// 
// Note the leading 0.
// 
// 3)
// 249
// 30
// 
// Returns: "$249.30"
// 
// 4)
// 1000
// 1
// 
// Returns: "$1,000.01"
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
