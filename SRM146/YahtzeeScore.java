import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class YahtzeeScore
{
	public int maxPoints(int[] toss)
	{
		int res = 0;
		int[] v = new int[6];
		for( int i = 0 ; i < v.length ; i++ )
		{
			v[i] = 0;
		}
		
		for( int i = 0 ; i < toss.length ; i++ )
		{
			v[toss[i] - 1] += toss[i];
		}
		
		for( int i = 0 ; i < v.length ; i++ )
		{
			if( res < v[i] )
				res = v[i];
		}
		
		return res;
	}
	
	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit-pf 2.3.0
	private static boolean KawigiEdit_RunTest(int testNum, int[] p0, boolean hasAnswer, int p1) {
		System.out.print("Test " + testNum + ": [" + "{");
		for (int i = 0; p0.length > i; ++i) {
			if (i > 0) {
				System.out.print(",");
			}
			System.out.print(p0[i]);
		}
		System.out.print("}");
		System.out.println("]");
		YahtzeeScore obj;
		int answer;
		obj = new YahtzeeScore();
		long startTime = System.currentTimeMillis();
		answer = obj.maxPoints(p0);
		long endTime = System.currentTimeMillis();
		boolean res;
		res = true;
		System.out.println("Time: " + (endTime - startTime) / 1000.0 + " seconds");
		if (hasAnswer) {
			res = answer == p1;
		}
		if (!res) {
			System.out.println("DOESN'T MATCH!!!!");
			if (hasAnswer) {
				System.out.println("Desired answer:");
				System.out.println("\t" + p1);
			}
			System.out.println("Your answer:");
			System.out.println("\t" + answer);
		} else if ((endTime - startTime) / 1000.0 >= 2) {
			System.out.println("FAIL the timeout");
			res = false;
		} else if (hasAnswer) {
			System.out.println("Match :-)");
		} else {
			System.out.println("OK, but is it right?");
		}
		System.out.println("");
		return res;
	}
	public static void main(String[] args) {
		boolean all_right;
		boolean disabled;
		boolean tests_disabled;
		all_right = true;
		tests_disabled = false;
		
		int[] p0;
		int p1;
		
		// ----- test 0 -----
		disabled = false;
		p0 = new int[]{2,2,3,5,4};
		p1 = 5;
		all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 1 -----
		disabled = false;
		p0 = new int[]{6,4,1,1,3};
		p1 = 6;
		all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 2 -----
		disabled = false;
		p0 = new int[]{5,3,5,3,3};
		p1 = 10;
		all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		if (all_right) {
			if (tests_disabled) {
				System.out.println("You're a stud (but some test cases were disabled)!");
			} else {
				System.out.println("You're a stud (at least on given cases)!");
			}
		} else {
			System.out.println("Some of the test cases had errors.");
		}
	}
	// PROBLEM STATEMENT
	// This task is about the scoring in the first phase of the die-game Yahtzee, where five dice are used. The score is determined by the values on the upward die faces after a roll. The player gets to choose a value, and all dice that show the chosen value are considered active. The score is simply the sum of values on active dice.
	// 
	// Say, for instance, that a player ends up with the die faces showing 2, 2, 3, 5 and 4. Choosing the value two makes the dice showing 2 active and yields a score of 2 + 2 = 4, while choosing 5 makes the one die showing 5 active, yielding a score of 5.
	// 
	// Your method will take as input a int[] toss, where each element represents the upward face of a die, and return the maximum possible score with these values.
	// 
	// 
	// 
	// DEFINITION
	// Class:YahtzeeScore
	// Method:maxPoints
	// Parameters:int[]
	// Returns:int
	// Method signature:int maxPoints(int[] toss)
	// 
	// 
	// CONSTRAINTS
	// -toss will contain exactly 5 elements.
	// -Each element of toss will be between 1 and 6, inclusive.
	// 
	// 
	// EXAMPLES
	// 
	// 0)
	// { 2, 2, 3, 5, 4 }
	// 
	// Returns: 5
	// 
	// The example from the text.
	// 
	// 1)
	// { 6, 4, 1, 1, 3 }
	// 
	// Returns: 6
	// 
	// Selecting 1 as active yields 1 + 1 = 2, selecting 3 yields 3, selecting 4 yields 4 and selecting 6 yields 6, which is the maximum number of points.
	// 
	// 2)
	// { 5, 3, 5, 3, 3 }
	// 
	// Returns: 10
	// 
	// END KAWIGIEDIT TESTING
}

//Powered by KawigiEdit-pf 2.3.0!