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
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> A(n);
	vector<int> B(n);

	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &B[i]);

	vector<double> X(n);
	vector<double> Y(n);
 
	for(int i = 0; i < n; i++) {
		X[i] = (double)(A[i] - B[i])/2.0;
		Y[i] = (double)(A[i] + B[i])/2.0;
	}

	while(q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--; r--;
		vector<double> tx, ty;
		for(int i = l; i <= r; i++)
			tx.push_back(X[i]), ty.push_back(Y[i]);
		sort(tx.begin(), tx.end());
		sort(ty.begin(), ty.end());

		int mid = (r-l+1)/2;

		double ans = 0;
		for(int i = 0; i < tx.size(); i++) {
			ans += abs(tx[i] - tx[mid]);
			ans += abs(ty[i] - ty[mid]);
		}
		printf("%lf\n", ans);			
	}
	return 0;
}
