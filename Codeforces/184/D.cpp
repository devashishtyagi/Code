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
typedef long long LL;

int binpow(int x, int n) {
	if (n == 0)
		return 1;
	else{
		int v = binpow(x, n/2);
		v = (LL)v*v%MOD;
		if (n&1)
			v = (LL)v*x%MOD;
		return v;
	}
}

int validJumps[1000001];
int jump[1000001];
int prefixSum[1000001];

int main()
{
	int n, m, k;
	cin>>n>>m>>k;
	LL ans = 0;

	CLEAR(jump);
	prefixSum[0] = 0;	
	validJumps[0] = 0;

	int end = n-k-1;

	FOR(i, 0, m) {
		int x, y;
		cin>>x>>y;
		if (y - x == k+1) {
			jump[x] = 1;
			end = min(end, y-1);
		}
		else if (y -x != 1)
			goto end;
	}

	FOR(i, 1, n+1) {
		prefixSum[i] = prefixSum[i-1] + jump[i];
		validJumps[i] = validJumps[i-1];
		if (i+k+1 <= n && i <= end)
			validJumps[i]++;
	}

	if (prefixSum[n] == 0)
		ans = 1;

	FOR(i, 1, end+1) {
		if ((prefixSum[n] - prefixSum[i+k]) == 0) {
			int value = (validJumps[i+k] - validJumps[i]) - (prefixSum[i+k] - prefixSum[i]);
			if (value >= 0) {
				ans += binpow(2, value);
				ans %= MOD;
			}
		}
		if (jump[i])
			goto end;
	}

	end:
	cout<<ans<<endl;
}