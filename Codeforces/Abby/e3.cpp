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

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define init0(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define MOD 1000000000
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

int f[200002];
int f0sum[200002];
int f1sum[200002];

void init() {
	f[0]  = 1;
	f[1] = 1;
	forn(i, 2, 200002) {
		f[i] = (f[i-1] + f[i-2])%MOD;
	}
	f1sum[1] = 1;
	f0sum[1] = 1;
	forn(i, 2, 200002) {
		f1sum[i] = (f1sum[i-1] + f[i])%MOD;
		f0sum[i] = (f0sum[i-1] + f[i-1])%MOD;
	}
}

class SegmentTree{
private:
	class Node {
	public:
		pair<int, int> f;
		long long upd;
		int len;
	};

	int N;
	vector< Node > tree;

	pair<int, int> shiftBy(pair<int, int> p, int x) {
		if (x == 0){
			return p;
		}
		else if (x == 1){
			pair<int , int> ans;
			ans.first = p.second;
			ans.second = (p.first + p.second)%MOD;
			return ans;
		}
		else {
			pair<int, int> ans;
			ans.first = (p.first*1LL*f[x-2] + p.second*1LL*f[x-1])%MOD;
			ans.second = (p.first*1LL*f[x-1] + p.second*1LL*f[x])%MOD;
			return ans;
		}
	}

	inline void combine(int node) {
		pair<int, int> p2 = shiftBy(tree[2*node+1].f, tree[2*node].len);
		pair<int, int> p1 = tree[2*node].f;
		tree[node].f = make_pair((p1.first + p2.first)%MOD, (p1.second + p2.second)%MOD);		
	}

	inline void applyUpdate(int node, int upd) {
		tree[node].f.first = (tree[node].f.first*1LL + f0sum[tree[node].len]*1LL*upd)%MOD;
		tree[node].f.second = (tree[node].f.second*1LL + f1sum[tree[node].len]*1LL*upd)%MOD;

		// Check for overflow here
		tree[node].upd += upd;
		if (tree[node].upd >= MOD)
			tree[node].upd -= MOD;
	}

	void pushUpdate(int node) {
		if (tree[node].upd != 0) {
			applyUpdate(2*node, tree[node].upd);
			applyUpdate(2*node+1, tree[node].upd);
			tree[node].upd = 0;
		}
	}

	void build(int node, int l, int r, vector<int>& store) {
		if (l > r)
			return;
		if (l == r) {
			tree[node].upd = 0;
			tree[node].len = 1;
			tree[node].f = make_pair(store[l], store[l]);
			return;
		}
		int mid = (l+r)>>1;
		build(2*node, l, mid, store);
		build(2*node +1 , mid+1, r, store);
		combine(node);
		tree[node].upd = 0;
		tree[node].len = tree[2*node].len + tree[2*node+1].len;
	}

	pair<int, int> get(int node, int l, int r, int a, int b){
		if (l > r || a > b || a > r || b < l)
			return make_pair(0, 0);
		else if (a == l && b == r)
			return tree[node].f;

		pushUpdate(node);

		int mid = (l+r)>>1;
		pair<int, int> p1 = get(2*node, l, mid, a, min(mid, b));
		pair<int, int> p2 = get(2*node+1, mid+1, r, max(a, mid+1), b);

		p2 = shiftBy(p2, max(mid-a+1, 0));

		return make_pair((p1.first+ p2.first)%MOD, (p1.second + p2.second)%MOD);
	}

	void update(int node, int l, int r, int a, int b, int v) {
		if (l > r || a > b || r < a || l > b)
			return;
		else if (l == a && r == b){
			applyUpdate(node, v);
			return;
		}

		pushUpdate(node);

		int mid = (l+r)>>1;
		update(2*node, l, mid, a, min(b, mid), v);
		update(2*node + 1, mid+1, r, max(mid+1, a), b, v);
		
		combine(node);
	}

	void modify(int node, int l, int r, int index, int v) {
		if (l > r || index > r || index < l)
			return;
		else if (l == r){
			tree[node].f = make_pair(v, v);
			return;
		}

		pushUpdate(node);

		int mid = (l+r)>>1;
		modify(2*node, l, mid, index, v);
		modify(2*node + 1, mid+1, r, index, v);

		combine(node);
	}

public:
	SegmentTree(int n, vector<int>& store){
		N = n;
		tree.resize(4*N+2);
		build(1, 1, N, store);
	}

	int calculate(int i, int j){
		return get(1, 1, N, i, j).first;
	}

	void range_update(int i, int j, int v){
		update(1, 1, N, i, j, v);
	}

	void point_update(int i, int x) {
		modify(1, 1, N, i, x);
	}
};

vector<int> a;

int main()
{
	int n, m;
	cin>>n>>m;

	a.resize(n+1);

	forn(i, 0, n)
		cin>>a[i+1];

	init();
	SegmentTree stree(n, a);

	forn(i, 0, m) {
		int t;
		cin>>t;
		if (t == 1) {
			int x, v;
			cin>>x>>v;
			stree.point_update(x, v);
		}
		else if (t == 2) {
			int l, r;
			cin>>l>>r;
			cout<<stree.calculate(l, r)<<endl;
		}
		else {
			int l, r, d;
			cin>>l>>r>>d;
			stree.range_update(l, r, d);
		}
	}
	return 0;
}
