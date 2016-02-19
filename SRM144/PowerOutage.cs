using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

public class PowerOutage {
	public int estimateTimeOut(int[] fromJunction, int[] toJunction, int[] ductLength) {
		return 0;
	}

// CUT begin
	static bool DoTest(int[] fromJunction, int[] toJunction, int[] ductLength, int __expected) {
		DateTime startTime = DateTime.Now;
		Exception exception = null;
		PowerOutage instance = new PowerOutage();
		int __result = 0;
		try {
			__result = instance.estimateTimeOut(fromJunction, toJunction, ductLength);
		}
		catch (Exception e) { exception = e; }
		TimeSpan __elapsed = new TimeSpan(DateTime.Now.Ticks - startTime.Ticks);

		if (exception != null) {
			Console.Error.WriteLine("RUNTIME ERROR!");
			Console.Error.WriteLine(exception);
			return false;
		}
		else if (__result == __expected) {
			Console.Error.WriteLine("PASSED! " + string.Format("({0:0.00} seconds)", __elapsed.TotalSeconds));
			return true;
		}
		else {
			Console.Error.WriteLine("FAILED! " + string.Format("({0:0.00} seconds)", __elapsed.TotalSeconds));
			Console.Error.WriteLine("           Expected: " + __expected);
			Console.Error.WriteLine("           Received: " + __result);
			return false;
		}
	}

	public static void Main(string[] args){
		HashSet<int> cases = new HashSet<int>();
        for (int i = 0; i < args.Length; ++i) cases.Add(int.Parse(args[i]));

		Console.Error.WriteLine("PowerOutage (1100 Points)");
		Console.Error.WriteLine();

    	int nCases = 0, nPassed = 0;
    	using (var reader = File.OpenText("..\\..\\..\\..\\SRM144\\PowerOutage.sample")) {
            while (true) {
                string line = reader.ReadLine();
                if (line == null || !line.StartsWith("--"))
                    break;

                int[] fromJunction = new int[int.Parse(reader.ReadLine())];
                for (int i = 0; i < fromJunction.Length; ++i)
                    fromJunction[i] = (int) Convert.ChangeType(reader.ReadLine(), typeof(int));
                int[] toJunction = new int[int.Parse(reader.ReadLine())];
                for (int i = 0; i < toJunction.Length; ++i)
                    toJunction[i] = (int) Convert.ChangeType(reader.ReadLine(), typeof(int));
                int[] ductLength = new int[int.Parse(reader.ReadLine())];
                for (int i = 0; i < ductLength.Length; ++i)
                    ductLength[i] = (int) Convert.ChangeType(reader.ReadLine(), typeof(int));
                reader.ReadLine();
                int __answer = (int) Convert.ChangeType(reader.ReadLine(), typeof(int));

                nCases++;
                if (cases.Count > 0 && !cases.Contains(nCases - 1))
                	continue;
                Console.Error.Write(string.Format("  Testcase #{0} ... ", nCases - 1));
                if (DoTest(fromJunction, toJunction, ductLength, __answer))
                    nPassed++;
            }
    	}

        if (cases.Count > 0) nCases = cases.Count;
		Console.Error.WriteLine();
		Console.Error.WriteLine(string.Format("Passed : {0}/{1} cases", nPassed, nCases));

		DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
		int T = (int)((DateTime.UtcNow - Jan1st1970).TotalSeconds - 1455864129);
		double PT = T / 60.0, TT = 75.0;
		Console.Error.WriteLine(string.Format("Time   : {0} minutes {1} secs", T / 60, T % 60));
		Console.Error.WriteLine(string.Format("Score  : {0:0.00} points", 1100 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}
// CUT end
}
