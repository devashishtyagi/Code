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
#define two(x) ((1)<<(x))

#define PB push_back
#define MP make_pair
#define sz(a) (int)(a).size()

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define MOD 1000000007
#define PI 3.1415926535897932

using namespace std;


int trees(int n, int p){
	if (p == 0)
		return 1LL;
	else if (p % 2 == 1)
		return (long long)n*trees(n,p-1)%MOD;
	else{
		int value = trees(n, p/2);
		return (long long)value*value%MOD;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> b(n);
		for(int i=0; i<n; i++)
			cin>>b[i];
		long long ans = 1;
		memset(dp, -1, sizeof dp);
		ans = solve(two(n)-1);
		for(int i=0; i<n; i++){
			if (b[i] >= 2)
				ans = ans*trees(b[i], b[i]-2)%MOD;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
