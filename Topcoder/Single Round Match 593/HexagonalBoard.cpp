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

class HexagonalBoard {
    public:
        
    bool check(vector<string>& board, int limit) {
        int w = board.size(), h = board[0].size();
        int color[w][h];
        memset(color, -1, sizeof color);

        for(int i = 0; i < w; i++) {
            for(int j = 0; j < h; j++) {
                if (board[i][j] == 'X') {
                    int col[] = {-1, -1, -1};
                    if (i > 0)
                        col[0] = color[i-1][j];
                    if (i > 0 && j < h-1)
                        col[1] = color[i-1][j+1];
                    if (j > 0)
                        col[2] = color[i][j-1];
                    int pos = -1;
                    for(int k = 0; k < limit; k++) {
                        bool found = false;
                        for(int l = 0; l < 3; l++) {
                            if (col[l] == k) {
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            pos = k;
                            break;
                        }
                    }
                    if (pos == -1)
                        return false;
                    color[i][j] = pos;
                }
            }
        }
        return true;
    }

    int minColors(vector<string> board) {
        if (check(board, 0)) {
            return 0;
        }
        else if (check(board, 1)) {
            return 1;
        }
        else if (check(board, 2)) {
            return 2;
        }
        else
            return 3;
        return 0;
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
    HexagonalBoard *instance = new HexagonalBoard();
    int __result = instance->minColors(board);
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
                "---",
                "---",
                "---"
            };
            int __expected = 0;
            return do_test(to_vector(board), __expected, __no);
        }
        case 1: {
            string board[] = {
                "-X--",
                "---X",
                "----",
                "-X--"
            };
            int __expected = 1;
            return do_test(to_vector(board), __expected, __no);
        }
        case 2: {
            string board[] = {
                "XXXX",
                "---X",
                "---X",
                "---X"
            };
            int __expected = 2;
            return do_test(to_vector(board), __expected, __no);
        }
        case 3: {
            string board[] = {
                "XX-XX--",
                "-XX-XXX",
                "X-XX--X",
                "X--X-X-",
                "XX-X-XX",
                "-X-XX-X",
                "-XX-XX-"
            };
            int __expected = 3;
            return do_test(to_vector(board), __expected, __no);
        }

        // Your custom testcase goes here
        case 4:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "HexagonalBoard (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 4; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1380988775;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
