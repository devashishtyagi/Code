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

#define MOD 1000000007

using namespace std;

class Spacetsk {
    public:
    int g[2001][2001];
    int C[2001][2001];
    int lines[2001];

    int countsets(int L, int H, int K) {
        memset(g, -1, sizeof g);
        memset(lines, 0, sizeof lines);
        memset(C, 0, sizeof C);

        for(int i = 0; i < 2001; i++) {
            g[0][i] = i; 
            g[i][0] = i;
        }

        for(int i = 1; i < 2001; i++) {
            for(int j = i; j < 2001; j++) {
                g[i][j] = g[j-i][i];
                g[j][i] = g[i][j];
            }
        }   

        for(int i = 0; i < 2001; i++) {
            C[i][0] = 1;
            for(int j = 1; j <= i; j++) {
                C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
            }
        }

        for(int p = 1; p <= H; p++) {
            int ty = H/p + 1;
            for(int q = 0; q <= L; q++) {
                if (g[p][q] != 1)
                    continue;
                if (q == 0) {
                    lines[ty] += L+1;
                }
                else {
                    for(int tx = 0; ; tx++) {
                        int lo = q*(tx-1);
                        int hi = min(q*tx, L+1);
                        if (lo > hi)
                            break;
                        int c = hi - lo;
                        lines[min(tx, ty)] += 2*c;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 1; i < 2001; i++) {
            ans = (ans + (lines[i]*1LL*C[i][K]%MOD))%MOD;
        }


        return ans;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int L, int H, int K, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Spacetsk *instance = new Spacetsk();
    int __result = instance->countsets(L, H, K);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
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
            int L = 1;
            int H = 1;
            int K = 2;
            int __expected = 4;
            return do_test(L, H, K, __expected, __no);
        }
        case 1: {
            int L = 1;
            int H = 1;
            int K = 1;
            int __expected = 4;
            return do_test(L, H, K, __expected, __no);
        }
        case 2: {
            int L = 2;
            int H = 2;
            int K = 1;
            int __expected = 9;
            return do_test(L, H, K, __expected, __no);
        }
        case 3: {
            int L = 2;
            int H = 2;
            int K = 2;
            int __expected = 23;
            return do_test(L, H, K, __expected, __no);
        }
        case 4: {
            int L = 5;
            int H = 5;
            int K = 3;
            int __expected = 202;
            return do_test(L, H, K, __expected, __no);
        }
        case 5: {
            int L = 561;
            int H = 394;
            int K = 20;
            int __expected = 786097180;
            return do_test(L, H, K, __expected, __no);
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
    cout << "Spacetsk (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380610937;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
