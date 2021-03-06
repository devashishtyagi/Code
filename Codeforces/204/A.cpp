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
	int n;
	cin>>n;

	vector<double> a(2*n);
	vector<double> decimal(2*n);
	int zero = 0;
	double sum = 0.0;

	for(int i = 0; i < 2*n; i++) {
		cin>>a[i];
		decimal[i] = a[i]-trunc(a[i]);
		sum += decimal[i];
		if (decimal[i] == 0.0)
			zero++;
	}

	//cout<<sum<<" "<<zero<<endl;

	double ans = -1.0;
	for(int i = 0; i <= n; i++) {
		double temp = abs(sum-i);
		if (n-i <= zero) {
			if (ans == -1.0 || ans > temp)
				ans = temp;
		}
	}

	printf("%.3lf\n", abs(ans));

	return 0;
}
