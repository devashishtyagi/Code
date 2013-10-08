public class StrIIRec {
	public String recovstr(int n, int minInv, String minStr) {
		return "";
	}

// CUT begin
	static void runTestcase(int __case) {
		switch (__case) {
			// Your custom testcase goes here
			case -1:
				//doTest(n, minInv, minStr, expected, __case);
				break;

			case 0: {
				int n = 2;
				int minInv = 1;
				String minStr = "ab";
				String __excepted = "ba";
				doTest(n, minInv, minStr, __excepted, __case);
				break;
			}
			case 1: {
				int n = 9;
				int minInv = 1;
				String minStr = "efcdgab";
				String __excepted = "efcdgabhi";
				doTest(n, minInv, minStr, __excepted, __case);
				break;
			}
			case 2: {
				int n = 11;
				int minInv = 55;
				String minStr = "debgikjfc";
				String __excepted = "kjihgfedcba";
				doTest(n, minInv, minStr, __excepted, __case);
				break;
			}
			case 3: {
				int n = 15;
				int minInv = 0;
				String minStr = "e";
				String __excepted = "eabcdfghijklmno";
				doTest(n, minInv, minStr, __excepted, __case);
				break;
			}
			case 4: {
				int n = 9;
				int minInv = 20;
				String minStr = "fcdebiha";
				String __excepted = "fcdehigba";
				doTest(n, minInv, minStr, __excepted, __case);
				break;
			}
			default: break;
		}
	}

	static void doTest(int n, int minInv, String minStr, String __expected, int caseNo) {
		long startTime = System.currentTimeMillis();
		Throwable exception = null;
		StrIIRec instance = new StrIIRec();
		String __result = "";
		try {
			__result = instance.recovstr(n, minInv, minStr);
		}
		catch (Throwable e) { exception = e; }
		double elapsed = (System.currentTimeMillis() - startTime) / 1000.0;

		nAll++;
		System.err.print(String.format("  Testcase #%d ... ", caseNo));

		if (exception != null) {
			System.err.println("RUNTIME ERROR!");
			exception.printStackTrace();
		}
		else if (__expected.equals(__result)) {
			System.err.println("PASSED! " + String.format("(%.2f seconds)", elapsed));
			nPassed++;
		}
		else {
			System.err.println("FAILED! " + String.format("(%.2f seconds)", elapsed));
			System.err.println("           Expected: " + __expected);
			System.err.println("           Received: " + __result);
		}
	}

	static int nExample = 5;
	static int nAll = 0, nPassed = 0;

	public static void main(String[] args){
		System.err.println("StrIIRec (275 Points)");
		System.err.println();
		if (args.length == 0)
			for (int i = 0; i < nExample; ++i) runTestcase(i);
		else
			for (int i = 0; i < args.length; ++i) runTestcase(Integer.parseInt(args[i]));
		System.err.println(String.format("%nPassed : %d/%d cases", nPassed, nAll));

		int T = (int)(System.currentTimeMillis() / 1000) - 1380599684;
		double PT = T / 60.0, TT = 75.0;
		System.err.println(String.format("Time   : %d minutes %d secs%nScore  : %.2f points", T / 60, T % 60, 275 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}
// CUT end
}
