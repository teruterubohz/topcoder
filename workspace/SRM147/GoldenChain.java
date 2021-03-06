import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class GoldenChain
{
	public int minCuts(int[] sections)
	{
		
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
		GoldenChain obj;
		int answer;
		obj = new GoldenChain();
		long startTime = System.currentTimeMillis();
		answer = obj.minCuts(p0);
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
		p0 = new int[]{3,3,3,3};
		p1 = 3;
		all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 1 -----
		disabled = false;
		p0 = new int[]{2000000000};
		p1 = 1;
		all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 2 -----
		disabled = false;
		p0 = new int[]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
		p1 = 42;
		all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 3 -----
		disabled = false;
		p0 = new int[]{20000000,20000000,2000000000};
		p1 = 3;
		all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 4 -----
		disabled = false;
		p0 = new int[]{10,10,10,10,10,1,1,1,1,1};
		p1 = 5;
		all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
		tests_disabled = tests_disabled || disabled;
		// ------------------
		
		// ----- test 5 -----
		disabled = false;
		p0 = new int[]{1,10};
		p1 = 1;
		all_right = (disabled || KawigiEdit_RunTest(5, p0, true, p1) ) && all_right;
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
	// Background
	// 
	// I remember a chain problem from my childhood. Suppose you have four sections of a golden chain. Each consists of three links joined together in a line. You would like to connect all four sections into a necklace. The obvious solution is to cut the last link of each section and use it to connect the first section to the second one, then the second to the third, then the third to the fourth, then the fourth to the first one. If you want to minimize the number of cuts, you can do better. You can cut one of the three link sections into its individual links. Using the three loose links you can join the three remaining sections together.
	// 
	// Your task is, given the lengths of the sections, to return the minimum number of cuts to make one big circular necklace out of all of them.
	// 
	// 
	// DEFINITION
	// Class:GoldenChain
	// Method:minCuts
	// Parameters:int[]
	// Returns:int
	// Method signature:int minCuts(int[] sections)
	// 
	// 
	// CONSTRAINTS
	// -sections has between 1 and 50 elements inclusive
	// -each element of sections is between 1 and 2,147,483,647 inclusive
	// -the sum of all elements of sections is between 3 and 2,147,483,647 inclusive
	// 
	// 
	// EXAMPLES
	// 
	// 0)
	// {3,3,3,3}
	// 
	// Returns: 3
	// 
	// 1)
	// {2000000000}
	// 
	// Returns: 1
	// 
	// 2)
	// {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
	// 21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,
	// 38,39,40,41,42,43,44,45,46,47,48,49,50}
	// 
	// Returns: 42
	// 
	// 3)
	// {20000000,20000000,2000000000}
	// 
	// Returns: 3
	// 
	// 4)
	// {10,10,10,10,10,1,1,1,1,1}
	// 
	// Returns: 5
	// 
	// 5)
	// {1,10}
	// 
	// Returns: 1
	// 
	// END KAWIGIEDIT TESTING
}

//Powered by KawigiEdit-pf 2.3.0!
