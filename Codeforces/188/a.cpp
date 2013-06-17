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
#define MOD 1000000009
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

int main()
{
	LL x, y, m;
	cin>>x>>y>>m;

	if (x <= 0 && y <= 0) {
		if (m <= max(x,y))
			cout<<0<<endl;
		else
			cout<<-1<<endl;
		return 0;
	}

	if (x > y)
		swap(x,y);

	long long op = 0;
	while(y < m) {
		long long mult = max(-x, 0LL)/y + 1;
		op += mult;
		x += mult*y;
		if (x > y)
			swap(x, y);
	}

	cout<<op<<endl;

	return 0;
}
