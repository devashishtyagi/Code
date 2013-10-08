public class Spacetsk {
	public int countsets(int L, int H, int K) {
		return 0;
	}

// CUT begin
	static void runTestcase(int __case) {
		switch (__case) {
			// Your custom testcase goes here
			case -1:
				//doTest(L, H, K, expected, __case);
				break;

			case 0: {
				int L = 1;
				int H = 1;
				int K = 2;
				int __excepted = 4;
				doTest(L, H, K, __excepted, __case);
				break;
			}
			case 1: {
				int L = 1;
				int H = 1;
				int K = 1;
				int __excepted = 4;
				doTest(L, H, K, __excepted, __case);
				break;
			}
			case 2: {
				int L = 2;
				int H = 2;
				int K = 1;
				int __excepted = 9;
				doTest(L, H, K, __excepted, __case);
				break;
			}
			case 3: {
				int L = 2;
				int H = 2;
				int K = 2;
				int __excepted = 23;
				doTest(L, H, K, __excepted, __case);
				break;
			}
			case 4: {
				int L = 5;
				int H = 5;
				int K = 3;
				int __excepted = 202;
				doTest(L, H, K, __excepted, __case);
				break;
			}
			case 5: {
				int L = 561;
				int H = 394;
				int K = 20;
				int __excepted = 786097180;
				doTest(L, H, K, __excepted, __case);
				break;
			}
			default: break;
		}
	}

	static void doTest(int L, int H, int K, int __expected, int caseNo) {
		long startTime = System.currentTimeMillis();
		Throwable exception = null;
		Spacetsk instance = new Spacetsk();
		int __result = 0;
		try {
			__result = instance.countsets(L, H, K);
		}
		catch (Throwable e) { exception = e; }
		double elapsed = (System.currentTimeMillis() - startTime) / 1000.0;

		nAll++;
		System.err.print(String.format("  Testcase #%d ... ", caseNo));

		if (exception != null) {
			System.err.println("RUNTIME ERROR!");
			exception.printStackTrace();
		}
		else if (__result == __expected) {
			System.err.println("PASSED! " + String.format("(%.2f seconds)", elapsed));
			nPassed++;
		}
		else {
			System.err.println("FAILED! " + String.format("(%.2f seconds)", elapsed));
			System.err.println("           Expected: " + __expected);
			System.err.println("           Received: " + __result);
		}
	}

	static int nExample = 6;
	static int nAll = 0, nPassed = 0;

	public static void main(String[] args){
		System.err.println("Spacetsk (500 Points)");
		System.err.println();
		if (args.length == 0)
			for (int i = 0; i < nExample; ++i) runTestcase(i);
		else
			for (int i = 0; i < args.length; ++i) runTestcase(Integer.parseInt(args[i]));
		System.err.println(String.format("%nPassed : %d/%d cases", nPassed, nAll));

		int T = (int)(System.currentTimeMillis() / 1000) - 1380610934;
		double PT = T / 60.0, TT = 75.0;
		System.err.println(String.format("Time   : %d minutes %d secs%nScore  : %.2f points", T / 60, T % 60, 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}
// CUT end
}
