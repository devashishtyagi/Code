/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define sf(a) scanf("%d",&a)
#define ssf(a,b) scanf("%d %d",&a,&b)
#define pf(a) printf("%d\n",a)
#define foreach(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.end()

#define PB push_back
#define MP make_pair
#define sz(a) (int)(a).size()

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

int main()
{
    int n,k;
    sf(n); sf(k);
    int moves[n][k+1];
    bool done[n];
    CLEAR(moves);
    CLEAR(done);

    int index = 2;
    while(index < n) {
        done[n - index - 1] = true;
        int num = 1;
        int l = 0;
        while(num < index) {
            moves[n - index - 1][l++] = n - index;
            num = num*2;
        }
        while(l < k)
            moves[n - index - 1][l++] = n;
        index = index*2;
    }

    for(int i = 0; i < n; i++) {
        if (done[n - i - 1])
            continue;
        int value = 1;
        int l = 0;10000
        while (l < k && !(value & i)) {
            moves[n - i - 1][l++] = n - i;
            value = value*2;
        }
        moves[n - i - 1][l++] = n;
        value = value*2;
        while(l < k) {
            if (value&i) {
                moves[n - i - 1][l++] = n - value;
            }
            else {
                moves[n - i - 1][l++] = n;
            }
            value = value*2;
        }
    }

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cout<<moves[j][i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
