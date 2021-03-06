#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>



using namespace std;

class BinaryCode {
    public:
    vector<string> decode(string message) {
		string p1 = "00";
		string p2 = "01";
		string ret1, ret2;
		vector<string> ret;

		for (int i = 1; i <= message.length() ; i++)
		{
			int p = (message.at(i-1) - '0') - (p1.at(i-1) - '0') - (p1.at(i) - '0');
			if (p > 1 || p < 0)
			{
				p1 = "NONE";
				break;
			}
			stringstream ss;
			ss << p;
			p1 += ss.str();
		}
		if (p1 != "NONE") ret1 = p1.substr(1, message.length() );
		else ret1 = "NONE";

		for (int i = 1; i <= message.length() ; i++)
		{
			int p = (message.at(i-1) - '0') - (p2.at(i - 1) - '0') - (p2.at(i) - '0');
			if (p > 1 || p < 0)
			{
				p2 = "NONE";
				break;
			}
			stringstream ss;
			ss << p;
			p2 += ss.str();
		}
		if (p2 != "NONE") ret2 = p2.substr(1, message.length() );
		else ret2 = "NONE";

		ret.push_back(ret1);
		ret.push_back(ret2);
        return  ret;
    }
};

// CUT begin
ifstream ifs("BinaryCode.sample");

string next_line() {
    string s;
    getline(ifs, s);
//	if (ifs.fail()) exit(0);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(string message, vector<string> __expected) {
    time_t startClock = clock();
    BinaryCode *instance = new BinaryCode();
    vector<string> __result = instance->decode(message);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string message;
        from_stream(message);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(message, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1512229331;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "BinaryCode (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
