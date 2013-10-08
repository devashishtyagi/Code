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

class MayTheBestPetWin {
    public:
    int calc(vector<int> A, vector<int> B) {
        bool dp[2][1000005];
        int base = 500002;
        memset(dp, false, sizeof dp);
        dp[0][base] = true;

        int n = A.size();
        
        int prev = 0, next = 1, sum = 2*base;

        for(int i = 0; i < n; i++) {
            sum += (B[i] - A[i]);
            memset(dp[next], false, sizeof dp[next]);
            for(int j = 0; j < 1000005; j++) {
                if (dp[prev][j] && j >= A[i]) {
                    int current = j - A[i];
                    int inverted = sum - current;
                    int possible = max(inverted, current);
                    dp[next][possible] |= dp[prev][j];
                }
                if (dp[prev][j]) {
                    int current = j + B[i];
                    int inverted = sum - current;
                    int possible = max(inverted, current);
                    dp[next][possible] |= dp[prev][j];
                }
            }
            swap(next, prev);
        }


        int minpossible = 0;
        for(int i = 0; i < n; i++)
            minpossible += B[i];
        

        for(int i = base; i < 1000005; i++) {
            if (dp[prev][i]) {
                minpossible = min(minpossible, i-base);
            }
        }


        return minpossible;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> A, vector<int> B, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    MayTheBestPetWin *instance = new MayTheBestPetWin();
    int __result = instance->calc(A, B);
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
            int A[] = {
                3, 4, 4, 7
            };
            int B[] = {
                3, 4, 4, 7
            };
            int __expected = 2;
            return do_test(to_vector(A), to_vector(B), __expected, __no);
        }
        case 1: {
            int A[] = {
                1, 3, 5, 4, 5
            };
            int B[] = {
                2, 5, 6, 8, 7
            };
            int __expected = 5;
            return do_test(to_vector(A), to_vector(B), __expected, __no);
        }
        case 2: {
            int A[] = {
                2907, 949, 1674, 6092, 8608, 5186, 2630, 970, 1050, 2415, 1923, 2697, 5571, 6941, 8065, 4710, 716, 756, 5185, 1341, 993, 5092, 248, 1895, 4223, 1783, 3844, 3531, 2431, 1755, 2837, 4015
            };
            int B[] = {
                7296, 6954, 4407, 9724, 8645, 8065, 9323, 8433, 1352, 9618, 6487, 7309, 9297, 8999, 9960, 5653, 4721, 7623, 6017, 7320, 3513, 6642, 6359, 3145, 7233, 5077, 6457, 3605, 2911, 4679, 5381, 6574
            };
            int __expected = 52873;
            return do_test(to_vector(A), to_vector(B), __expected, __no);
        }

        // Your custom testcase goes here
        case 3:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "MayTheBestPetWin (450 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 3; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380989884;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
