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


int main()
{
	int n, m;
	cin>>n>>m;
	vector<int> correct(n), wrong(m);
	int low = 0, high = 101;

	for(int i = 0; i < n; i++) {
		cin>>correct[i];
		low = max(low, correct[i]);
	}

	sort(correct.begin(), correct.end());

	for(int i = 0; i < m; i++) {
		cin>>wrong[i];
		high = min(high, wrong[i]);
	}

	int ans = -1;

	for(int i = low; i < high; i++) {
		if (2*correct[0] <= i) {
			ans = i;
			break;
		}
	}

	cout<<ans<<endl;

	return 0;
}
