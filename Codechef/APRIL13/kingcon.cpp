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

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 3.1415926535897932

using namespace std;
typedef long long ll;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int convertString(string s)
{
    int num;
    stringstream sstr(s); // create a stringstream
    sstr>>num; // push the stream into the num
    return num;
}

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

vector< vector<int> > graph(3005);
bool visited[3005];
int tim[3005], fup[3005];
bool isCut[3005];
int vertices, timer;

void init() {
	for(int i = 0; i < 3005; i++) 
		graph[i].clear();
	CLEAR(visited);
	CLEAR(tim);
	CLEAR(fup);
	CLEAR(isCut);
	vertices = 0;
	timer = 0;
}

void dfs(int v, int p) {
	visited[v] = true;
	tim[v] = fup[v] = timer++;
	int children = 0;
	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
		if (to == p) continue;
		if (visited[to]) {
			fup[v] = min(fup[v], tim[to]);
		}
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] >= tim[v] && p != -1)
				isCut[v] = true;
			children++;
		}
	}
	if (p == -1 && children > 1)
		isCut[v] = true;
}

int main()
{
	int t;
	sf(t);
	while(t--) {
		init();
		int n,m,k;
		sf(n); sf(m); sf(k);
		for(int i = 0; i < m; i++) {
			int a,b;
			sf(a); sf(b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(0, -1);
		for(int i = 0; i < n; i++)
			if (isCut[i])
				vertices++;
		pf(vertices*k);
	}
	return 0;
}
