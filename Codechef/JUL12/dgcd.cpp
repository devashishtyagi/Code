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

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define clear(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

class SegmentTree {
private:
	class Node {
	public:
		int l, r;
		int gcd;
		int upd;
	};

	int N;
	vector<Node> tree;

	int f(int a, int b) {
		if (a < 0)
			return f(-a, b);
		else if (b < 0)
			return f(a, -b);
		else if (a == 0)
			return b;
		else if (a > b)
			return f(b, a);
		else 
			return f(b%a, a);
	}

	void combine(int node) {
		tree[node].l = tree[2*node].l;
		tree[node].r = tree[2*node+1].r;
		tree[node].gcd = f(f(tree[2*node].gcd, tree[2*node+1].gcd), tree[2*node+1].l - tree[2*node].r);
	}

	void inc(int node, int upd) {
		tree[node].l += upd;
		tree[node].r += upd;
	}

	void pushUpdate(int node) {
		inc(2*node, tree[node].upd);
		inc(2*node+1, tree[node].upd);
		tree[2*node].upd += tree[node].upd;
		tree[2*node+1].upd += tree[node].upd;
		tree[node].upd = 0;
	}

	void build(int node, int l, int r, vector<int>& store) {
		if (l > r)
			return;
		if (l == r) {
			tree[node].l = store[l-1]; tree[node].r = store[l-1];
			tree[node].gcd = 0;
			tree[node].upd = 0;
			return;
		}

		int mid = (l+r)>>1;

		build(2*node, l, mid, store);
		build(2*node+1, mid+1, r, store);
		tree[node].upd = 0;
		combine(node);
	}

	int get(int node, int l, int r, int a, int b) {
		if (l > r || a > b)
			return 0;
		else if (l == a && r == b)
			return f(tree[node].gcd, tree[node].l);
		else if (l > b && r < a)
			return 0;

		pushUpdate(node);

		int mid = (l+r)>>1;
		int p1 = get(2*node, l, mid, a, min(b, mid));
		int p2 = get(2*node+1, mid+1, r, max(a, mid+1), b);
		return f(p1, p2);
	}

	void update(int node, int l, int r, int a, int b, int k) {
		if (l > r || a > b)
			return;
		else if (l == a && r == b) {
			inc(node, k);
			tree[node].upd += k;
			return;
		}
		else if (l > b && r < a)
			return;

		pushUpdate(node);

		int mid = (l+r)>>1;
		update(2*node, l, mid, a, min(b, mid), k);
		update(2*node+1, mid+1, r, max(a, mid+1), b, k);
		
		combine(node);
	}

public:
	SegmentTree(int n, vector<int>& store) {
		N = n;
		tree.resize(4*N+2);
		build(1, 1, N, store);
	}

	int calc(int i, int j) {
		return get(1, 1, N, i, j);
	}
	void change(int i, int j, int k) {
		update(1, 1, N, i, j, k);
	}

};

class HeavyChain {
private:
	SegmentTree* stree;
	vector<int> mapping;
	int N;

	buildMapping(vector<int>& store) {
		forn(i, 0, store.size())
			mapping[store[i]] = i;
	}

public:
	HeavyChain(int n, vector<int>& store, vector<int>& values) {
		n = N;
		mapping.resize(N, -1);
		stree = new SegmentTree(n, values);
		buildMapping(store);
	}

	~HeavyChain() {
		delete stree;
	}

	int calc(int u, int v) {
		int l = mapping[u];
		int r = mapping[v];
		if (l > r)
			swap(l, r);
		return stree->get(l, r);
	}

	void change(int u, int v, int k) {
		int l = mapping[u];
		int r = mapping[v];
		if (l > r)
			swap(l, r);
		stree->change(l, r, k);
	}
};

class Node {
	int w;
	bool heavy;
	int size = 0;
};

vector< vector<int> > graph
vector<Node> tree;

void dfs(int v) {
	if (tree[v].size != -1)
		return;

	tree[v].size = 0;
	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
		dfs(to);
		
	}
}

int main()
{
	int n;
	cin>>n;
	
	tree.resize(n);
	graph.resize(n);

	for(int i = 0; i < n-1; i++) {
		int u, v;
		cin>>u>>v;
		u--; v--;
		graph[u].push_back(v);
	}

	for(int i = 0; i < n; i++) {
		int w;
		cin>>w;
		tree[i].w = w;
		tree[i].heavy = false;
		tree[i].size = -1;
	}

	dfs(0);
}
