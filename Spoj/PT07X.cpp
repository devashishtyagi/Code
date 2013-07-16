#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > graph;

pair<int, int> dfs(int v, int p) {
	int with = 0, without = 0;
	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
		if (to != p) {
			pair<int, int>  p = dfs(to, v);
			with += min(p.first, p.second);
			without += p.first;
		}
	}
	//cout<<v<<" "<<with+1<<" "<<without<<endl;
	return make_pair(with+1, without);
}

int main(void) {
	int n;
	scanf("%d", &n);

	graph.resize(n);

	for(int i = 0; i < n-1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	pair<int, int> ans = dfs(0, -1);

	printf("%d\n", min(ans.first, ans.second));

	return 0;
}