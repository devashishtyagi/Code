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

int n, l, r, Ql, Qr;
vector<int> w;

int main()
{
	cin>>n>>l>>r>>Ql>>Qr;
	w.resize(n);

	for(int i = 0; i < n; i++)
		cin>>w[i];

	vector<int> suml(n+1, 0);
	vector<int> sumr(n+1, 0);

	for(int i = 0; i < n; i++) {
		suml[i+1] = suml[i] + w[i]*l;
		sumr[i+1] = sumr[i] + w[i]*r;
	}

	int ans = -1;

	for(int i = 0; i <= n; i++) {
		int extra = (n-i) - i;
		if (extra > 1) {
			extra = (extra-1)*Qr;
		}
		else if (extra < -1) {
			extra = -(1+extra)*Ql;
		}
		else
			extra = 0;
		int cost = suml[i] + sumr[n]-sumr[i] + extra;
		if (ans == -1 || ans > cost) {
			ans = cost;
			//cout<<i<<" "<<cost<<" "<<extra<<endl;
		}
	}

	cout<<ans<<endl;

	return 0;
}
