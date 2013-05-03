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
typedef long long LL;

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

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
	    elems.push_back(item);
	}
}

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

int l, r;
bool visited[500];
vector< vector<int> > graph;
vector< vector<int> > number;

void dfs(int v) {
	visited[v] = true;
	for(int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
		int num = number[v][i];
		if ((num >= l && num <= r) || visited[to])
			continue;
		dfs(to);
	}
}

int main()
{
	int n, m;
	sf(n); sf(m);
	graph.resize(n);
	number.resize(n);

	for(int i = 0; i < m; i++) {
		int x,y;
		sf(x); sf(y);
		x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
		number[x].push_back(i+1);
		number[y].push_back(i+1);
	}

	int k;
	sf(k);

	for(int i = 0; i < k; i++) {
		memset(visited, false, sizeof visited);
		sf(l); sf(r);
		int parts = 0;
		for(int j = 0; j < n; j++) {
			if (!visited[j]){
				dfs(j);
				parts++;
			}
		}
		pf(parts);
	}

	return 0;
}
