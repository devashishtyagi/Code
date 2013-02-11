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
	long long totalsum = 0, psum = 0, sum = 0, subarrays = 0;
	while(l < n){
		r = max(r, l);
		while(r < n && sum+D[r] <= t){
			sum += D[r];
			psum += sum;
			r++;
		}
		long long p = max(r-l, 0);
		subarrays += p;
		totalsum += psum;
		if (p > 0){
			psum = max(psum - p*D[l], 0LL);
		}
		else{
			psum = 0;
		}
		sum = max(sum - D[l], 0LL);
		l++;
	}
	double expectedValue;
	if (subarrays != 0)
		expectedValue = (double)totalsum/(double)subarrays;
	else
		expectedValue = 0.0;
		
	printf("%.12f\n",expectedValue);
	return 0;
}
