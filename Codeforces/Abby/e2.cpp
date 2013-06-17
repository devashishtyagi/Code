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

void init() {
	f[0]  = 1;
	f[1] = 1;
	forn(i, 2, 200002) {
		f[i] = (f[i-1] + f[i-2])%MOD;
	}
}

class SegmentTree{
private:
	int N;
	vector< pair<int,int> > tree;

	pair<int,int> shiftBy(pair<int,int> p, int x) {
		if (x == 0){
			return p;
		}
		else if (x == 1){
			pair<int, int> ans;
			ans.first = p.second;
			ans.second = (p.first + p.second)%MOD;
			return ans;
		}
		else {
			pair<int,int> ans;
			ans.first = (p.first*1LL*f[x-2] + p.second*1LL*f[x-1])%MOD;
			ans.second = (p.first*1LL*f[x-1] + p.second*1LL*f[x])%MOD;
			return ans;
		}
	}

	void build(int node, int l, int r, vector<int>& store) {
		if (l > r)
			return;
		if (l == r) {
			tree[node] = make_pair(store[l], store[r]);
			return;
		}
		int mid = (l+r)>>1;
		build(2*node, l, mid, store);
		build(2*node +1 , mid+1, r, store);
		pair<int, int> p2 = shiftBy(tree[2*node+1], (mid-l+1));
		pair<int, int> p1 = tree[2*node];

		tree[node] = make_pair((p1.first + p2.first)%MOD, (p1.second + p2.second)%MOD);
	}

	pair<int,int> get(int node, int l, int r, int a, int b){
		if (l > r || a > b)
			return make_pair(0, 0);
		else if (a > r || b < l)
			return make_pair(0, 0);
		else if (a == l && b == r)
			return tree[node];

		int mid = (l+r)>>1;
		pair<int,int> p1 = get(2*node, l, mid, a, min(mid, b));
		pair<int,int> p2 = get(2*node+1, mid+1, r, max(a, mid+1), b);

		p2 = shiftBy(p2, max(mid-a+1, 0));

		//cout<<p2.first<<" "<<p2.second<<endl;

		return make_pair((p1.first+ p2.first)%MOD, (p1.second + p2.second)%MOD);
	}

	void update(int node, int l, int r, int index, int v) {
		if (l > r || index > r || index < l)
			return;
		else if (l == r){
			tree[node] = make_pair(v, v);
			return;
		}

		int mid = (l+r)>>1;
		update(2*node, l, mid, index, v);
		update(2*node + 1, mid+1, r, index, v);
		pair<int, int> p2 = shiftBy(tree[2*node+1], (mid-l+1));
		pair<int, int> p1 = tree[2*node];

		tree[node] = make_pair((p1.first + p2.first)%MOD, (p1.second + p2.second)%MOD); 
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

	int change(int i, int v){
		update(1, 1, N, i, v);
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
			stree.change(x, v);
		}
		else{
			int l, r;
			cin>>l>>r;
			cout<<stree.calculate(l, r)<<endl;
		}
	}
	return 0;
}
