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

int main()
{
	int n, m;
	cin>>n>>m;
	int color[n];
	vector< vector<int> > graph(n);
	FOR(i, 0, m){
		int a, b;
		cin>>a>>b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	memset(color, 0, sizeof color);
	
	queue<int> Q;
	FOR(i, 0, n) {
		if (graph[i].size() > 1)
			Q.push(i);
	}

	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();
		int count[] = {0, 0};
		FOR(j, 0, graph[v].size()) {
			if (color[graph[v][j]] == 0)
				count[0]++;
			else
				count[1]++;
		}
		if (count[color[v]] <= 1)
			continue;
		color[v] = color[v]^1; 
		FOR(i, 0, graph[v].size()) {
			int samecount = 0;
			int u = graph[v][i];
			FOR(j, 0, graph[u].size()) {
				if (color[graph[u][j]] == color[u])
					samecount++;
			}
			if (samecount > 1)
				Q.push(u);
		}
	}
	FOR(i, 0, n)
		cout<<color[i];
	cout<<endl;
	return 0;
}