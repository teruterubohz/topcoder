#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#include <functional>

using namespace std;

class Bonuses {
    public:
    vector<int> getDivision(vector<int> points) {
		int score = 0;
	
		vector<int>::iterator itr = points.begin();
		while( itr != points.end()){
			score += *itr;
			++itr;
		}

		vector<int> bonus(points.size());
		int sum = 0;

		for (int i = 0; i < points.size(); i++) {
			bonus[i] = 100 * points[i] / score;
			sum += bonus[i];
		}

		int rest = 100 - sum;

		vector<int> tmp(points.size());
		copy(points.begin(), points.end(), back_inserter(tmp));
		sort(tmp.begin(), tmp.end(), std::greater<int>());

		vector<int> check(points.size());

		for (int i = 0; i < rest; i++) {
			for (int j = 0; j < points.size(); j++) {
				if (tmp[i] == points[j]) {
					if (tmp[i] == points[j]) {
						if (check[j] == 0) {
							check[j] = 1;
							bonus[j] += 1;
							break;
						}
					}
				}
			}
		}

        return bonus;
    }
};

// CUT begin
ifstream lfs("Bonuses.sample");

string next_line() {
    string s;
    getline(lfs, s);
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

bool do_test(vector<int> points, vector<int> __expected) {
    time_t startClock = clock();
    Bonuses *instance = new Bonuses();
    vector<int> __result = instance->getDivision(points);
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
        vector<int> points;
        from_stream(points);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(points, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1514300704;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "Bonuses (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
