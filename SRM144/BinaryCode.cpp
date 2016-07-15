// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

class BinaryCode {
public:
    vector <string> decode(string message) {
        vector <string> res;
		vector<int> decodeInt(message.length()+1);
		vector<int> encodeInt(message.length()+1);
		stringstream ss;

		decodeInt[0] = 0;
		for (int i = 0; i < (int)message.length(); i++)
		{
			decodeInt[i+1] = message.at(i) - '0';
		}

		encodeInt[0] = 0;
		encodeInt[1] = 0;
		for (int i = 1; i < message.length() ; i++)
		{
			encodeInt[i + 1] = decodeInt[i] - encodeInt[i - 1] - encodeInt[i];
			if (encodeInt[i + 1] != 0 && encodeInt[i + 1] != 1)
			{
				res.push_back("NONE");
				break;
			}
		}


		if (res.size() == 0)
		{
			if (decodeInt[message.length()] != encodeInt[message.length() - 1] + encodeInt[message.length()])
			{
				res.push_back("NONE");
			}
			else
			{
				for (int i = 1; i < message.length() + 1; i++)
					ss << encodeInt[i];

				res.push_back(ss.str());
			}
		}


		ss.str("");
		ss.clear();
		encodeInt.clear();
		encodeInt.resize(message.length() + 1);
		encodeInt[0] = 0;
		encodeInt[1] = 1;
		for (int i = 1; i < message.length() ; i++)
		{
			encodeInt[i + 1] = decodeInt[i] - encodeInt[i - 1] - encodeInt[i];
			if (encodeInt[i + 1] != 0 && encodeInt[i + 1] != 1)
			{
				res.push_back("NONE");
				break;
			}
		}


		if (res.size() == 1)
		{
			if (decodeInt[message.length()] != encodeInt[message.length() - 1] + encodeInt[message.length()])
			{
				res.push_back("NONE");
			}
			else
			{
				for (int i = 1; i < message.length() + 1; i++)
					ss << encodeInt[i];

				res.push_back(ss.str());
			}
		}
		return res;
    }

};

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string retrunValueARRAY[] = { "011100011",  "NONE" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BinaryCode theObject;
        eq(0, theObject.decode("123210122"),retrunValue);
    }
    {
        string retrunValueARRAY[] = { "01",  "10" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BinaryCode theObject;
        eq(1, theObject.decode("11"),retrunValue);
    }
    {
        string retrunValueARRAY[] = { "NONE",  "11001" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BinaryCode theObject;
        eq(2, theObject.decode("22111"),retrunValue);
    }
    {
        string retrunValueARRAY[] = { "NONE",  "NONE" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BinaryCode theObject;
        eq(3, theObject.decode("123210120"),retrunValue);
    }
    {
        string retrunValueARRAY[] = { "NONE",  "NONE" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BinaryCode theObject;
        eq(4, theObject.decode("3"),retrunValue);
    }
    {
        string retrunValueARRAY[] = { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BinaryCode theObject;
        eq(5, theObject.decode("12221112222221112221111111112221111"),retrunValue);
    }
}
// END CUT HERE
