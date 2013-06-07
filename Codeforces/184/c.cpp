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

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

vector< pair<LL,LL> > optimal;
int ptr;
LL dp[2][100001];

void add(pair<LL,LL> p) {
	if (optimal.size() < 2) {
		optimal.push_back(p);
	}
	else {
		int index = optimal.size() - 2;
		pair<LL,LL> p1 = optimal.at(index);
		pair<LL,LL> p2 = optimal.at(index+1);
		if ((p.second - p2.second)*(p1.first - p.first) <= (p2.first - p.first)*(p.second - p1.second)) {
			optimal.pop_back();
			if (ptr > 0){
				ptr--;
			}
			add(p);
		}
		else {
			optimal.push_back(p);
		}
	}
}

void exchg() {
	ptr = 0;
	optimal.clear();
}

LL find(LL j) {
	while(ptr < optimal.size() - 1  &&  (j*optimal[ptr].first + optimal[ptr].second) >= (j*optimal[ptr+1].first + optimal[ptr+1].second)){
		ptr++;
	}
	return (j*optimal[ptr].first + optimal[ptr].second);
}

int main()
{
	int n, m, p;
	scanf("%d %d %d",&n,&m,&p);

	int D[n];
	D[0] = 0;
	FOR(i, 0, n-1) {
		scanf("%d",&D[i+1]);
		D[i+1] += D[i];
	}

	vector<LL> times(m);
	LL total = 0;
	FOR(i, 0, m) {
		int s,t;
		scanf("%d %d",&s,&t);
		times[i] = t - D[s-1];
		total += (t - D[s-1]);
	}

	sort(times.begin(), times.end());

	int now = 0, prev = 1;
	FOR(i, 0, m) {
		dp[now][i] = (i+1)*times[i];
	}


	FOR(i, 1, p) {
		exchg();
		swap(now, prev);
		add(mp(1, 0));

		FOR(j, 0, m) {		
			add(mp(-j, dp[prev][j]));
			dp[now][j] = find(times[j]) + j*times[j];
		}
	}

	LL ans = dp[now][m-1];
	
	cout<<ans-total<<endl;

	return 0;
}
