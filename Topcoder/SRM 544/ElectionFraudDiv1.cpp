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

class ElectionFraudDiv1 {
    public:
    vector<int> p;

    int minPos(int x, int p) {
        if (p*x - x/2 < 0)
            return 0;
        if ((p*x-x/2)%100 == 0)
            return (p*x-x/2)/100;
        else
            return (p*x-x/2)/100+1;
    }

    bool check(int x) {
        int minsum = 0, maxsum = 0;
        for(int i = 0; i < p.size(); i++) {
            int a = minPos(x, p[i]);
            int b = minPos(x, p[i]+1)-1;
            if (a > b)
                return false;
            minsum += a;
            maxsum += b;
        }
        if (x >= minsum && x <= maxsum)
            return true;
        else
            return false;
    }

    int MinimumVoters(vector<int> percentages) {
        p = percentages;
        for(int i = 1; i < 25001; i++) {
            if (check(i)) {
                cout<<i<<endl;
                return i;
            }
        }

        return -1;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> percentages, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    ElectionFraudDiv1 *instance = new ElectionFraudDiv1();
    int __result = instance->MinimumVoters(percentages);
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
            int percentages[] = {
                33, 33, 33
            };
            int __expected = 3;
            return do_test(to_vector(percentages), __expected, __no);
        }
        case 1: {
            int percentages[] = {
                29, 29, 43
            };
            int __expected = 7;
            return do_test(to_vector(percentages), __expected, __no);
        }
        case 2: {
            int percentages[] = {
                12, 12, 12, 12, 12, 12, 12, 12
            };
            int __expected = -1;
            return do_test(to_vector(percentages), __expected, __no);
        }
        case 3: {
            int percentages[] = {
                13, 13, 13, 13, 13, 13, 13, 13
            };
            int __expected = 8;
            return do_test(to_vector(percentages), __expected, __no);
        }
        case 4: {
            int percentages[] = {
                0, 1, 100
            };
            int __expected = 200;
            return do_test(to_vector(percentages), __expected, __no);
        }
        case 5: {
            int percentages[] = {
                3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4
            };
            int __expected = 97;
            return do_test(to_vector(percentages), __expected, __no);
        }

        // Your custom testcase goes here
        case 6:{
            int percentages[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
            int __expected = 200;
            return do_test(to_vector(percentages), __expected, __no);
        }
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "ElectionFraudDiv1 (275 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380686120;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 275 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
