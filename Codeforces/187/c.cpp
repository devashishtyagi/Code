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

LL tree[1000002];
int MAXN = 1000000;

void add(int i, int v) {
	while(i <= MAXN) {
		tree[i] += v;
		if (tree[i] >= MOD)
			tree[i] %= MOD;
		i += (i & -i);
	}
}

int get(int i) {
	LL sum = 0;
	while(i > 0) {
		sum += tree[i];
		if (sum  >= MOD)
			sum %= MOD;
		i -= (i & -i);
	}
	return (int)sum;
}



int main()
{
	int n;
	cin>>n;
	int a[n];
	forn(i, 0, n)
		cin>>a[i];

	init0(tree);

	forn(i, 0, n) {
		int sum = get(a[i]);
		sum = sum*1LL*a[i]%MOD;
		sum = (sum + a[i])%MOD;
		add(a[i], sum);
	}

	cout<<get(a[n-1])<<endl;

	return 0;
}
