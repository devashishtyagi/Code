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
#define MOD 1000000009
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;


int powmod(int a, int n) {
	if (n == 0)
		return 1;
	else {
		int x = powmod(a, n/2);
		x = x*1LL*x%MOD;
		if (n&1)
			x = x*1LL*a%MOD;
		return x;
	}
}

int main()
{
	int n, m, k;
	cin>>n>>m>>k;

	int x = (n-m);

	if ((k-1)*1LL*x >= m) {
		cout<<m<<endl;
	}
	else {
		int l = m - (k-1)*x;
		int p = l/k;
		int rem = l%k;
		int ans = powmod(2, p+1);
		//cout<<"Pow "<<ans<<endl;
		ans = (ans - 2 + MOD)%MOD;
		ans = ans*1LL*k%MOD;
		//cout<<ans<<endl;
		ans = (ans + rem)%MOD;
		//cout<<ans<<endl;
		ans = (ans + 0LL + (k-1)*x)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
