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

class StrIIRec {
public:
    string ref;
    string ans;
    int N;

    void solve(int n, int inv, int p) {
        
        if (n >= N)
            return;
        char lowerlimit = (p == 0) ? ref[n] : 'a';

        vector<int> taken(26, false);
        for(int i = 0; i < n; i++)
            taken[ans[i]-'a'] = true;

        int pos = lowerlimit-'a';
        for(int c = pos; c < 26; c++) {
            if (!taken[c]) {
                int count = 0;
                for(int i = 0; i < c; i++)
                    if (taken[i])
                        count++;
                int newinv = max(inv - c + count, 0);
                if (newinv <= ((N-n-1)*(N-n-2))/2) {
                    ans[n] = c+'a';
                    if (c > pos)
                        solve(n+1, newinv, 1);
                    else
                        solve(n+1, newinv, p);
                    break;
                }
            }
        }
    }

    string recovstr(int n, int minInv, string minStr) {
        ref = minStr;
        vector<int> taken(26, false);
        for(int i = 0; i < ref.size(); i++) 
            taken[ref[i]-'a'] = true;
        for(int i = 0; i < n; i++) 
            if (!taken[i])
                ref.push_back(i+'a');

        N = n;
        ans.resize(n);
        solve(0, minInv, 0);

        return ans;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(int n, int minInv, string minStr, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    StrIIRec *instance = new StrIIRec();
    string __result = instance->recovstr(n, minInv, minStr);
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
            int n = 2;
            int minInv = 1;
            string minStr = "ab";
            string __expected = "ba";
            return do_test(n, minInv, minStr, __expected, __no);
        }
        case 1: {
            int n = 9;
            int minInv = 1;
            string minStr = "efcdgab";
            string __expected = "efcdgabhi";
            return do_test(n, minInv, minStr, __expected, __no);
        }
        case 2: {
            int n = 11;
            int minInv = 55;
            string minStr = "debgikjfc";
            string __expected = "kjihgfedcba";
            return do_test(n, minInv, minStr, __expected, __no);
        }
        case 3: {
            int n = 15;
            int minInv = 0;
            string minStr = "e";
            string __expected = "eabcdfghijklmno";
            return do_test(n, minInv, minStr, __expected, __no);
        }
        case 4: {
            int n = 9;
            int minInv = 20;
            string minStr = "fcdebiha";
            string __expected = "fcdehigba";
            return do_test(n, minInv, minStr, __expected, __no);
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
    cout << "StrIIRec (275 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380600501;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 275 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
