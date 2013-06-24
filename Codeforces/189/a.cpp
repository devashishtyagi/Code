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
#define MOD 1000000007
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

int binpow(int n, int x) {
	if (x == 0)
		return 1;
	else {
		int v = binpow(n, x/2);
		v = v*1LL*v%MOD;
		if (x&1) {
			v = v*1LL*n%MOD;
		}
		return v;
	}
}

int main()
{
	string x;
	cin>>x;

	reverse(x.begin(), x.end());

	int n = x.size();

	int ans = 0;
	int mod2 = 1;

	for(int i = 0; i < n; i++) {
		ans = 2*1LL*ans%MOD;
		if (x[i] == '1')
			ans = ((LL)ans + mod2*1LL*mod2)%MOD;
		mod2 = mod2*1LL*2%MOD;
	}

	cout<<ans<<endl;

	return 0;
}
