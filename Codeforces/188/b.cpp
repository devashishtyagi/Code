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

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define init0(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define MOD 1000000009
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

int dp[2][203][203];

int main()
{
	int n;
	cin>>n;

	init0(dp[0]);

	bool change = true;
	dp[0][101][101] = n;
	int prev = 0, now = 1;

	while(change) {
		change = false;
		
		init0(dp[now]);

		for(int i = 1; i < 202; i++) {
			for(int j = 1; j < 202; j++) {
				dp[now][i][j] += dp[prev][i][j]%4;
				if (dp[prev][i][j] >=4 ) {
					change = true;
					int dispersed = dp[prev][i][j]/4;
					dp[now][i+1][j] += dispersed;
					dp[now][i-1][j] += dispersed;
					dp[now][i][j+1] += dispersed;
					dp[now][i][j-1] += dispersed;
				}
			}
		}
		swap(prev, now);
	}

	int t;
	cin>>t;

	while(t--) {
		int x, y;
		cin>>x>>y;
		if (abs(x) <= 100 && abs(y) <= 100) 
			cout<<dp[prev][x+101][y+101]<<endl;
		else
			cout<<0<<endl;
	}

	return 0;
}
