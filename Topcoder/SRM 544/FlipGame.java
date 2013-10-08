public class FlipGame {
	public int minOperations(String[] board) {
		return 0;
	}

// CUT begin
	static void runTestcase(int __case) {
		switch (__case) {
			// Your custom testcase goes here
			case -1:
				//doTest(board, expected, __case);
				break;

			case 0: {
				String board[] = new String[] {
					"1000",
					"1110",
					"1111"
				};
				int __excepted = 1;
				doTest(board, __excepted, __case);
				break;
			}
			case 1: {
				String board[] = new String[] {
					"1111",
					"1111",
					"1111"
				};
				int __excepted = 1;
				doTest(board, __excepted, __case);
				break;
			}
			case 2: {
				String board[] = new String[] {
					"00",
					"00",
					"00"
				};
				int __excepted = 0;
				doTest(board, __excepted, __case);
				break;
			}
			case 3: {
				String board[] = new String[] {
					"00000000",
					"00100000",
					"01000000",
					"00001000",
					"00000000"
				};
				int __excepted = 4;
				doTest(board, __excepted, __case);
				break;
			}
			case 4: {
				String board[] = new String[] {
					"000000000000001100000000000000",
					"000000000000011110000000000000",
					"000000000000111111000000000000",
					"000000000001111111100000000000",
					"000000000011111111110000000000",
					"000000000111111111111000000000",
					"000000001100111111001100000000",
					"000000011000011110000110000000",
					"000000111100111111001111000000",
					"000001111111111111111111100000",
					"000011111111111111111111110000",
					"000111111111000000111111111000",
					"001111111111100001111111111100",
					"011111111111110011111111111110",
					"111111111111111111111111111111"
				};
				int __excepted = 29;
				doTest(board, __excepted, __case);
				break;
			}
			default: break;
		}
	}

	static void doTest(String[] board, int __expected, int caseNo) {
		long startTime = System.currentTimeMillis();
		Throwable exception = null;
		FlipGame instance = new FlipGame();
		int __result = 0;
		try {
			__result = instance.minOperations(board);
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
		System.err.println("FlipGame (500 Points)");
		System.err.println();
		if (args.length == 0)
			for (int i = 0; i < nExample; ++i) runTestcase(i);
		else
			for (int i = 0; i < args.length; ++i) runTestcase(Integer.parseInt(args[i]));
		System.err.println(String.format("%nPassed : %d/%d cases", nPassed, nAll));

		int T = (int)(System.currentTimeMillis() / 1000) - 1380691233;
		double PT = T / 60.0, TT = 75.0;
		System.err.println(String.format("Time   : %d minutes %d secs%nScore  : %.2f points", T / 60, T % 60, 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))));
	}
// CUT end
}
