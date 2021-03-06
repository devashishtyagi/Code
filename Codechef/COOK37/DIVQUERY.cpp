/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <functional>
#include <numeric>
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


// Compiler utility
#define int_msb(x) ((31) - __builtin_clz(x))

#define sf(a) scanf("%d",&a)
#define ssf(a,b) scanf("%d %d",&a,&b)
#define pf(a) printf("%d\n",a)
#define foreach(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.end()

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define init0(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define MOD 1000000009
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

vector< vector<int> > indices(100001);

int main()
{
	int n, q;

	scanf("%d %d", &n, &q);

	for(int i = 0; i < n; i++) {
		int p;
		scanf("%d", &p);

		for(int j = 2; j*j <= p; j++) {
			if (p%j == 0) {
				indices[j].push_back(i);
				if (j*j != p)
					indices[p/j].push_back(i);
			}
		}
		indices[p].push_back(i);
	}

	for(int i = 0; i < q; i++) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		if (k != 1) {
			l--; r--;
			int first = (lower_bound(indices[k].begin(), indices[k].end(), l) - indices[k].begin());
			first--;
			int second = (lower_bound(indices[k].begin(), indices[k].end(), r+1) - indices[k].begin());
			second--;
			printf("%d\n", second-first);
		}
		else {
			printf("%d\n", r-l+1);
		}
	}

	return 0;
}
