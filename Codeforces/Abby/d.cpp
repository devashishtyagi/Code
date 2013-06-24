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

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define init0(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define MOD 1000000007
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

int I[1000001];

int calculateI(int n) {
	if (I[n] != -1)
		return I[n];
	I[n] = (calculateI(n-1) + (n-1)*1LL*calculateI(n-2))%MOD;
	return I[n];
}

int binpow(int x, int n) {
	if (n == 0)
		return 1;
	else{
		int v = binpow(x, n/2);
		v = (v*1LL*v)%MOD;
		if (n%2 == 1) {
			v = (v*1LL*x)%MOD;
		}
		return v;
	}
}

int main()
{
	int n;
	cin>>n;
	int a = 0, b = 0;
	forn(i, 0, n) {
		int p;
		cin>>p;
		if (p == 1)
			a++;
		else 
			b++;
	}

	memset(I, -1, sizeof I);

	I[0] = 1;
	I[1] = 1;
	I[2] = 2;

	int Iv = calculateI(a);

	int factn = 1;
	forn(i, 1, n+1)
		factn = factn*1LL*i%MOD;
	int facta = 1;
	forn(i, 1, a+1)
		facta = facta*1LL*i%MOD;

	//cout<<facta<<" "<<factn<<" "<<Iv<<endl;

	int invfact = binpow(facta, MOD-2);

	//cout<<invfact<<endl;

	//cout<<binpow(2, 3)<<endl;

	int ans = Iv*1LL*factn%MOD;
	ans = ans*1LL*invfact%MOD;

	cout<<ans<<endl;
	return 0;
}
