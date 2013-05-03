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

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

int main()
{
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector< pair<int,int> > B(n);
		for(int i = 0; i < n; i++)
			cin>>B[i].second>>B[i].first;
		
		sort(B.begin(), B.end());
		
		map<int,int> mymap;
		int t = 0;
		for(int i = 0; i < n; i++){
			if (mymap.find(B[i].second) == mymap.end()) {
				mymap[B[i].second] = t;
				B[i].second = t++;
			}
			else {
				B[i].second = mymap[B[i].second];
			}
		}

		int distinct = 0;
		long long ans = 0;
		vector<bool> seen(t, false);
		for(int i = 0; i < n; i++) {
			if (seen[B[i].second]) {
				ans += B[i].first*1LL*t;
			}
			else {
				seen[B[i].second] = true;
				distinct++;
				ans += B[i].first*1LL*distinct;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
