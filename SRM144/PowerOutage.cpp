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
#include <numeric>

using namespace std;

const static int MAX_ELEMENT = 50;
const static int INFTY = 9999999;

class PowerOutage {
	public:
	int estimateTimeOut(vector<int> fromJunction, vector<int> toJunction, vector<int> ductLength) {
		vector<vector<int> > J(MAX_ELEMENT, vector<int>(MAX_ELEMENT, INFTY));
		int elements = fromJunction.size();
		for (int i = 0; i < elements; i++)
		{
			J[fromJunction[i]][toJunction[i]] = J[toJunction[i]][fromJunction[i]] = ductLength[i];
		}

		int farthestDis = dijkstra(J);
		int total = accumulate(ductLength.begin(), ductLength.end(), 0);
		int minMinutes = 2 * total - farthestDis;
        return minMinutes;
    }

	private:
	int dijkstra(const vector<vector<int> >& J){
		vector<int> D(MAX_ELEMENT);
		for (int i = 1; i < MAX_ELEMENT; i++)
		{
			D[i] = J[0][i];
		}

		vector<bool> visited(MAX_ELEMENT, false);
		while (true){
			int minDis = INFTY;
			int minIdx = -1;
			for (int j = 1; j < MAX_ELEMENT; j++){
				if (!visited[j] && D[j] < minDis){
					minDis = D[j];
					minIdx = j;
				}
			}
			if (minIdx == -1)
				break;
			visited[minIdx] = true;

			for (int j = 1; j < MAX_ELEMENT; j++){
				D[j] = min(D[j], minDis + J[minIdx][j]);
			}
		}

		int maxDis = 0;
		for (int i = 0; i < MAX_ELEMENT; i++){
			if (D[i] != INFTY && D[i] > maxDis)
				maxDis = D[i];
		}
		return maxDis;
	}
};

// CUT begin
ifstream data("..\\..\\SRM144\\PowerOutage.sample");

string next_line() {
    string s;
    getline(data, s);
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

bool do_test(vector<int> fromJunction, vector<int> toJunction, vector<int> ductLength, int __expected) {
    time_t startClock = clock();
    PowerOutage *instance = new PowerOutage();
    int __result = instance->estimateTimeOut(fromJunction, toJunction, ductLength);
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
        vector<int> fromJunction;
        from_stream(fromJunction);
        vector<int> toJunction;
        from_stream(toJunction);
        vector<int> ductLength;
        from_stream(ductLength);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(fromJunction, toJunction, ductLength, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1455864115;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1100 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "PowerOutage (1100 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
