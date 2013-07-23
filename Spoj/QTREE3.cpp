#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>

#define INF 100000000
#define MAXN 100000

using namespace std;

vector< vector< pair<int, bool> > > graph(MAXN);
vector< vector<int> > heavy_chains(MAXN);
int parent[MAXN], chain[MAXN], head[MAXN], inverse_index[MAXN], subtree_size[4*MAXN];

int num = 0, idx = 0;

class SegmentTree {
public:
	vector<int> tree;
	int N;
	int index;

	inline void combine(int node) {
		if (tree[2*node] < INF)
			tree[node] = tree[2*node];
		else
			tree[node] = tree[2*node+1];

	}

	void build(int node, int i, int j) {
		if (i > j)
			return;
		if (i == j) {
			tree[node] = INF;
			return;
		}
		int mid = (i+j)>>1;
		build(2*node, i, mid);
		build(2*node+1, mid+1, j);
		combine(node);
	}

	int get(int node, int i, int j, int a, int b) {
		if (i > j || a > b || i > b || j < a)
			return INF;
		if (i == a && j == b)
			return tree[node];

		int mid = (i+j)>>1;
		int p1 = get(2*node, i, mid, a, min(mid, b));
		int p2 = get(2*node+1, mid+1, j, max(a, mid+1),b);

		if (p1 < INF)
			return p1;
		else
			return p2;
	}

	void update(int node, int i, int j, int v) {
		if (i > j || i > v || j < v)
			return;

		if (i == j && i == v) {
			if (tree[node] == INF)
				tree[node] = heavy_chains[index][v];
			else
				tree[node] = INF;
			return;
		}

		int mid = (i+j)>>1;
		update(2*node, i, mid, v);
		update(2*node+1, mid+1, j, v);

		combine(node);
	}
	void init(int n, int store) {
		index = store;
		N = n;
		tree.resize(4*N+2);
		build(1, 0, N-1);
	}
};

int dfs(int v, int p) {

	int n = graph[v].size();
	int prev = idx;
	idx += n;

	for(int i = 0; i < n; i++)
		if (graph[v][i].first != p)
			subtree_size[prev+i] = dfs(graph[v][i].first, v);
		else
			subtree_size[prev+i] = 0;

	int total = 0;
	for(int i = 0; i < n; i++)
		total += subtree_size[prev+i];

	total++;

	for(int i = 0; i < n; i++) {
		if (graph[v][i].first != p && subtree_size[prev+i] > total/2)
			graph[v][i].second = true;
	}

	return total;
}

void chainer(int v, int p, bool heavy) {	
	if (p != -1) {
		parent[v] = p;
		if (heavy) {
			chain[v] = chain[p];
			head[v] = head[p];
			inverse_index[v] = inverse_index[p] + 1;
		}
		else{
			chain[v] = ++num;
			head[v] = v;
			inverse_index[v] = 0;
		}
	}
	else {
		parent[v] = -1;
		chain[v] = 0;
		head[v] = v;
		inverse_index[v] = 0;
	}

	heavy_chains[chain[v]].push_back(v);

	for(int i = 0; i < graph[v].size(); i++) {
		if (graph[v][i].first != p) {
			chainer(graph[v][i].first, v, graph[v][i].second);
		}
	}
}


int main(void) {
	/*clock_t begin = clock(), end;*/

	int n, q;
	scanf("%d %d",&n,&q);

	for(int i = 0; i < n-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		graph[a].push_back(make_pair(b, false));
		graph[b].push_back(make_pair(a, false));
	}

	dfs(0, -1);

	chainer(0, -1, false);

	SegmentTree stree[num+1];

	for(int i = 0; i <= num; i++)
		stree[i].init(heavy_chains[i].size(), i);

	while(q--) {
		int c, v;
		scanf("%d %d",&c,&v);
		v--;
		if (c == 0) {
			stree[chain[v]].update(1, 0, stree[chain[v]].N-1, inverse_index[v]);
		}
		else {
			int ans = INF;
			while(v != -1) {
				int p = stree[chain[v]].get(1, 0, stree[chain[v]].N-1, inverse_index[head[v]], inverse_index[v]);
				if (p < INF)
					ans = p;
				v = parent[head[v]];
			}
			if (ans < INF)
				printf("%d\n", ans+1);
			else
				printf("-1\n");
		}
	}

	return 0;
}
