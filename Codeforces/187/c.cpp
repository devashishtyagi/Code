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

#define PB push_back
#define MP make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define init0(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define MOD 1000000007
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

const int MAXN = 1000002;
int tree[MAXN];
int q[MAXN];

void add(int index, int v) {
	while(index <= MAXN) {
		tree[index] = ((LL)tree[index] + v)%MOD;
		index += (index & -index);
	}
}

int get(int index) {
	int sum = 0;
	while(index > 0) {
		sum = ((LL)tree[index]+sum)%MOD;
		index -= (index & -index);
	}
	return sum;
}

int main()
{
	int n;
	cin>>n;

	init0(tree);
	init0(q);

	int a[n];

	forn(i, 0, n)
		cin>>a[i];

	forn(i, 0, n) {
		int new_val = ((LL)get(a[i])*1LL*a[i]%MOD + a[i])%MOD;
		int change = ((LL)new_val - q[a[i]])%MOD;
		if (change < 0)
			change += MOD;
		q[a[i]] = new_val;
		add(a[i], change);
	}

	cout<<get(MAXN-1)<<endl;

	return 0;
}
