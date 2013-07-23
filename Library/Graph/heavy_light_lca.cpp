#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

vector< vector< pair<int, bool> > > graph;
vector<int> parent;
vector<int> chain;
vector<int> head;
vector<int> depth;

int num = 0;

int dfs(int v) {
	vector<int> subtree_size;

	for(int i = 0; i < graph[v].size(); i++)
		subtree_size.push_back(dfs(graph[v][i].first));

	int total = 0;
	for(int i = 0; i < subtree_size.size(); i++)
		total += subtree_size[i];

	total++;

	for(int i = 0; i < subtree_size.size(); i++) {
		if (subtree_size[i] > total/2)
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
		}
		else{
			chain[v] = ++num;
			head[v] = v;
		}
		depth[v] = depth[p]+1;
	}
	else {
		parent[v] = v;
		depth[v] = 0;
		chain[v] = 0;
		head[v] = v;
	}

	for(int i = 0; i < graph[v].size(); i++)
		chainer(graph[v][i].first, v, graph[v][i].second);
}


int main(void) {
	int t;
	scanf("%d",&t);

	for(int k = 1; k <= t; k++) {
		int n;
		scanf("%d", &n);

		graph.clear();
		graph.resize(n);
		parent.clear();
		parent.resize(n);
		head.clear();
		head.resize(n);
		chain.clear();
		chain.resize(n);
		depth.clear();
		depth.resize(n, 0);

		vector<int> degree(n, 0);

		for(int i = 0; i < n; i++) {
			int m;
			scanf("%d", &m);
			for(int j = 0; j < m; j++) {
				int tmp;
				scanf("%d", &tmp);
				tmp--;
				degree[tmp]++;
				graph[i].push_back(make_pair(tmp, false));
			}
		}

		int root = -1;
		for(int i = 0; i < n; i++) {
			if (degree[i] == 0) {
				root = i;
				break;
			}
		}

		assert(root != -1);

		dfs(root);
		chainer(root, -1, false);

		int q;
		scanf("%d", &q);

		printf("Case %d:\n", k);

		while(q--) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;
			
			while(chain[u] != chain[v]) {
				if (depth[head[u]] < depth[head[v]])
					v = parent[head[v]];
				else
					u = parent[head[u]];
			}
			if (depth[u] < depth[v])
				printf("%d\n", u+1);
			else
				printf("%d\n", v+1);
		}
	}

	return 0;
}
