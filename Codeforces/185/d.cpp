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
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define MOD 95542721
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int convertString(string s)
{
  int num;
  stringstream sstr(s); // create a stringstream
  sstr>>num; // push the stream into the num
  return num;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
	    elems.push_back(item);
	}
}

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }


class SegmentTree {
private:
	class Node {
	public:
		int dirty;
		int valueStore[48];
	};

	vector<Node> tree;
	int N;

	void build(int node, int l, int r, vector< vector<int> >& store) {
		if (l > r)
			return;

		if (l == r) {
			tree[node].dirty = 0;
			forn(i, 0, 48) {
				tree[node].valueStore[i] = store[i][l];
			}
			return;
		}

		int mid = (l+r)>>1;
		build(2*node, l, mid, store);
		build(2*node+1, mid+1, r, store);

		tree[node].dirty = 0;
		forn(i, 0, 48)
			tree[node].valueStore[i] = (tree[2*node].valueStore[i] + tree[2*node+1].valueStore[i])%MOD;
	}

	void inc(int node, int s) {
		int temp[48];
		forn(i, 0, 48) {
			temp[i] = tree[node].valueStore[(i+s)%48];
		}
		memcpy(tree[node].valueStore, temp, sizeof(temp));
	}

	void pushUpdate(int node) {
		inc(2*node, tree[node].dirty);
		inc(2*node + 1, tree[node].dirty);

		tree[2*node].dirty += tree[node].dirty;
		tree[2*node+1].dirty += tree[node].dirty;

		tree[node].dirty = 0;
	}

	int calc(int node, int l, int r, int a, int b) {
		if (l > r || a > b)
			return 0;
		if (l == a && r == b)
			return tree[node].valueStore[0];
		else if (l > b && r < a)
			return 0;

		int mid = (l+r)>>1;
		pushUpdate(node);
		int p1 = calc(2*node, l, mid, a, min(b, mid));
		int p2 = calc(2*node+1, mid+1, r, max(mid+1, a), b);
		return (p1+ p2)%MOD;
	}

	void update(int node, int l, int r, int a, int b) {
		if (l > r || a > b)
			return;
		if (l == a && r == b) {
			inc(node, 1);
			tree[node].dirty += 1;
			return;
		}
		else if (l > b && r < a)
			return;

		int mid = (l+r)>>1;
		pushUpdate(node);
		update(2*node, l, mid, a, min(b, mid));
		update(2*node+1, mid+1, r, max(a, mid+1), b);
		forn(i, 0, 48)
			tree[node].valueStore[i] = (tree[2*node].valueStore[i] + tree[2*node+1].valueStore[i])%MOD;

	}

public:
	SegmentTree(int n, vector< vector<int> >& store) {
		N = n;
		tree.resize(4*N+2);
		build(1, 1, N, store);
	}

	int get(int i, int j) {
		return calc(1, 1, N, i, j);
	}

	void change(int i, int j) {
		update(1, 1, N, i, j);
	}

};

int **store;


int main()
{	
	int n;
	cin>>n;

	vector< vector<int> > store(48, vector<int>(n+1, 0));

	forn(i, 0, n)
		cin>>store[0][i+1];

	forn(i, 1, 48) {
		forn(j, 1, n+1) {
			store[i][j] = (LL)((LL)store[i-1][j]*store[i-1][j]%MOD)*store[i-1][j]%MOD;
		}
	}	

	SegmentTree stree(n, store);

	int m;
	cin>>m;

	while(m--) {
		int op;
		cin>>op;
		if(op == 1) {
			int i, j;
			cin>>i>>j;
			cout<<stree.get(i, j)<<endl;
		}
		else {
			int i, j;
			cin>>i>>j;
			stree.change(i, j);
		}
	}
	return 0;
}