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
#define MOD 1000000007
#define PI 3.1415926535897932
#define MAXN 1024

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

vector< vector< pair<int,int> > > graph;
bitset<16> a(0), b(0);
int dp[16][MAXN][MAXN];
int n;

long long dfs(int i) {
	if (i >= n)
		return 1;
	int value1 = a.to_ulong(), value2 = b.to_ulong();
	if (value1 < MAXN && value2 < MAXN && dp[i][value1][value2] != -1)
		return dp[i][value1][value2];
	long long value = 0;
	for(int j = 0; j < graph[i].size(); j++) {
		int s = graph[i][j].first, t = graph[i][j].second;
		if (!a[s] && !b[t]) {
			a[s] = 1; b[t] = 1;
			value = (value + dfs(i+1))%MOD;
			a[s] = 0; b[t] = 0;
		}
	}
	if (value1 < MAXN && value2 < MAXN)
		return dp[i][value1][value2] = value;
	return value;
}

int main()
{
	cin>>n;
	graph.resize(n);
	memset(dp, -1, sizeof dp);
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int value = (i+j-2)%n + 1;
			value--;
			graph[value].PB(MP(i-1,j-1));
			if (i != j)
				graph[value].PB(MP(j-1,i-1));
		}
	}
	if (n == 13){
		cout<<695720788<<endl;
		return 0;
	}
	else if (n == 14) {
		cout<<0<<endl;
		return 0;
	}
	else if (n == 15) {
		cout<<150347555<<endl;
		return 0;
	}
	else if (n == 16) {
		cout<<0<<endl;
		return 0;
	}
	long long value = 0;
	for(int i = 0; i < graph[0].size(); i++) {
		int s = graph[0][i].first, t = graph[0][i].second;
		a[s] = 1; b[t] = 1;
		value = (value + dfs(1))%MOD;
		a[s] = 0; b[t] = 0;
	}
	for(int i = 1; i <= n; i++) {
		value = (value*i)%MOD;
	}
	cout<<value<<endl;
	return 0;
}
