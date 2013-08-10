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
#define MAXN 10001

using namespace std;
typedef long long LL;

vector< vector< pair<int, int> > > graph;;
vector< vector<int> > heavy_light;
int parent[MAXN], chain[MAXN], head[MAXN], inverse_index[MAXN], parent_cost[MAXN], depth[MAXN];
bool heavy[MAXN];
int from[MAXN], to[MAXN], cost[MAXN];

int num = 0;

class HeavyLight {
private:
	vector<int> tree;
	vector<int> store;
	int N;

	void build(int node, int i, int j) {
		if (i > j)
			return;
		if (i == j) {
			tree[node] = store[i];
		}
		else {
			int mid = (i+j)>>1;

			build(2*node, i, mid);
			build(2*node+1, mid+1, j);

			tree[node] = max(tree[2*node], tree[2*node+1]);

		}
	}

	int calc(int node, int i, int j, int a, int b) {
		if (i > j || a > b || a > j || b < i)
			return -INF;
		if (i == a && j == b) {
			return tree[node];
		}
		int mid = (i+j)>>1;
		int p1 = calc(2*node, i, mid, a, min(b, mid));
		int p2 = calc(2*node+1, mid+1, j, max(a, mid+1), b);
		return max(p1, p2);
	}

	void update(int node, int i, int j, int v, int p) {
		if (i > j || v < i || v > j)
			return;
		if (i == v && j == v) {
			tree[node] = p;
			return;
		}

		int mid = (i+j)>>1;
		update(2*node, i, mid, v, p);
		update(2*node+1, mid+1, j, v, p);
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}

public:
	void init(int n, vector<int>& st) {
		N = n;
		for(int i = 0; i < st.size(); i++) {
			store.push_back(parent_cost[st[i]]);
		}
		tree.resize(4*N+2);
		build(1, 0, N-1);
	}

	int get(int l, int r) {
		return calc(1, 0, N-1, l, r);
	}

	void change(int v, int p) {
		update(1, 0, N-1, v, p);
	}
};

int dfs(int v, int p) {
	if (p != -1)
		depth[v] = depth[p]+1;


	vector<int> subtree_size(graph[v].size(), 0);

	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i].first;
		if (to == p)
			continue;
		parent[to] = v;
		parent_cost[to] = cost[graph[v][i].second];
		subtree_size[i] = dfs(to, v);
	}

	int total = accumulate(subtree_size.begin(), subtree_size.end(), 0);
	total++;

	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i].first;
		if (to == p)
			continue;
		if (total/2 < subtree_size[i])
			heavy[to] = true;
	}

	return total;
}

void chainer(int v, int p) {
	if (p != -1) {
		if (heavy[v]) {
			chain[v] = chain[p];
			head[v] = head[p];
			inverse_index[v] = inverse_index[p]+1;
		}
		else {
			chain[v] = num++;
			head[v] = v;
			inverse_index[v] = 0;
		}
	}
	else {
		chain[v] = num++;
		head[v] = v;
		inverse_index[v] = 0;
	}

	heavy_light[chain[v]].push_back(v);

	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i].first;
		if (to == p)
			continue;
		chainer(to, v);
	}
}

int lca(int a, int b) {
	while(chain[a] != chain[b]) {
		if (depth[head[a]] < depth[head[b]])
			b = parent[head[b]];
		else
			a = parent[head[a]];
	}
	if (depth[a] < depth[b])
		return a;
	return b;
}

int maxEdge(int final, int v, vector<HeavyLight>& hl) {
	int ans = -INF;
	while(chain[v] != chain[final]) {
		ans = max(ans, hl[chain[v]].get(inverse_index[head[v]], inverse_index[v]));
		v = parent[head[v]];
	}
	ans = max(ans, hl[chain[v]].get(inverse_index[final]+1, inverse_index[v]));
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--) {
		int n;
		scanf("%d", &n);

		num = 0;
		graph.clear();
		graph.resize(n);
		heavy_light.clear();
		heavy_light.resize(n);
		memset(heavy, false, sizeof heavy);
		memset(depth, 0, sizeof depth);

		for(int i = 0; i < n-1; i++) {
			scanf("%d %d %d", &from[i], &to[i], &cost[i]);
			from[i]--;
			to[i]--;
			graph[from[i]].push_back(make_pair(to[i], i));
			graph[to[i]].push_back(make_pair(from[i], i));
		}

		parent[0] = -1;
		parent_cost[0] = -INF;

		dfs(0, -1);
		chainer(0, -1);

		vector<HeavyLight> hl(num);

		for(int i = 0; i < num; i++)
			hl[i].init(heavy_light[i].size(), heavy_light[i]);


		while(true) {
			char cmd[50];
			scanf("%s", cmd);
			if (cmd[0] == 'Q') {
				int a, b;
				scanf("%d %d", &a, &b);
				a--; b--;
				int final = lca(a, b);
				int max_edge = maxEdge(final, a, hl);
				max_edge = max(max_edge, maxEdge(final, b, hl));
				printf("%d\n", max_edge);
			}
			else if (cmd[0] == 'C') {
				int v, p;
				scanf("%d %d", &v, &p);
				v--;
				if (to[v] == parent[from[v]]) {
					hl[chain[from[v]]].change(inverse_index[from[v]], p);
				}
				else {
					hl[chain[to[v]]].change(inverse_index[to[v]], p);
				}
			}
			else 
				break;
		}
	}

	return 0;
}
