import java.io.*;
import java.util.*;


public class BinaryCode {
//	private static final String NONE = "NONE";
	
	public String[] decode(String message) {
        String p1 = "00";
		String p2 = "01";
		String ret1 = "";
		String ret2 = "";

		for (int i = 1; i<= message.length();i++)
		{
			int encoded = Character.getNumericValue(message.charAt(i-1));
			int temp1 = Character.getNumericValue(p1.charAt(i-1));
			int temp2 = Character.getNumericValue(p1.charAt(i));
			int digit = encoded - temp1 - temp2;
			if( digit > 1 || digit < 0 )
			{
				p1 = "NONE";
				break;
			}
			p1 += String.valueOf(digit);
		}
		if( p1 != "NONE") ret1 = p1.substring(1, message.length()+1);
		else ret1 = p1;
			
		for (int i = 1; i<= message.length();i++)
		{
			int encoded = Character.getNumericValue(message.charAt(i-1));
			int temp1 = Character.getNumericValue(p2.charAt(i-1));
			int temp2 = Character.getNumericValue(p2.charAt(i));
			int digit = encoded - temp1 - temp2;
			if( digit > 1 || digit < 0 )
			{
				p2 = "NONE";
				break;
			}
			p2 += String.valueOf(digit);
		}
		if( p2 != "NONE") ret2 = p2.substring(1, message.length()+1);
		else ret2 = p2;

		return new String[]{ret1,ret2};
	}

// CUT begin
	public static void main(String[] args){
		System.err.println("BinaryCode (300 Points)");
		System.err.println();
		HashSet<Integer> cases = new HashSet<Integer>();
        for (int i = 0; i < args.length; ++i) cases.add(Integer.parseInt(args[i]));
        runTest(cases);
	}

	static void runTest(HashSet<Integer> caseSet) {
	    int cases = 0, passed = 0;
	    while (true) {
	    	String label = Reader.nextLine();
	    	if (label == null || !label.startsWith("--"))
	    		break;

            String message = Reader.nextLine();
            Reader.nextLine();
            String[] __answer = new String[Integer.parseInt(Reader.nextLine())];
            for (int i = 0; i < __answer.length; ++i)
                __answer[i] = Reader.nextLine();

            cases++;
            if (caseSet.size() > 0 && !caseSet.contains(cases - 1))
                continue;
    		System.err.print(String.format("  Testcase #%d ... ", cases - 1));

            if (doTest(message, __answer))
                passed++;
	    }
	    if (caseSet.size() > 0) cases = caseSet.size();
        System.err.println(String.format("%nPassed : %d/%d cases", passed, cases));

        int T = (int)(System.currentTimeMillis() / 1000) - 1512229330;
        double PT = T / 60.0, TT = 75.0;
        System.err.println(String.format("Time   : %d minutes %d secs%nScore  : %.2f points", T / 60, T % 60, 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}

	static boolean doTest(String message, String[] __expected) {
        message = new String(message);
		long startTime = System.currentTimeMillis();
		Throwable exception = null;
		BinaryCode instance = new BinaryCode();
		String[] __result = new String[0];
		try {
			__result = instance.decode(message);
		}
		catch (Throwable e) { exception = e; }
		double elapsed = (System.currentTimeMillis() - startTime) / 1000.0;

		if (exception != null) {
			System.err.println("RUNTIME ERROR!");
			exception.printStackTrace();
			return false;
		}
		else if (equals(__result, __expected)) {
			System.err.println("PASSED! " + String.format("(%.2f seconds)", elapsed));
			return true;
		}
		else {
			System.err.println("FAILED! " + String.format("(%.2f seconds)", elapsed));
			System.err.println("           Expected: " + toString(__expected));
			System.err.println("           Received: " + toString(__result));
			return false;
		}
	}

	static boolean equals(String[] a, String[] b) {
		if (a.length != b.length) return false;
		for (int i = 0; i < a.length; ++i) if (a[i] == null || b[i] == null || !a[i].equals(b[i])) return false;
		return true;
	}

	static String toString(String[] arr) {
		StringBuffer sb = new StringBuffer();
		sb.append("[ ");
		for (int i = 0; i < arr.length; ++i) {
			if (i > 0) sb.append(", ");
			sb.append(arr[i]);
		}
		return sb.toString() + " ]";
	}

	static class Reader {
        private static final String dataFileName = "BinaryCode.sample";
	    private static BufferedReader reader;

	    public static String nextLine() {
	        try {
                if (reader == null) {
                    reader = new BufferedReader(new InputStreamReader(new FileInputStream(dataFileName)));
                }
                return reader.readLine();
	        }
	        catch (IOException e) {
	            System.err.println("FATAL!! IOException");
	            e.printStackTrace();
	            System.exit(1);
	        }
	        return "";
	    }
	}
// CUT end
}
