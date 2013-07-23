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
