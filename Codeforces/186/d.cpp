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

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1E18
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
	int n, m, l;
	cin>>n>>m>>l;

	LL cost[n+4][n+4];
	LL dp[n+4][n+4];


	fill(cost[0], cost[n+1], INF);
	fill(dp[0], dp[n+1], INF);

	forn(i, 0, m){
		int a, b, c;
		cin>>a>>b>>c;
		a--;
		cost[a][b] = min(cost[a][b], (LL)c);
	}

	forn(i, 0, n+1) {
		forn(j, 1, i+1) {
			cost[j][i] = min(cost[j-1][i], cost[j][i]);
		}
	}

	dp[0][0] = 0;
	forn(i, 0, n+1) {
		forn(j, 0, n+1) {
			if (dp[i][j] == INF)
				continue;
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			forn(k, i+1, n+1) {
				dp[k][j+(k-i)] = min(dp[k][j+(k-i)], dp[i][j] + cost[i][k]);
			}
		}
	}

	LL ans = INF;

	forn(i, l, n+1) {
		ans = min(ans, dp[n][i]);
	}

	if (ans == INF){
		cout<<-1<<endl;
	}
	else {
		cout<<ans<<endl;
	}

	return 0;
	
}