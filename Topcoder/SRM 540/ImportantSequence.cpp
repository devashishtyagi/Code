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

class ImportantSequence {
    public:
    int getCount(vector<int> B, string operators) {
        vector<long long> upper;
        vector<long long> lower;

        lower.push_back(0);

        for(int i = 0; i < B.size(); i++) {
            char op = operators[i];
            long long value = B[i];
            for(int j = i+1; j < B.size(); j++) {
                char op2 = operators[j];
                if (op == '+') {
                    op = (op2 == '+') ? '-' : '+';
                    value -= B[j];
                }
                else {
                    op = op2;
                    value += B[j];
                }
            }
            if (op == '+') {
                upper.push_back(value);
            }
            else
                lower.push_back(-value);
        }

        if (upper.size() == 0)
            return -1;
        else {
            long long l = lower[0], u = upper[0];
            for(int i = 0; i < lower.size(); i++)
                l = max(l, lower[i]);
            for(int i = 0; i < upper.size(); i++)
                u = min(u, upper[i]);
            //cout<<u<<" "<<l<<endl;
            return (int)max(u-l-1, 0LL);
        }
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> B, string operators, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    ImportantSequence *instance = new ImportantSequence();
    int __result = instance->getCount(B, operators);
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
            int B[] = {
                3, -1, 7
            };
            string operators = "+-+";
            int __expected = 2;
            return do_test(to_vector(B), operators, __expected, __no);
        }
        case 1: {
            int B[] = {
                1
            };
            string operators = "-";
            int __expected = -1;
            return do_test(to_vector(B), operators, __expected, __no);
        }
        case 2: {
            int B[] = {
                1
            };
            string operators = "+";
            int __expected = 0;
            return do_test(to_vector(B), operators, __expected, __no);
        }
        case 3: {
            int B[] = {
                10
            };
            string operators = "+";
            int __expected = 9;
            return do_test(to_vector(B), operators, __expected, __no);
        }
        case 4: {
            int B[] = {
                540, 2012, 540, 2012, 540, 2012, 540
            };
            string operators = "-+-+-+-";
            int __expected = 1471;
            return do_test(to_vector(B), operators, __expected, __no);
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
    cout << "ImportantSequence (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1381223859;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
