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

class PatrolRoute {
public:
    int n[8001];
    long long p[8001];

    long long sumP(int l, int r) {
        l = min(max(l, 1), 8000);
        r = min(max(r, 1), 8000);
        if (l > r)
            return 0LL;
        return p[r]-p[l-1];
    }

    int countRoutes(int X, int Y, int minT, int maxT) {
        memset(n, 0, sizeof n);
        memset(p, 0, sizeof p);

        for(int i = 4; i < 8001; i += 2){
            int d = i/2;
            int cand = max(X-d, 0);
            n[i] = cand*(d-1);
        }

        for(int i = 4; i < 8001; i += 2) {
            int d = i/2;
            int cand = max(Y-d, 0);
            p[i] = cand*(d-1);
        }

        for(int i = 1; i < 8001; i++)
            p[i] += p[i-1];

        //cout<<n[4]<<" "<<p[4]<<" "<<n[6]<<" "<<p[6]<<endl;

        long long ans = 0;
        for(int i = 4; i < 8001; i += 2) {
            ans = (ans + sumP(minT-i, maxT-i)*6LL*n[i]%MOD)%MOD;
        }

        return (int)ans;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int X, int Y, int minT, int maxT, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    PatrolRoute *instance = new PatrolRoute();
    int __result = instance->countRoutes(X, Y, minT, maxT);
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
            int X = 3;
            int Y = 3;
            int minT = 1;
            int maxT = 20000;
            int __expected = 6;
            return do_test(X, Y, minT, maxT, __expected, __no);
        }
        case 1: {
            int X = 3;
            int Y = 3;
            int minT = 4;
            int maxT = 7;
            int __expected = 0;
            return do_test(X, Y, minT, maxT, __expected, __no);
        }
        case 2: {
            int X = 4;
            int Y = 6;
            int minT = 9;
            int maxT = 12;
            int __expected = 264;
            return do_test(X, Y, minT, maxT, __expected, __no);
        }
        case 3: {
            int X = 7;
            int Y = 5;
            int minT = 13;
            int maxT = 18;
            int __expected = 1212;
            return do_test(X, Y, minT, maxT, __expected, __no);
        }
        case 4: {
            int X = 4000;
            int Y = 4000;
            int minT = 4000;
            int maxT = 14000;
            int __expected = 859690013;
            return do_test(X, Y, minT, maxT, __expected, __no);
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
    cout << "PatrolRoute (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380855615;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
