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
#define EPS 10E-14
#define MAXN 3001

using namespace std;
typedef long long LL;

int x[3000], y[3000];
double dtance[3000][3000];
double angle[3000][3000];
double tree[12007];

double mytan(double y, double x) {
	double angle = atan2(y, x) * 180.0 / PI;
	return angle;
}

double dist(int i, int j) {
	return hypot(x[j]-x[i], y[j]-y[i]);
}


void build(int node, int l, int r, vector<double> &store) {
	if (l > r)
		return;
	if (l == r) {
		tree[node] = store[l];
		return;
	}
	int mid = (l+r)>>1;
	build(2*node, l, mid, store);
	build(2*node+1, mid+1, r, store);
	tree[node] = max(tree[2*node], tree[2*node+1]);
}

double find(int node, int l, int r, int a, int b) {
	if (l > r || a > b || a > r || b < l)
		return 0.0;
	if (l == a && r == b)
		return tree[node];
	int mid = (l+r)>>1;
	double v1 = find(2*node, l, mid, a, min(b, mid));
	double v2 = find(2*node+1, mid+1, r, max(a, mid+1), b);
	return max(v1, v2);
}

int main()
{
	int n;
	scanf("%d", &n);

	
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			dtance[i][j] = dist(i, j);
			angle[i][j] = mytan(y[j]-y[i], x[j]-x[i]);
		}

	double ans = 0.0;

	vector< pair<double, int> > slopes(n-1);
	vector<double> dt(n-1);

	for(int i = 0; i < n; i++) {
		int sz = 0;
		for(int j = 0; j < n; j++) {
			if (i == j)
				continue;
			slopes[sz++] = make_pair(angle[i][j], j);
		}
		sort(slopes.begin(), slopes.end());

		for(int j = 0; j < n-1; j++) {
			dt[j] = dtance[i][slopes[j].second];
		}

		build(1, 0, n-2, dt);

		int k = 0, l = 0;
		for(int j = 0; j < n-1; j++) {
			double angle = slopes[j].first;
			while(k < n-1 && slopes[k].first < angle+60.0)
				k++;
			while(l < n-1 && slopes[l].first < angle+300.0)
				l++;
			l--;

			if (k < n-1) {
				double maxdist = find(1, 0, n-2, k, l);
				ans = max(ans, min(maxdist, dtance[slopes[j].second][i]));
			}
		}
	}

	printf("%.8lf\n", ans/2.0);

	return 0;
}
