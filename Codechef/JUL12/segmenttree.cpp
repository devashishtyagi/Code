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
		tree[node].upd += upd;
	}

	void pushUpdate(int node) {
		inc(2*node, tree[node].upd);
		inc(2*node+1, tree[node].upd);
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
		if (l > r || a > b || l > b || r < a)
			return 0;
		else if (l == a && r == b)
			return f(tree[node].gcd, tree[node].l);

		pushUpdate(node);

		int mid = (l+r)>>1;
		int p1 = get(2*node, l, mid, a, min(b, mid));
		int p2 = get(2*node+1, mid+1, r, max(a, mid+1), b);
		return f(p1, p2);
	}

	void update(int node, int l, int r, int a, int b, int k) {
		if (l > r || a > b || l > b || r < a)
			return;
		else if (l == a && r == b) {
			inc(node, k);
			return;
		}

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


int main()
{
	int n;
	cin>>n;
	vector<int> store(n);
	forn(i, 0, n)
		cin>>store[i];

	SegmentTree stree(n, store);

	int q;
	cin>>q;
	while(q--) {
		int op;
		cin>>op;
		if (op == 1) {
			int x, y;
			cin>>x>>y;	
			cout<<stree.calc(x, y)<<endl;
		}
		else {
			int x, y, z;
			cin>>x>>y>>z;
			stree.change(x, y, z);
		}
	}
	return 0;
}
