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

class LittleElephantAndPermutationDiv1 {
public:
    int dp[51][51][2501];
    bool seen[51][51][2501];
    int n, k;
    
    int solve(int x, int fx, int sum) {
        if (x == n+1) {
            if (fx == 0 && sum >= k)
                return 1;
            else
                return 0;
        }   

        if (seen[x][fx][sum])
            return dp[x][fx][sum];

        seen[x][fx][sum] = true;

        int &ret = dp[x][fx][sum];
        ret = 0;

        ret = (ret + solve(x+1, fx+1, sum))%MOD;
        ret = (ret + solve(x+1, fx, sum+x))%MOD;
        if (fx > 0)
            ret = (ret + solve(x+1, fx-1, sum + 2*x)*1LL*fx*fx%MOD)%MOD;
        ret = (ret + solve(x+1, fx, sum + x)*1LL*2*fx%MOD)%MOD;

        return ret; 
    }

    int getNumber(int _N, int _K) {
        memset(dp, 0, sizeof dp);
        memset(seen, false, sizeof seen);
        n = _N; k = _K;
        int ans = solve(1, 0, 0);

        for(int i = 1; i <= n; i++)
            ans = ans*1LL*i%MOD;

        return ans;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int N, int K, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    LittleElephantAndPermutationDiv1 *instance = new LittleElephantAndPermutationDiv1();
    int __result = instance->getNumber(N, K);
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
            int N = 1;
            int K = 1;
            int __expected = 1;
            return do_test(N, K, __expected, __no);
        }
        case 1: {
            int N = 2;
            int K = 1;
            int __expected = 4;
            return do_test(N, K, __expected, __no);
        }
        case 2: {
            int N = 3;
            int K = 8;
            int __expected = 18;
            return do_test(N, K, __expected, __no);
        }
        case 3: {
            int N = 10;
            int K = 74;
            int __expected = 484682624;
            return do_test(N, K, __expected, __no);
        }
        case 4: {
            int N = 50;
            int K = 1000;
            int __expected = 539792695;
            return do_test(N, K, __expected, __no);
        }

        // Your custom testcase goes here
        case 5:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "LittleElephantAndPermutationDiv1 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380526799;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
