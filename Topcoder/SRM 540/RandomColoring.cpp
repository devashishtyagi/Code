#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>

using namespace std;

class RandomColoring {
    public:
    double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
        return 0.0;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2, double __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    RandomColoring *instance = new RandomColoring();
    double __result = instance->getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            int N = 2;
            int maxR = 5;
            int maxG = 1;
            int maxB = 1;
            int startR = 2;
            int startG = 0;
            int startB = 0;
            int d1 = 0;
            int d2 = 1;
            double __expected = 0.0;
            return do_test(N, maxR, maxG, maxB, startR, startG, startB, d1, d2, __expected, __no);
        }
        case 1: {
            int N = 3;
            int maxR = 5;
            int maxG = 1;
            int maxB = 1;
            int startR = 2;
            int startG = 0;
            int startB = 0;
            int d1 = 0;
            int d2 = 1;
            double __expected = 0.22222222222222227;
            return do_test(N, maxR, maxG, maxB, startR, startG, startB, d1, d2, __expected, __no);
        }
        case 2: {
            int N = 7;
            int maxR = 4;
            int maxG = 2;
            int maxB = 2;
            int startR = 0;
            int startG = 0;
            int startB = 0;
            int d1 = 3;
            int d2 = 3;
            double __expected = 1.0;
            return do_test(N, maxR, maxG, maxB, startR, startG, startB, d1, d2, __expected, __no);
        }
        case 3: {
            int N = 10;
            int maxR = 7;
            int maxG = 8;
            int maxB = 9;
            int startR = 1;
            int startG = 2;
            int startB = 3;
            int d1 = 0;
            int d2 = 10;
            double __expected = 0.0;
            return do_test(N, maxR, maxG, maxB, startR, startG, startB, d1, d2, __expected, __no);
        }
        case 4: {
            int N = 10;
            int maxR = 7;
            int maxG = 8;
            int maxB = 9;
            int startR = 1;
            int startG = 2;
            int startB = 3;
            int d1 = 4;
            int d2 = 10;
            double __expected = 0.37826245943967396;
            return do_test(N, maxR, maxG, maxB, startR, startG, startB, d1, d2, __expected, __no);
        }
        case 5: {
            int N = 3;
            int maxR = 3;
            int maxG = 2;
            int maxB = 2;
            int startR = 1;
            int startG = 0;
            int startB = 0;
            int d1 = 1;
            int d2 = 2;
            double __expected = 0.09090909090909148;
            return do_test(N, maxR, maxG, maxB, startR, startG, startB, d1, d2, __expected, __no);
        }

        // Your custom testcase goes here
        case 6:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "RandomColoring (550 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1381224978;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
