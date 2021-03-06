using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;


public class CCipher
{
	public string decode(string cipherText, int shift)
	{
        //string res = new string( 'A',  cipherText.Length );
        string res = null;

        for( int i = 0; i < cipherText.Length; i++ )
        {
            int num = cipherText[i];
            int num2 = num - shift;
            if (num2 < 'A')
                res += (char)('Z' - ('A' - num2 - 1));
            else
                res += (char)num2;
        }

        return res;	
	}

	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit-pf 2.3.0
	#region Testing code generated by KawigiEdit
	[STAThread]
	private static Boolean KawigiEdit_RunTest(int testNum, string p0, int p1, Boolean hasAnswer, string p2) {
		Console.Write("Test " + testNum + ": [" + "\"" + p0 + "\"" + "," + p1);
		Console.WriteLine("]");
		CCipher obj;
		string answer;
		obj = new CCipher();
		DateTime startTime = DateTime.Now;
		answer = obj.decode(p0, p1);
		DateTime endTime = DateTime.Now;
		Boolean res;
		res = true;
		Console.WriteLine("Time: " + (endTime - startTime).TotalSeconds + " seconds");
		if (hasAnswer) {
			res = answer == p2;
		}
		if (!res) {
			Console.WriteLine("DOESN'T MATCH!!!!");
			if (hasAnswer) {
				Console.WriteLine("Desired answer:");
				Console.WriteLine("\t" + "\"" + p2 + "\"");
			}
			Console.WriteLine("Your answer:");
			Console.WriteLine("\t" + "\"" + answer + "\"");
		} else if ((endTime - startTime).TotalSeconds >= 2) {
			Console.WriteLine("FAIL the timeout");
			res = false;
		} else if (hasAnswer) {
			Console.WriteLine("Match :-)");
		} else {
			Console.WriteLine("OK, but is it right?");
		}
		Console.WriteLine("");
		return res;
	}
	public static void Main(string[] args) {
		Boolean all_right;
		Boolean disabled;
		Boolean tests_disabled;
		all_right = true;
		tests_disabled = false;
		
		string p0;
		int p1;
		string p2;
		
		// ----- test 0 -----
		disabled = false;
		p0 = "VQREQFGT";
		p1 = 2;
		p2 = "TOPCODER";
		all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 1 -----
		disabled = false;
		p0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		p1 = 10;
		p2 = "QRSTUVWXYZABCDEFGHIJKLMNOP";
		all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 2 -----
		disabled = false;
		p0 = "TOPCODER";
		p1 = 0;
		p2 = "TOPCODER";
		all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 3 -----
		disabled = false;
		p0 = "ZWBGLZ";
		p1 = 25;
		p2 = "AXCHMA";
		all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 4 -----
		disabled = false;
		p0 = "DBNPCBQ";
		p1 = 1;
		p2 = "CAMOBAP";
		all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 5 -----
		disabled = false;
		p0 = "LIPPSASVPH";
		p1 = 4;
		p2 = "HELLOWORLD";
		all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		if (all_right) {
			if (tests_disabled) {
				Console.WriteLine("You're a stud (but some test cases were disabled)!");
			} else {
				Console.WriteLine("You're a stud (at least on given cases)!");
			}
		} else {
			Console.WriteLine("Some of the test cases had errors.");
		}
	}
	#endregion
	// PROBLEM STATEMENT
	// 
	// Julius Caesar used a system of cryptography, now known as Caesar Cipher, which shifted each letter 2 places further through the alphabet (e.g. 'A' shifts to 'C', 'R' shifts to 'T', etc.). At the end of the alphabet we wrap around, that is 'Y' shifts to 'A'.
	// 
	// We can, of course, try shifting by any number. Given an encoded text and a number of places to shift, decode it.
	// 
	// For example, "TOPCODER" shifted by 2 places will be encoded as "VQREQFGT". In other words, if given (quotes for clarity) "VQREQFGT"  and 2 as input, you will return "TOPCODER". See example 0 below.
	// 
	// 
	// DEFINITION
	// Class:CCipher
	// Method:decode
	// Parameters:string, int
	// Returns:string
	// Method signature:string decode(string cipherText, int shift)
	// 
	// 
	// CONSTRAINTS
	// -cipherText has between 0 to 50 characters inclusive
	// -each character of cipherText is an uppercase letter 'A'-'Z'
	// -shift is between 0 and 25 inclusive
	// 
	// 
	// EXAMPLES
	// 
	// 0)
	// "VQREQFGT"
	// 2
	// 
	// Returns: "TOPCODER"
	// 
	// 1)
	// "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	// 10
	// 
	// Returns: "QRSTUVWXYZABCDEFGHIJKLMNOP"
	// 
	// 2)
	// "TOPCODER"
	// 0
	// 
	// Returns: "TOPCODER"
	// 
	// 3)
	// "ZWBGLZ"
	// 25
	// 
	// Returns: "AXCHMA"
	// 
	// 4)
	// "DBNPCBQ"
	// 1
	// 
	// Returns: "CAMOBAP"
	// 
	// 5)
	// "LIPPSASVPH"
	// 4
	// 
	// Returns: "HELLOWORLD"
	// 
	// END KAWIGIEDIT TESTING
}

//Powered by KawigiEdit-pf 2.3.0!
