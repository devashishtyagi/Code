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
#include <climits>


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

vector< vector<int> > graph;
vector<int> a;
vector<bool> visited;

long long gcd(long long a, long long b) {
	if (a == 0)
		return b;
	else if (a > b)
		return gcd(b, a);
	else
		return gcd(b%a, a);
}

pair<long long, long long> solve(int v) {
	visited[v] = true;

	vector< pair<long long, long long> > leaves;

	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
		if (!visited[to]) {
			leaves.push_back(solve(to));
		}
	}

	if (leaves.size() == 0) {
		return make_pair(1, a[v]);
	}


	long long lcm = 1;
	for(int i = 0; i < leaves.size(); i++) {
		if (leaves[i].first != 0) {		
			long long g = gcd(lcm, leaves[i].first);
			lcm = lcm/g;
			if (lcm > LLONG_MAX/leaves[i].first) {
				lcm = 0;
				break;
			}
			lcm = lcm*leaves[i].first;
		}
		else {
			lcm = 0;
			break;
		}
	}


	if (lcm != 0) {
		long long minleaves = (leaves[0].second/lcm)*lcm;
		
		for(int i = 1; i < leaves.size(); i++) {
			minleaves = min(minleaves, (leaves[i].second/lcm)*lcm);
		}

		if (lcm > LLONG_MAX/leaves.size()) {
			return make_pair(0, minleaves*leaves.size());
		}

		return make_pair(lcm*leaves.size(), minleaves*leaves.size());
	}
	else {
		return make_pair(0, 0);
	}
}

int main()
{
	int n;
	cin>>n;

	graph.resize(n);
	a.resize(n);
	visited.resize(n, false);

	for(int i = 0; i < n; i++)
		cin>>a[i];

	for(int i = 0; i < n-1; i++) {
		int x, y;
		cin>>x>>y;
		x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	pair<long long, long long> p = solve(0);

	long long sum = 0;
	for(int i = 0; i < a.size(); i++)
		sum += a[i];

	cout<<sum-p.second<<endl;

	return 0;
}