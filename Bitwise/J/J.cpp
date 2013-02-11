using namespace std;
#include <cmath>
#include <cstdio>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
typedef long long ll; 
typedef pair<int,int> pii; 
#define FOR(i,n) for (int i = 0; i < n; i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define MP make_pair
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)

#define MOD 1000000007

const int maxn = 10000005;
int totalCases, testNum;
int N,M;
int g[maxn], h[maxn];

void input(){
	sf(M); sf(N);
}

void solve(){
	if (M == 1){
		pf(0);
		return;
	}
	g[0] = 1; h[0] = 1;
	for(int i = 1; i <= min(N,M-1); i++){
		g[i] = g[i-1]*1ll*M%MOD;
		h[i] = g[i]%MOD;
	}
	if (N >= M)
		h[M-1] = (h[M-1]-1+MOD)%MOD;
	for(int i = M; i <= N; i++){
		g[i] = ((M-1)*1ll*g[i-1]%MOD + h[i-1] + 0ll)%MOD;
		h[i] = g[i];
		h[i] = (h[i] - (M-2)*1ll*g[i-M]%MOD)%MOD;
		if (h[i] < 0)
			h[i] += MOD;
		h[i] = (h[i] - h[i-M])%MOD;
		if (h[i] < 0)
			h[i] += MOD;
	}
	pf(g[N]);
}


int main()
{
  sf(totalCases);
  for(testNum = 1; testNum <= totalCases; testNum++)
  {
    input();
    solve();
  }
}