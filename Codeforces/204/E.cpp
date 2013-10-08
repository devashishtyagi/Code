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
	vector<int> a(n);
	vector<int> value;
	for(int i = 0; i < n; i++)
		cin>>a[i];

	int c = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++)
			if (a[j] < a[i])
				c++;

		int a1 = 0, a2 = 0;
		for(int j = 0; j < i; j++) {
			if (a[j] > a[i])
				a1++;
			if (a[j] > -a[i])
				a2++;
		}
		int b1 = 0, b2 = 0;
		for(int j = i+1; j < n; j++) {
			if (a[j] < a[i])
				b1++;
			if (a[j] < -a[i])
				b2++;
		}

		cout<<i<<" "<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;

		if (a2+b2-a1-b1 < 0) {
			a[i] = -a[i];
			c += (a2+b2-a1-b1);
			cout<<"Inversed "<<i<<endl;
		}
	}

	cout<<c<<endl;

	return 0;
}
