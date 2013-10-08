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

#define INF 1000000

using namespace std;

class AntsMeet {
    public:
    int give(char c) {
        switch(c){
            case 'N': return 0;
            case 'S': return 1;
            case 'E': return 2;
            case 'W': return 3;
            default: return 3;
        }
    }

    int countAnts(vector<int> x, vector<int> y, string direction) {
        int n = x.size();
        float change[4][2] = {{0, 0.5}, {0, -0.5}, {0.5, 0}, {-0.5, 0}};
        vector<bool> removed(n, false);
        
        vector< pair<float, float> > points(n);
        for(int i = 0; i < n; i++)
            points[i] = make_pair(x[i], y[i]);

        for(int t = 1; t < 4001; t++) {
            for(int i = 0; i < n; i++) {
                points[i].first += change[give(direction[i])][0];
                points[i].second += change[give(direction[i])][1];
            }

            vector<int> to_removed;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if (i == j || removed[i] || removed[j])
                        continue;
                    if (points[i] == points[j]) {
                        to_removed.push_back(i);
                        break;
                    }
                }
            }
            for(int i = 0; i < to_removed.size(); i++)
                removed[to_removed[i]] = true;
        }

        int ans = 0;
        for(int i = 0; i < removed.size(); i++)
            if (!removed[i])
                ans++;

        return ans;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<int> x, vector<int> y, string direction, int __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    AntsMeet *instance = new AntsMeet();
    int __result = instance->countAnts(x, y, direction);
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
            int x[] = {
                0, 9, 0, 0
            };
            int y[] = {
                0, 0, 4, 5
            };
            string direction = "EWSS";
            int __expected = 2;
            return do_test(to_vector(x), to_vector(y), direction, __expected, __no);
        }
        case 1: {
            int x[] = {
                -10, 0, 0, 10
            };
            int y[] = {
                0, -10, 10, 0
            };
            string direction = "NEWS";
            int __expected = 0;
            return do_test(to_vector(x), to_vector(y), direction, __expected, __no);
        }
        case 2: {
            int x[] = {
                -1, -1, -1, 0, 0, 0, 1, 1, 1
            };
            int y[] = {
                -1, 0, 1, -1, 0, 1, -1, 0, 1
            };
            string direction = "ESEWNNEWW";
            int __expected = 4;
            return do_test(to_vector(x), to_vector(y), direction, __expected, __no);
        }
        case 3: {
            int x[] = {
                4, 7, 6, 2, 6, 5, 7, 7, 8, 4, 7, 8, 8, 8, 5, 4, 8, 9, 1, 5, 9, 3, 4, 0, 0, 1, 0, 7, 2, 6, 9, 6, 3, 0, 5, 5, 1, 2, 0, 4, 9, 7, 7, 1, 8, 1, 9, 2, 7, 3
            };
            int y[] = {
                2, 3, 0, 6, 8, 4, 9, 0, 5, 0, 2, 4, 3, 8, 1, 5, 0, 7, 3, 7, 0, 9, 8, 1, 9, 4, 7, 8, 1, 1, 6, 6, 6, 2, 8, 5, 1, 9, 0, 1, 1, 1, 7, 0, 2, 5, 4, 7, 5, 3
            };
            string direction = "SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" ;
            int __expected = 25;
            return do_test(to_vector(x), to_vector(y), direction, __expected, __no);
        }
        case 4: {
            int x[] = {
                478, -664, 759, 434, -405, 513, 565, -396, 311, -174, 56, 993, 251, -341, 993, -112, 242, 129, 383, 513, -78, -341, -148, 129, 423, 493, 434, -405, 478, -148, 929, 251, 56, 242, 929, -78, 423, -664, 802, 251, 759, 383, -112, -591, -591, -248, 660, 660, 735, 493
            };
            int y[] = {
                -186, 98, 948, 795, 289, -678, 948, -170, -195, 290, -354, -424, 289, -157, -166, 150, 706, -678, 684, -294, -234, 36, 36, -294, -216, -234, 427, 945, 265, -157, 265, 715, 275, 715, -186, 337, 798, -170, 427, 706, 754, 961, 286, -216, 798, 286, 961, 684, -424, 337
            };
            string direction = "WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE";
            int __expected = 44;
            return do_test(to_vector(x), to_vector(y), direction, __expected, __no);
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
    cout << "AntsMeet (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1381144840;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
