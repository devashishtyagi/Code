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
#define MOD 747474747
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

int points[6666][5];
long long cost[6666][6666];
long long edges[6666];
long long away[6666];
bool selected[6666];
int parent[6666];

void init() {
	CLEAR(parent);
	memset(selected, false, sizeof selected);
}

LL dist(int i, int j, int d) {
	LL ans = 0;
	for(int k = 0; k < d; k++) {
		ans += (points[i][k]-points[j][k])*1LL*(points[i][k]-points[j][k]);
	}
	return ans;
}

int main()
{
	int t;
	sf(t);
	while(t--) {
		init();
		int n,d;
		sf(n); sf(d);
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < d; j++) {
				sf(points[i][j]);
			}
		}

		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				if (j == i) {
					cost[i][j] = 0;
				}
				else{
					cost[i][j] = dist(i, j, d);
					cost[j][i] = cost[i][j];
				}
			}
		}

		memcpy(away, cost[0], n*sizeof(long long));
		int k = 1;
		selected[0] = true;
		while(k < n) {
			long long maxDist = -1;
			int x = -1, y = -1;
			for(int i = 1; i < n; i++) {
				if (!selected[i] && away[i] > maxDist) {
					maxDist = away[i];
					x = i;
					y = parent[i];
				}
			}
			edges[k-1] = cost[x][y];
			selected[x] = true;
			for(int i = 1; i < n; i++) {
				if (away[i] < cost[x][i]) {
					away[i] = cost[x][i];
					parent[i] = x;
				}
			}
			k++;
		}

		long long ans = 1;
		for(int i = 0; i < n-1; i++) {
			if (edges[i] != 0) {
				edges[i] %= MOD;
				ans = ans*edges[i]%MOD;
			}
		}
		printf("%lld\n", ans);

	}  
	return 0;
}
