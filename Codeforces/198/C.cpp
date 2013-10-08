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
#define MOD 1000000007
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

int perm[2001];
int dp[2001][2001];

void init() {
	perm[0] = 1;
	for(int i = 1; i < 2001; i++) {
		perm[i] = perm[i-1]*1LL*i%MOD;
	}
	memset(dp, -1, sizeof dp);
}

int solve(int x, int y) {
	if (dp[x][y] != -1)
		return dp[x][y];

	int &res = dp[x][y];
	res = 0;
	if (x == 0) {
		res = perm[y];
	}
	else {
		if (x >= 2) 
			res = (res + solve(x-2, y+1)*1LL*(x-1)%MOD)%MOD;
		if (y != 0)
			res = (res + solve(x-1, y)*1LL*y%MOD)%MOD;
	}

	return res;
}


int main()
{
	int n;
	cin>>n;

	init();

	vector<int> a(n);

	int x = 0, y = 0;
	for(int i = 0; i < n; i++) {
		cin>>a[i];
		if (a[i] == -1)
			x++;
	}
	for(int i = 0; i < n; i++) {
		if (a[i] != -1 && a[a[i]-1] == -1) {
			x--;
			y++;
		}
	}

	dp[0][0] = 1;
	dp[1][1] = 1;
	dp[1][0] = 0;
	dp[0][1] = 1;

	cout<<solve(x, y)<<endl;

	return 0;	
}
