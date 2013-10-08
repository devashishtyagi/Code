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

vector<int> face, standing;

class Node {
public:
	bool left, right, middle;
	int sz;
	Node(bool l, bool r, bool m, int s) {
		left = l;
		right = r;
		middle = m;
		sz = s;
	}
	Node() {

	}
};

class SegmentTree {
private:
	int N;
	vector<Node> tree;

	void updateNode(int index) {
		tree[index].left = (tree[2*index].left) || (tree[2*index].middle && tree[2*index+1].left);
		tree[index].right = (tree[2*index+1].right) || (tree[2*index+1].middle && tree[2*index].right);
		tree[index].middle = tree[2*index].middle && tree[2*index+1].middle;
		tree[index].sz = tree[2*index].sz + tree[2*index+1].sz + (tree[2*index].right && tree[2*index+1].left);
	}

	Node combine(Node n1, Node n2) {
		bool l = (n1.left) || (n1.middle && n2.left);
		bool r = (n2.right) || (n2.middle && n1.right);
		bool m = n1.middle && n2.middle;
		int s = n1.sz + n2.sz + (n1.right && n2.left);
		return Node(l, r, m, s);
	}

	void build(int index, int l, int r) {
		if (l > r)
			return;
		if (l == r) {
			tree[index].left = face[l] && standing[l];
			tree[index].right = !face[l] && standing[l];
			tree[index].middle = !standing[l];
			tree[index].sz = 0;
			return;
		}

		int mid = (l+r)/2;
		build(2*index, l, mid);
		build(2*index+1, mid+1, r);
		updateNode(index);
	}

	void update(int index, int l, int r, int v) {
		if (v < l || v > r)
			return;
		if (l == r) {
			tree[index].left = face[l] && standing[l];
			tree[index].right = !face[l] && standing[l];
			tree[index].middle = !standing[l];
			tree[index].sz = 0;
			return;
		}
		int mid = (l+r)/2;
		update(2*index, l, mid, v);
		update(2*index+1, mid+1, r, v);
		updateNode(index);
	}

	Node query(int index, int l, int r, int a, int b) {
		if (b < l || a > r || l > r)
			return Node(false, false, false, 0);
		if (l == a && r == b)
			return tree[index];

		int mid = (l+r)/2;
		Node n1 = query(2*index, l, mid, a, min(b, mid));
		Node n2 = query(2*index+1, mid+1, r, max(a, mid+1), b);
		return combine(n1, n2);
	}

public:
	void init(int n) {
		N = n;
		tree.resize(4*N+2);
		build(1, 0, N-1);
	}

	void change(int v) {
		update(1, 0, N-1, v);
	}

	int getValue(int l, int r) {
		Node ans = query(1, 0, N-1, l, r);
		return ans.sz;
	}
};

int main()
{
	int t;
	cin>>t;
	while(t--) {
		int n, q;
		cin>>n>>q;
		face.resize(n, true);
		standing.resize(n, true);

		string S;
		cin>>S;

		for(int i = 0; i < n; i++)
			if (S[i] == '>')
				face[i] = false;
		
		SegmentTree stree;
		stree.init(n);

		while(q--) {
			int type;
			cin>>type;
			if(type == 1) {
				int x;
				cin>>x;
				x--;
				standing[x] = !standing[x];
				stree.change(x);
			}
			else if (type == 2) {
				int x;
				cin>>x;
				x--;
				face[x] = !face[x];
				stree.change(x);
			}
			else {
				int l, r;
				cin>>l>>r;
				l--; r--;
				cout<<stree.getValue(l, r)<<endl;
			}
			//cout<<q<<" Handled"<<endl;
		}

		face.clear();
		standing.clear();
	}

	return 0;
}
