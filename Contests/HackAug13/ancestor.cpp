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
#define MAXN 100001
#define LOGN 18

using namespace std;
typedef long long LL;


vector< vector<int> > graph;
int information[MAXN][LOGN];
int parent[MAXN];

int findParent(int v, int k) {
	if (k == 0)
		return v;
	if (v == 0)
		return 0;
	int index = 31 - __builtin_clz(k);
	return findParent(information[v][index], k - (1<<index));
} 


void dfs(int v) {
	information[v][0] = parent[v];
	for(int i = 1; i < LOGN; i++) {
		information[v][i] = findParent(information[v][i-1], 1<<(i-1));
	}
	
	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
		dfs(to);
	}
}

int main()
{
	int t;
	cin>>t;

	while(t--) {
		graph.clear();
		graph.resize(MAXN);
		memset(parent, 0, sizeof parent);
		memset(information, 0, sizeof information);

		int p;
		cin>>p;

		int root = -1;

		for(int i = 0; i < p; i++) {
			int x, y;
			cin>>x>>y;
			parent[x] = y;
			if (y == 0)
				root = x;
			graph[y].push_back(x);
		}

		dfs(root);

		int q;
		cin>>q;

		while(q--) {
			int cmd;
			cin>>cmd;

			if (cmd == 0) {
				int x, y;
				cin>>x>>y;
				parent[y] = x;
				information[y][0] = parent[y];
				for(int i = 1; i < LOGN; i++)
					information[y][i] = findParent(information[y][i-1], 1<<(i-1));
			}
			else if (cmd == 1) {
				int x;
				cin>>x;
				memset(information[x], 0, sizeof information[x]);
			}
			else {
				int x, k;
				cin>>x>>k;
				cout<<findParent(x, k)<<endl;
			}
		}
	}
	return 0;
}
