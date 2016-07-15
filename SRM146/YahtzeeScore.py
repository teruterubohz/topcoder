import math,string,itertools,fractions,heapq,collections,re,array,bisect,random

class YahtzeeScore:
    def maxPoints(self, toss):
        
        res = 0
        v = [0]*6;

        for i in range(len(v)):
            v[i] = 0

        for i in range(len(toss)):
            v[toss[i]-1] += toss[i]

        for i in range(len(v)):
            if( res < v[i] ):
                res = v[i]

        return res

# BEGIN KAWIGIEDIT TESTING
# Generated by KawigiEdit-pf 2.3.0
import sys
import time
def KawigiEdit_RunTest(testNum, p0, hasAnswer, p1):
	sys.stdout.write(str("Test ") + str(testNum) + str(": [") + str("{"))
	for i in range(len(p0)):
		if (i > 0):
			sys.stdout.write(str(","))
		
		sys.stdout.write(str(p0[i]))
	
	sys.stdout.write(str("}"))
	print(str("]"))
	obj = YahtzeeScore()
	startTime = time.clock()
	answer = obj.maxPoints(p0)
	endTime = time.clock()
	res = True
	print(str("Time: ") + str((endTime - startTime)) + str(" seconds"))
	if (hasAnswer):
		res = answer == p1
	
	if (not res):
		print(str("DOESN'T MATCH!!!!"))
		if (hasAnswer):
			print(str("Desired answer:"))
			print(str("\t") + str(p1))
		
		print(str("Your answer:"))
		print(str("\t") + str(answer))
	elif ((endTime - startTime) >= 2):
		print(str("FAIL the timeout"))
		res = False
	elif (hasAnswer):
		print(str("Match :-)"))
	else:
		print(str("OK, but is it right?"))
	
	print(str(""))
	return res

all_right = True
tests_disabled = False


# ----- test 0 -----
disabled = False
p0 = (2,2,3,5,4)
p1 = 5
all_right = (disabled or KawigiEdit_RunTest(0, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 1 -----
disabled = False
p0 = (6,4,1,1,3)
p1 = 6
all_right = (disabled or KawigiEdit_RunTest(1, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 2 -----
disabled = False
p0 = (5,3,5,3,3)
p1 = 10
all_right = (disabled or KawigiEdit_RunTest(2, p0, True, p1) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

if (all_right):
	if (tests_disabled):
		print(str("You're a stud (but some test cases were disabled)!"))
	else:
		print(str("You're a stud (at least on given cases)!"))
	
else:
	print(str("Some of the test cases had errors."))

# PROBLEM STATEMENT
# This task is about the scoring in the first phase of the die-game Yahtzee, where five dice are used. The score is determined by the values on the upward die faces after a roll. The player gets to choose a value, and all dice that show the chosen value are considered active. The score is simply the sum of values on active dice.
# 
# Say, for instance, that a player ends up with the die faces showing 2, 2, 3, 5 and 4. Choosing the value two makes the dice showing 2 active and yields a score of 2 + 2 = 4, while choosing 5 makes the one die showing 5 active, yielding a score of 5.
# 
# Your method will take as input a tuple (integer) toss, where each element represents the upward face of a die, and return the maximum possible score with these values.
# 
# 
# 
# DEFINITION
# Class:YahtzeeScore
# Method:maxPoints
# Parameters:tuple (integer)
# Returns:integer
# Method signature:def maxPoints(self, toss):
# 
# 
# CONSTRAINTS
# -toss will contain exactly 5 elements.
# -Each element of toss will be between 1 and 6, inclusive.
# 
# 
# EXAMPLES
# 
# 0)
# { 2, 2, 3, 5, 4 }
# 
# Returns: 5
# 
# The example from the text.
# 
# 1)
# { 6, 4, 1, 1, 3 }
# 
# Returns: 6
# 
# Selecting 1 as active yields 1 + 1 = 2, selecting 3 yields 3, selecting 4 yields 4 and selecting 6 yields 6, which is the maximum number of points.
# 
# 2)
# { 5, 3, 5, 3, 3 }
# 
# Returns: 10
# 
# END KAWIGIEDIT TESTING
#Powered by KawigiEdit-pf 2.3.0!