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

class FlipGame {
    public:
    int minOperations(vector<string> board) {
        int w = board.size(), h = board[0].size();
        int steps = -1, req = 0;
        
        do {    
            req = 0;
            steps++;
            for(int i = 0; i < w; i++) {
                for(int j = req; j < h; j++) {
                    if (board[i][j] == '1')
                        req = j+1;
                }
                for(int j = 0; j < req; j++) {
                    board[i][j] = (board[i][j] == '1' ? '0' : '1');
                }
            }

        } while(req != 0);

        return steps;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> board, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FlipGame *instance = new FlipGame();
    int __result = instance->minOperations(board);
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
            string board[] = {
                "1000",
                "1110",
                "1111"
            };
            int __expected = 1;
            return do_test(to_vector(board), __expected, __no);
        }
        case 1: {
            string board[] = {
                "1111",
                "1111",
                "1111"
            };
            int __expected = 1;
            return do_test(to_vector(board), __expected, __no);
        }
        case 2: {
            string board[] = {
                "00",
                "00",
                "00"
            };
            int __expected = 0;
            return do_test(to_vector(board), __expected, __no);
        }
        case 3: {
            string board[] = {
                "00000000",
                "00100000",
                "01000000",
                "00001000",
                "00000000"
            };
            int __expected = 4;
            return do_test(to_vector(board), __expected, __no);
        }
        case 4: {
            string board[] = {
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
            int __expected = 29;
            return do_test(to_vector(board), __expected, __no);
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
    cout << "FlipGame (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380692687;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
