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
#define init0(a) memset((a),0,sizeof(a))

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

vector<int> a;
vector<int> b;
vector<bool> visited;

int dfsa(int v) {
	visited[v] = true;
	if (a[v] == -1)
		return 1;
	return 1+dfsa(a[v]);
}

void dfsb(int v) {
	visited[v] = true;
	if (b[v] == -1)
		return;
	dfsb(b[v]);
}

int main() {
	int n, x;
	cin>>n>>x;
	x--;

	a.resize(n);
	b.resize(n, -1);
	visited.resize(n, false);

	forn(i, 0, n) {
		cin>>a[i];
		a[i]--;
		if (a[i] >= 0)
			b[a[i]] = i;
	}

	int pos = dfsa(x);
	dfsb(x);
	vector<int> lengths;

	forn(i, 0, n) {
		if (b[i] == -1 && !visited[i]) {
			lengths.push_back(dfsa(i));
		} 
	}

	if (lengths.size() > 0) {
		bool dp[lengths.size()][1001];
		memset(dp, false, sizeof dp);

		dp[0][0] = true;
		dp[0][lengths[0]] = true;

		forn(i, 1, lengths.size()) {
			forn(j, 0, 1001) {
				if (j >= lengths[i]) {
					dp[i][j] = (dp[i-1][j] | dp[i-1][j-lengths[i]]);
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}

		forn(i, 0, 1001) {
			if (dp[lengths.size()-1][i]) {
				cout<<pos+i<<endl;
			}
		}
	}
	else {
		cout<<pos<<endl;
	}

	return 0;
}
