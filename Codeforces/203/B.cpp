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

vector<int> type;
vector< vector<int> > ski;
vector<bool> visited;
vector<int> ans;

int dfs(int v) {
	if (visited[v])
		return ans[v];

	visited[v] = true;

	if (type[v] == 1)
		return ans[v] = 1;
	if (ski[v].size() != 1)
		return ans[v] = -INF;

	return ans[v] = dfs(ski[v][0]) + 1;
}

void print(int v) {
	if (type[v] == 1) {
		cout<<v+1<<endl;
		return;
	}
	cout<<v+1<<" ";
	print(ski[v][0]);
}

int main()
{
	int n;
	cin>>n;
	
	type.resize(n);
	ski.resize(n);
	visited.resize(n, false);
	ans.resize(n);

	for(int i = 0; i < n; i++)  {
		cin>>type[i];
	}

	for(int i = 0; i < n; i++) {
		int a;
		cin>>a;
		if (a != 0)
			ski[a-1].push_back(i);
	}

	int dist = -1, index = 0;

	for(int i = 0; i < n; i++) {
		if (!visited[i]) {
			int d = dfs(i);
			if (d > dist) {
				dist = d;
				index = i;
			}
		}
	}

	cout<<dist<<endl;
	print(index);

	return 0;
}
