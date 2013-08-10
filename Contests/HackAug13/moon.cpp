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

using namespace std;
typedef long long LL;

vector< vector<int> > graph;
vector<bool> visited;

int dfs(int v) {
	visited[v] = true;

	int count = 0;

	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
		if (!visited[to])
			count += dfs(to);
	}

	return count+1;
}


int main()
{
	int n, k;
	cin>>n>>k;

	graph.resize(n);
	visited.resize(n, false);

	for(int i = 0; i < k; i++) {
		int a, b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> comp;
	for(int i = 0; i < n; i++) {
		if (!visited[i])
			comp.push_back(dfs(i));
	}

	vector<int> sum(comp.size());
	n = comp.size();

	sum[n-1] = 0;

	for(int i = n-2; i >= 0; i--) {
		sum[i] = sum[i+1] + comp[i+1];
	}

	long long result = 0;

	for(int i = 0; i < n-1; i++)
		result = result + sum[i]*1LL*comp[i];

	cout<<result<<endl;

	return 0;
}
