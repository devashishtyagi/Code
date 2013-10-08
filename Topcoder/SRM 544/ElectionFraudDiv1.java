public class ElectionFraudDiv1 {
	public int MinimumVoters(int[] percentages) {
		return 0;
	}

// CUT begin
	static void runTestcase(int __case) {
		switch (__case) {
			// Your custom testcase goes here
			case -1:
				//doTest(percentages, expected, __case);
				break;

			case 0: {
				int percentages[] = new int[] {
					33, 33, 33
				};
				int __excepted = 3;
				doTest(percentages, __excepted, __case);
				break;
			}
			case 1: {
				int percentages[] = new int[] {
					29, 29, 43
				};
				int __excepted = 7;
				doTest(percentages, __excepted, __case);
				break;
			}
			case 2: {
				int percentages[] = new int[] {
					12, 12, 12, 12, 12, 12, 12, 12
				};
				int __excepted = -1;
				doTest(percentages, __excepted, __case);
				break;
			}
			case 3: {
				int percentages[] = new int[] {
					13, 13, 13, 13, 13, 13, 13, 13
				};
				int __excepted = 8;
				doTest(percentages, __excepted, __case);
				break;
			}
			case 4: {
				int percentages[] = new int[] {
					0, 1, 100
				};
				int __excepted = 200;
				doTest(percentages, __excepted, __case);
				break;
			}
			case 5: {
				int percentages[] = new int[] {
					3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4
				};
				int __excepted = 97;
				doTest(percentages, __excepted, __case);
				break;
			}
			default: break;
		}
	}

	static void doTest(int[] percentages, int __expected, int caseNo) {
		long startTime = System.currentTimeMillis();
		Throwable exception = null;
		ElectionFraudDiv1 instance = new ElectionFraudDiv1();
		int __result = 0;
		try {
			__result = instance.MinimumVoters(percentages);
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
		System.err.println("ElectionFraudDiv1 (275 Points)");
		System.err.println();
		if (args.length == 0)
			for (int i = 0; i < nExample; ++i) runTestcase(i);
		else
			for (int i = 0; i < args.length; ++i) runTestcase(Integer.parseInt(args[i]));
		System.err.println(String.format("%nPassed : %d/%d cases", nPassed, nAll));

		int T = (int)(System.currentTimeMillis() / 1000) - 1380686108;
		double PT = T / 60.0, TT = 75.0;
		System.err.println(String.format("Time   : %d minutes %d secs%nScore  : %.2f points", T / 60, T % 60, 275 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}
// CUT end
}
