public class LittleElephantAndPermutationDiv1 {
	public int getNumber(int N, int K) {
		return 0;
	}

// CUT begin
	static void runTestcase(int __case) {
		switch (__case) {
			// Your custom testcase goes here
			case -1:
				//doTest(N, K, expected, __case);
				break;

			case 0: {
				int N = 1;
				int K = 1;
				int __excepted = 1;
				doTest(N, K, __excepted, __case);
				break;
			}
			case 1: {
				int N = 2;
				int K = 1;
				int __excepted = 4;
				doTest(N, K, __excepted, __case);
				break;
			}
			case 2: {
				int N = 3;
				int K = 8;
				int __excepted = 18;
				doTest(N, K, __excepted, __case);
				break;
			}
			case 3: {
				int N = 10;
				int K = 74;
				int __excepted = 484682624;
				doTest(N, K, __excepted, __case);
				break;
			}
			case 4: {
				int N = 50;
				int K = 1000;
				int __excepted = 539792695;
				doTest(N, K, __excepted, __case);
				break;
			}
			default: break;
		}
	}

	static void doTest(int N, int K, int __expected, int caseNo) {
		long startTime = System.currentTimeMillis();
		Throwable exception = null;
		LittleElephantAndPermutationDiv1 instance = new LittleElephantAndPermutationDiv1();
		int __result = 0;
		try {
			__result = instance.getNumber(N, K);
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

	static int nExample = 5;
	static int nAll = 0, nPassed = 0;

	public static void main(String[] args){
		System.err.println("LittleElephantAndPermutationDiv1 (500 Points)");
		System.err.println();
		if (args.length == 0)
			for (int i = 0; i < nExample; ++i) runTestcase(i);
		else
			for (int i = 0; i < args.length; ++i) runTestcase(Integer.parseInt(args[i]));
		System.err.println(String.format("%nPassed : %d/%d cases", nPassed, nAll));

		int T = (int)(System.currentTimeMillis() / 1000) - 1380526799;
		double PT = T / 60.0, TT = 75.0;
		System.err.println(String.format("Time   : %d minutes %d secs%nScore  : %.2f points", T / 60, T % 60, 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}
// CUT end
}
