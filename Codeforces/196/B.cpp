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

int n, m, d;
vector<bool> flagged;
vector< vector<int> > graph;
vector<bool> first, second, visited;
vector<int> l1, l2;

void dfs(int v) {
	visited[v] = true;

	int max_dist = -1;

	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
		if (!visited[to]) {
			dfs(to);
			if (l1[to] != -1) 
				max_dist = max(max_dist, l1[to]);
		}
	}

	
	if (max_dist+1 <= d) {
		first[v] = true;
		if (max_dist == -1 && !flagged[v])
			l1[v] = -1;
		else
			l1[v] = max_dist+1;
	}
	else {
		first[v] = false;
		l1[v] = max_dist+1;
	}

}

void redfs(int v, int dist, int p) {
	if (dist <= d) {
		second[v] = true;
	}

	set< pair<int, int> > S;
	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
		if (to != p)
			S.insert(make_pair(l1[to], to));	
	}

	for(int i = 0;  i < graph[v].size(); i++) {
		int to = graph[v][i];
		if (to != p) {
			S.erase(make_pair(l1[to], to));
			int max_dist = -1;
			if (!S.empty()) 
				max_dist = (*S.rbegin()).first;
			
			if (max_dist != -1)
				max_dist++;
			max_dist = max(max_dist, dist);
			if (flagged[v])
				max_dist = max(max_dist, 0);

			if (max_dist != -1)
				max_dist++;

			S.insert(make_pair(l1[to], to));
			redfs(to, max_dist, v);
		}
	}
}

int main()
{
	cin>>n>>m>>d;

	flagged.resize(n, false);
	graph.resize(n);
	first.resize(n, false);
	second.resize(n, false);
	visited.resize(n, false);
	l1.resize(n, 0);
	l2.resize(n, 0);

	for(int i = 0; i < m; i++) {
		int p;
		cin>>p;
		p--;
		flagged[p] = true;
	}

	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin>>a>>b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(0);

	redfs(0, -1, -1);

	int count = 0;

	for(int i = 0; i < n; i++) {
		if (first[i] && second[i]) {
			count++;
		}
	}

	cout<<count<<endl;

	return 0;
}
