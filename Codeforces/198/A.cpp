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

long long gcd(long long a, long long b) {
	if (a == 0)
		return b;
	else if (a > b)
		return gcd(b, a);
	else
		return gcd(b%a, a);
}

int main()
{
	int n;
	cin>>n;

	vector<int> A(n);

	for(int i = 0; i < n; i++)
		cin>>A[i];

	sort(A.begin(), A.end());

	long long denom = n, num = 0;

	for(int i = 0; i < n; i++) {
		int index = (lower_bound(A.begin(), A.end(), A[i]) - A.begin());
		int p = index, q = n-index-1;
		long long tnum = A[i] - q*2LL*A[i] + p*2LL*A[i];
		num += tnum;
	}

	long long g = gcd(num, denom);

	cout<<num/g<<" "<<denom/g<<endl;

	return 0;
}
