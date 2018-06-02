using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

public class Bonuses {
	public int[] getDivision(int[] points) {
        int score = 0;
        for( int i = 0; i < points.Length; i++)
        {
            score += points[i];
        }

        int[] bonus = new int[points.Length];
        int sum = 0;

        for( int i = 0; i < points.Length; i++)
        {
            bonus[i] = 100 * points[i] / score;
            sum += bonus[i];
        }

        int rest = 100 - sum;

        int[] tmp = new int[points.Length];
        Array.Copy(points, tmp, points.Length);
        Array.Sort(tmp);
        Array.Reverse(tmp);
        
        int[] check = new int[points.Length];

        for( int i = 0; i < rest; i++)
        {
            for( int j = 0; j < points.Length; j++)
            {
                if( tmp[i] == points[j])
                {
                    if( check[j] == 0)
                    {
                        check[j] = 1;
                        bonus[j] += 1;
                        break;
                    }
                }
            }
        }

        return bonus;
	}

// CUT begin
	static bool DoTest(int[] points, int[] __expected) {
		DateTime startTime = DateTime.Now;
		Exception exception = null;
		Bonuses instance = new Bonuses();
		int[] __result = new int[] { };
		try {
			__result = instance.getDivision(points);
		}
		catch (Exception e) { exception = e; }
		TimeSpan __elapsed = new TimeSpan(DateTime.Now.Ticks - startTime.Ticks);

		if (exception != null) {
			Console.Error.WriteLine("RUNTIME ERROR!");
			Console.Error.WriteLine(exception);
			return false;
		}
		else if (Equals(__result, __expected)) {
			Console.Error.WriteLine("PASSED! " + string.Format("({0:0.00} seconds)", __elapsed.TotalSeconds));
			return true;
		}
		else {
			Console.Error.WriteLine("FAILED! " + string.Format("({0:0.00} seconds)", __elapsed.TotalSeconds));
			Console.Error.WriteLine("           Expected: " + ToString(__expected));
			Console.Error.WriteLine("           Received: " + ToString(__result));
			return false;
		}
	}

	static bool Equals(int[] a, int[] b) {
		if (a.Length != b.Length) return false;
		for (int i = 0; i < a.Length; ++i) if (a[i] != b[i]) return false;
		return true;
	}

	static string ToString(int[] arr) {
		StringBuilder sb = new StringBuilder();
		sb.Append("[ ");
		for (int i = 0; i < arr.Length; ++i) {
			if (i > 0) sb.Append(", ");
			sb.Append(arr[i]);
		}
		return sb.ToString() + " ]";
	}

	public static void Main(string[] args){
		HashSet<int> cases = new HashSet<int>();
        for (int i = 0; i < args.Length; ++i) cases.Add(int.Parse(args[i]));

		Console.Error.WriteLine("Bonuses (250 Points)");
		Console.Error.WriteLine();

    	int nCases = 0, nPassed = 0;
    	using (var reader = File.OpenText("Bonuses.sample")) {
            while (true) {
                string line = reader.ReadLine();
                if (line == null || !line.StartsWith("--"))
                    break;

                int[] points = new int[int.Parse(reader.ReadLine())];
                for (int i = 0; i < points.Length; ++i)
                    points[i] = (int) Convert.ChangeType(reader.ReadLine(), typeof(int));
                reader.ReadLine();
                int[] __answer = new int[int.Parse(reader.ReadLine())];
                for (int i = 0; i < __answer.Length; ++i)
                    __answer[i] = (int) Convert.ChangeType(reader.ReadLine(), typeof(int));

                nCases++;
                if (cases.Count > 0 && !cases.Contains(nCases - 1))
                	continue;
                Console.Error.Write(string.Format("  Testcase #{0} ... ", nCases - 1));
                if (DoTest(points, __answer))
                    nPassed++;
            }
    	}

        if (cases.Count > 0) nCases = cases.Count;
		Console.Error.WriteLine();
		Console.Error.WriteLine(string.Format("Passed : {0}/{1} cases", nPassed, nCases));

		DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
		int T = (int)((DateTime.UtcNow - Jan1st1970).TotalSeconds - 1514300698);
		double PT = T / 60.0, TT = 75.0;
		Console.Error.WriteLine(string.Format("Time   : {0} minutes {1} secs", T / 60, T % 60));
		Console.Error.WriteLine(string.Format("Score  : {0:0.00} points", 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}
// CUT end
}
