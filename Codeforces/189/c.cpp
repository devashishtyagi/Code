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

LL a[100001];
LL b[100001];
vector< pair<LL, LL> > s;
int ptr = 0;

double intersection(pair<LL, LL> p1, pair<LL, LL> p2) {
	double x = (p1.second - p2.second);
	x = x/(double)(p2.first - p1.first);
	return x;
}

void add(pair<LL, LL> p) {
	if (s.size() < 2) {
		s.push_back(p);
	}
	else {
		pair<LL, LL> p1 = s[s.size()-1];
		pair<LL, LL> p2 = s[s.size()-2];
		if (intersection(p1, p) <= intersection(p2, p)) {
			s.pop_back();
			ptr = min(ptr, (int)s.size()-1);
			add(p);
		}
		else {
			s.push_back(p);
		}
	}
}

LL find(LL x) {
	while(ptr+1 < s.size() && (s[ptr].first*x + s[ptr].second >= s[ptr+1].first*x + s[ptr+1].second))
		ptr++;
	return s[ptr].first*x + s[ptr].second;
}

int main()
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = 0; i < n; i++)
		cin>>b[i];

	LL ans = 0;
	add(make_pair(b[0], 0));

	for(int i = 1; i < n; i++) {
		ans = find(a[i]);
		add(make_pair(b[i], ans));
	}

	cout<<ans<<endl;

	return 0;
}
