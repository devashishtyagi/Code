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
	int n;
	cin>>n;

	vector< pair<int,int> > points(n);

	forn(i, 0, n) {
		int x, y;
		cin>>x>>y;
		points[i].first = x+y;
		points[i].second = x-y;
	}

	sort(points.begin(), points.end());

	int minYL[n], maxYL[n], minYR[n], maxYR[n];

	minYL[0] = points[0].second; maxYL[0] = points[0].second;
	forn(i, 1, n) {
		minYL[i] = min(minYL[i-1], points[i].second);
		maxYL[i] = max(maxYL[i-1], points[i].second);
	}

	minYR[n-1] = points[n-1].second; maxYR[n-1] = points[n-1].second;
	rforn(i, n-1, 0) {
		minYR[i] = min(minYR[i+1], points[i].second);
		maxYR[i] = max(maxYR[i+1], points[i].second);
	}

	LL L = 0, R = 2*INF;

	while(L < R) {
		LL S = (L+R)/2;

		int j = 0;
		bool can = false;

		forn(i, 0, n) {
			while(j < n-1 && points[j+1].first - points[i].first <= S)
				j++;


			if (i == 0 && j == n-1){
				can = true;
				break;
			}

			int minY = INF, maxY = -INF;

			if (i > 0) {
				minY = min(minY, minYL[i-1]);
				maxY = max(maxY, maxYL[i-1]);
			}

			if (j < n-1) {
				minY = min(minY, minYR[j+1]);
				maxY = max(maxY, maxYR[j+1]);
			}

			if (maxY - minY <= S){			
				can = true;
				break;
			}
		}

		if (can) {
			R = S;
		}
		else{
			L = S+1;
		}
	}

	printf("%.8lf\n", (double)L*0.5);

	return 0;
}
