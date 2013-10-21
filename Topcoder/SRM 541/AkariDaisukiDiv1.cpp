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
#define limit 50

using namespace std;

class AkariDaisukiDiv1 {
public:
    string C, S, F;
    long long len[limit];

    char get(int k, long long p) {
        if (k == 0) {
            if (p >= S.length())
                return '-';
            else
                return S[(int)p];
        }

        long long x = len[k-1];

        for(int i = 0; i < C.length(); i++) {
            if (C[i] == '*') {
                if (p < x)
                    return get(k-1, p);
                else
                    p -= x;
            }
            else if (p == 0)
                return C[i];
            else
                p--;
        }

        return '-';
    }

    int A(int k) {
        vector<long long> valid;

        long long x = len[k-1];
        long long p = 0;

        for(int i = 0; i < C.size(); i++) {
            if (C[i] == '*') {
                for(int j = 1; j < F.length() && j <= x; j++)
                    valid.push_back(p+x-j);
                p += x;
            }
            else {
                valid.push_back(p);
                p++;
            }
        }

        int ans = 0;

        for(int i = 0; i < valid.size(); i++) {
            long long v = valid[i];
            bool ok = true;
            for(int j = 0; j < F.length() && ok; j++) {
                //cout<<k<<" "<<v+j<<" "<<get(k, v+j)<<endl;
                ok &= (get(k, v+j) == F[j]);
            }
            if (ok)
                ans++;
        }

        return ans;
    }

    int countF(string L, string M, string R, string S, string F, int k) {
        this->S = S;
        this->F = F;
        C = L+"*"+M+"*"+R;
        len[0] = S.length();
        int b = C.length()-2;

        for(int i = 1; i < limit; i++) {
            len[i] = 2*len[i-1] + b; 
        }
        
        int ans = 0;
        for(int i = 0; i <= (int)S.length()-(int)F.length(); i++) {
            ans += (S.substr(i, F.length()) == F);
        }
        

        int a = 0;
        for(int i = 1; i <= k; i++) {
            if (i < limit) {
                a = A(i);
                //cout<<i<<" "<<a<<endl;
            }
            ans = (2LL*ans+a)%MOD;
        }

        return ans;
    }
};

// CUT begin
template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(string Waai, string Akari, string Daisuki, string S, string F, int k, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    AkariDaisukiDiv1 *instance = new AkariDaisukiDiv1();
    int __result = instance->countF(Waai, Akari, Daisuki, S, F, k);
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
            string Waai = "a";
            string Akari = "b";
            string Daisuki = "c";
            string S = "x";
            string F = "axb";
            int k = 2;
            int __expected = 2;
            return do_test(Waai, Akari, Daisuki, S, F, k, __expected, __no);
        }
        case 1: {
            string Waai = "a";
            string Akari = "b";
            string Daisuki = "c";
            string S = "x";
            string F = "abcdefghij";
            int k = 1;
            int __expected = 0;
            return do_test(Waai, Akari, Daisuki, S, F, k, __expected, __no);
        }
        case 2: {
            string Waai = "a";
            string Akari = "a";
            string Daisuki = "a";
            string S = "b";
            string F = "aba";
            int k = 2;
            int __expected = 4;
            return do_test(Waai, Akari, Daisuki, S, F, k, __expected, __no);
        }
        case 3: {
            string Waai = "a";
            string Akari = "b";
            string Daisuki = "c";
            string S = "d";
            string F = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba";
            int k = 58;
            int __expected = 191690599;
            return do_test(Waai, Akari, Daisuki, S, F, k, __expected, __no);
        }
        case 4: {
            string Waai = "a";
            string Akari = "x";
            string Daisuki = "y";
            string S = "b";
            string F = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
            int k = 49;
            int __expected = 1;
            return do_test(Waai, Akari, Daisuki, S, F, k, __expected, __no);
        }
        case 5: {
            string Waai = "waai";
            string Akari = "akari";
            string Daisuki = "daisuki";
            string S = "usushio";
            string F = "id";
            int k = 10000000;
            int __expected = 127859200;
            return do_test(Waai, Akari, Daisuki, S, F, k, __expected, __no);
        }
        case 6: {
            string Waai = "vfsebgjfyfgerkqlr";
            string Akari = "ezbiwls";
            string Daisuki = "kjerx";
            string S = "jbmjvaawoxycfndukrjfg";
            string F = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs";
            int k = 1575724;
            int __expected = 483599313;
            return do_test(Waai, Akari, Daisuki, S, F, k, __expected, __no);
        }

        // Your custom testcase goes here
        case 7:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "AkariDaisukiDiv1 (550 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1381203775;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
