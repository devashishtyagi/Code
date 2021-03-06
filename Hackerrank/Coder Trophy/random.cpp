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

int main()
{
	int n;
	long long t;
	cin>>n>>t;
	vector<int> D(n);
	for(int i=0; i<n; i++)
		cin>>D[i];
	
	int l = 0, r = 0;
	long long sum = 0;
	double denom = (double)n*(n+1), result = 0.0;
	denom = 2.0/denom;
	while(l < n){
		r = max(r, l);
		while(r < n && sum+D[r] <= t){
			sum += D[r];
			r++;
		}
		long long p = max(r-l, 0);
		result += p*denom;
		sum = max(sum - D[l], 0LL);
		l++;
	}
	cout<<result<<endl;
	return 0;
}
