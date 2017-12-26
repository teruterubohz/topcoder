using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

public class BinaryCode {
	public string[] decode(string message) {
        string p1 = "00";
        string p2 = "01";
        string ret1, ret2;

        for( int i = 1 ; i <= message.Length ; i++)
        {
            int p = int.Parse(message[i-1].ToString()) - int.Parse(p1[i - 1].ToString()) - int.Parse(p1[i].ToString());
            if (p > 1 || p < 0 )
            {
                p1 = "NONE";
                break;
            }
            p1 += p.ToString();
        }
        if (p1 != "NONE") ret1 = p1.Substring(1, message.Length);
        else ret1 = p1;


        for (int i = 1; i <= message.Length ; i++)
        {
            int p = int.Parse(message[i-1].ToString()) - int.Parse(p2[i - 1].ToString()) - int.Parse(p2[i].ToString());
            if (p > 1 || p < 0)
            {
                p2 = "NONE";
                break;
            }
            p2 += p.ToString();
        }
        if (p2 != "NONE") ret2 = p2.Substring(1, message.Length);
        else ret2 = p2;

        return new string[] {ret1,ret2};
	}

// CUT begin
	static bool DoTest(string message, string[] __expected) {
		DateTime startTime = DateTime.Now;
		Exception exception = null;
		BinaryCode instance = new BinaryCode();
		string[] __result = new string[] { };
		try {
			__result = instance.decode(message);
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

	static bool Equals(string[] a, string[] b) {
		if (a.Length != b.Length) return false;
		for (int i = 0; i < a.Length; ++i) if (a[i] == null || b[i] == null || a[i] != b[i]) return false;
		return true;
	}

	static string ToString(string[] arr) {
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

		Console.Error.WriteLine("BinaryCode (300 Points)");
		Console.Error.WriteLine();

    	int nCases = 0, nPassed = 0;
    	using (var reader = File.OpenText("BinaryCode.sample")) {
            while (true) {
                string line = reader.ReadLine();
                if (line == null || !line.StartsWith("--"))
                    break;

                string message = (string) Convert.ChangeType(reader.ReadLine(), typeof(string));
                reader.ReadLine();
                string[] __answer = new string[int.Parse(reader.ReadLine())];
                for (int i = 0; i < __answer.Length; ++i)
                    __answer[i] = (string) Convert.ChangeType(reader.ReadLine(), typeof(string));

                nCases++;
                if (cases.Count > 0 && !cases.Contains(nCases - 1))
                	continue;
                Console.Error.Write(string.Format("  Testcase #{0} ... ", nCases - 1));
                if (DoTest(message, __answer))
                    nPassed++;
            }
    	}

        if (cases.Count > 0) nCases = cases.Count;
		Console.Error.WriteLine();
		Console.Error.WriteLine(string.Format("Passed : {0}/{1} cases", nPassed, nCases));

		DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
		int T = (int)((DateTime.UtcNow - Jan1st1970).TotalSeconds - 1512229326);
		double PT = T / 60.0, TT = 75.0;
		Console.Error.WriteLine(string.Format("Time   : {0} minutes {1} secs", T / 60, T % 60));
		Console.Error.WriteLine(string.Format("Score  : {0:0.00} points", 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}
// CUT end
}
