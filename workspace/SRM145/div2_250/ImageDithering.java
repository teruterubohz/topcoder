import java.io.*;
import java.util.*;

public class ImageDithering {
	public int count(String dithered, String[] screen) {
		int rtn = 0;

		for( int j = 0 ; j < screen.length ; j++ ){
			char[] charArray = screen[j].toCharArray();
			for( char ch : charArray ){
				if( dithered.contains(String.valueOf(ch))){
					rtn++;
				}
			}
		}
		return rtn;
	}

// CUT begin
	public static void main(String[] args){
		System.err.println("ImageDithering (250 Points)");
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

            String dithered = Reader.nextLine();
            String[] screen = new String[Integer.parseInt(Reader.nextLine())];
            for (int i = 0; i < screen.length; ++i)
                screen[i] = Reader.nextLine();
            Reader.nextLine();
            int __answer = Integer.parseInt(Reader.nextLine());

            cases++;
            if (caseSet.size() > 0 && !caseSet.contains(cases - 1))
                continue;
    		System.err.print(String.format("  Testcase #%d ... ", cases - 1));

            if (doTest(dithered, screen, __answer))
                passed++;
	    }
	    if (caseSet.size() > 0) cases = caseSet.size();
        System.err.println(String.format("%nPassed : %d/%d cases", passed, cases));

        int T = (int)(System.currentTimeMillis() / 1000) - 1513439308;
        double PT = T / 60.0, TT = 75.0;
        System.err.println(String.format("Time   : %d minutes %d secs%nScore  : %.2f points", T / 60, T % 60, 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}

	static boolean doTest(String dithered, String[] screen, int __expected) {
        dithered = new String(dithered);
		for (int i = 0; i < screen.length; i++) {
			screen[i] = new String(screen[i]);
		}
		long startTime = System.currentTimeMillis();
		Throwable exception = null;
		ImageDithering instance = new ImageDithering();
		int __result = 0;
		try {
			__result = instance.count(dithered, screen);
		}
		catch (Throwable e) { exception = e; }
		double elapsed = (System.currentTimeMillis() - startTime) / 1000.0;

		if (exception != null) {
			System.err.println("RUNTIME ERROR!");
			exception.printStackTrace();
			return false;
		}
		else if (__result == __expected) {
			System.err.println("PASSED! " + String.format("(%.2f seconds)", elapsed));
			return true;
		}
		else {
			System.err.println("FAILED! " + String.format("(%.2f seconds)", elapsed));
			System.err.println("           Expected: " + __expected);
			System.err.println("           Received: " + __result);
			return false;
		}
	}

	static class Reader {
        private static final String dataFileName = "ImageDithering.sample";
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
