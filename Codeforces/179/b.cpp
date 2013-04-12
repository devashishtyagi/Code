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

int main()
{
	int n;
	sf(n);
	string s, w;
	cin>>s>>w;
	long long dp[n][2];
	long long equal = 1;
	long long all = 1, up = 1, down = 1;
	int subtract = 1;
	FOR(i, 0, n) {
		if (s[i] == '?' && w[i] == '?') {
			dp[i][0] = 55;
			dp[i][1] = 55;
			all = all*100%MOD; 
			equal = equal*10%MOD;
		}
		if (s[i] != '?' && w[i] == '?') {
			int v = s[i] - '0';
			dp[i][0] = v+1;
			dp[i][1] = (10-v);
			all = all*10%MOD; 	
		}
		if (s[i] == '?' && w[i] != '?') {
			int v = w[i] - '0';
			dp[i][0] = 10-v;
			dp[i][1] = (v+1);
			all = all*10%MOD;	
		}
		if (s[i] != '?' && w[i] != '?') {
			int l = (s[i] >= w[i]) ? 1:0;
			int m = (s[i] <= w[i]) ? 1:0;
			dp[i][0] = l;
			dp[i][1] = m;		
			if (s[i] != w[i])
				equal = 0;
		}
		up = up*dp[i][0]%MOD;
		down = down*dp[i][1]%MOD;
	}

	cout<<(all-up-down+equal+MOD)%MOD<<endl;
	return 0;
}
