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

int bits[30][(1<<17)];

class SegmentTree {
private:
	vector< pair<int, int> > tree;
	int n;
	void build(int node, int i, int j, int* bits) {
		if (j < i)
			return;
		if (i == j) {
			tree[node].first = bits[i];
			tree[node].second = 0;
			return;
		}
		int mid = (i+j)>>1;
		build(2*node, i, mid, bits);
		build(2*node+1, mid+1, j, bits);
		tree[node].second = (tree[2*node].second+1)%2;
		if (tree[node].second == 0) {
			tree[node].first = tree[2*node].first ^ tree[2*node+1].first;
		}
		else {
			tree[node].first = tree[2*node].first | tree[2*node+1].first;	
		}
	}

	void update(int node, int i, int j, int a, int v) {
		if (j < i || a < i || a > j)
			return;

		if (i == j) {
			tree[node].first = v;
			return;
		}
		int mid = (i+j)>>1;
		update(2*node, i, mid, a, v);
		update(2*node+1, mid+1, j, a, v);
		if (tree[node].second == 0) {
			tree[node].first = tree[2*node].first ^ tree[2*node+1].first;
		}
		else {
			tree[node].first = tree[2*node].first | tree[2*node+1].first;	
		}
	}

public:
	void init(int N, int* bits) {
		n = N;
		tree.resize(4*n+2);
		build(1, 0, n-1, bits);
	}
	void change(int i, int v) {
		update(1, 0, n-1, i, v);
	}
	int get() {
		return tree[1].first;
	}
};


int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	memset(bits, 0, sizeof bits);

	for(int i = 0; i < (1<<n); i++) {
		int t;
		scanf("%d", &t);
		bitset<30> mybit(t);
		for(int j = 0; j < 30; j++)
			bits[j][i] = mybit[j];
	}

	SegmentTree stree[30];

	for(int i = 0; i < 30; i++) {
		stree[i].init(1<<n, bits[i]);
	}

	for(int i = 0; i < m; i++) {
		int p, b;
		scanf("%d %d", &p, &b);
		p--;
		bitset<30> mybit(b);
		int ans = 0;
		for(int j = 29; j >= 0; j--) {
			stree[j].change(p, mybit[j]);
			ans = (ans<<1) + stree[j].get();
		}
		printf("%d\n", ans);	
	}
}
