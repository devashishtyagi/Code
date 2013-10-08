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
#include <cassert>


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


bool check(long long x, vector<int>& a) {
	long long tmp = 0;
	for(int i = 0; i < a.size(); i++) {
		if (x < a[i])
			return false;
		tmp += (x-a[i]);
	}

	if (tmp >= x)
		return true;
	else
		return false;

}

int main()
{
	int n;
	cin>>n;

	vector<int> a(n);

	for(int i = 0; i < n; i++)
		cin>>a[i];

	sort(a.begin(), a.end());

	long long low = 1, high = 10E12;

	while(low < high) {
		long long mid = (low+high)/2;

		if (check(mid, a)) {
			high = mid;
		}
		else {
			low = mid+1;
		}
	}

	assert(low == high);

	cout<<low<<endl;

	return 0;
}
