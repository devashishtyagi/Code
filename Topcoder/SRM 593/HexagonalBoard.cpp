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
    vector< vector<int> > graph;    
    vector<int> visited;

    bool dfs(int v, int col, int l) {
        visited[v] = col;
        bool ans = true;
        for(int i = 0; i < graph[v].size(); i++) {
            int to = graph[v][i];
            if (visited[to] == -1) {
                ans &= dfs(to, (col+1)%l, l);
            }
            else {
                ans &= (visited[to] != col);
            }
        }
        return ans;
    }

    bool check(int limit) {
        fill(visited.begin(), visited.end(), -1);
        bool ans = true;
        for(int i = 0; i < graph.size(); i++) {
            if (visited[i] == -1) {
                ans &= dfs(i, 0, limit);
            }
        }
        return ans;
    }

    int minColors(vector<string> board) {
        int w = board.size(), h = board[0].size();
        int number[w][h];
        memset(number, -1, sizeof number);

        int avail = 0;
        for(int i = 0; i < w; i++) {
            for(int j = 0; j < h; j++) {
                if (board[i][j] == 'X')
                    number[i][j] = avail++;
            }
        }

        graph.resize(avail);
        visited.resize(avail);

        for(int i = 0; i < w; i++) {
            for(int j = 0; j < h; j++) {
                if (number[i][j] != -1) {
                    if (i > 0 && number[i-1][j] != -1) {
                        int a = number[i][j], b = number[i-1][j];
                        graph[a].push_back(b);
                        graph[b].push_back(a);
                    }
                    if (i > 0 && j < h-1 && number[i-1][j+1] != -1) {
                        int a = number[i][j], b = number[i-1][j+1];
                        graph[a].push_back(b);
                        graph[b].push_back(a);
                    }
                    if (j > 0 && number[i][j-1] != -1) {
                        int a = number[i][j], b = number[i][j-1];
                        graph[a].push_back(b);
                        graph[b].push_back(a);
                    }
                }
            }
        }

        cout<<"Done"<<endl;

        if (avail == 0) {
            return 0;
        }
        else if (check(1)) {
            return 1;
        }
        else if (check(2)) {
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
                "XXX-",
                "--X-",
                "----",
                "-X--"
            };
            int __expected = 2;
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
