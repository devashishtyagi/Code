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

#define PI 3.1415926535897932

using namespace std;
typedef long long ll;

const long long INF  = 100000000000000000;

int v[100001];
int c[100001];
int c1,c2; // 2 different colors with max value

long long solve(long long a, long long b, int n){
	vector<long long> colorMax(n+1, -INF);
	c1 = c[0]; c2 = -1;
	colorMax[c[0]] = b*v[0];
	long long ans = max(colorMax[c[0]], 0LL);
	
	for(int i=1; i<n; i++){
		long long value = colorMax[c[i]];
		//cout<<i<<" "<<value<<endl;
		value = max(colorMax[c[i]]+a*v[i], colorMax[c[i]]);
		//cout<<i<<" "<<value<<endl;
		value = max(b*v[i], value);
		//cout<<i<<" "<<value<<endl;
		if (c1 != -1){
			if (c1 == c[i]){
				value = max(value, colorMax[c1]+v[i]*a);
			}
			else{
				value = max(value, colorMax[c1]+v[i]*b);
			}
		}
		//cout<<i<<" "<<value<<endl;
		if (c2 != -1){
			if (c2 == c[i]){
				value = max(value, colorMax[c2]+v[i]*a);
			}
			else{
				value = max(value, colorMax[c2]+v[i]*b);
			}
		}
		//cout<<i<<" "<<value<<endl;
		colorMax[c[i]] = value;
		if (colorMax[c[i]] > colorMax[c1] && c[i] != c1){
			c2 = c1;
			c1 = c[i];
		}
		else if ((c2 == -1 || colorMax[c[i]] > colorMax[c2]) && c[i] != c1){
			c2 = c[i];
		}
		ans = max(ans, value);
	}
	return ans;
}

int main()
{
	int n,q;
	cin>>n>>q;
	
	FOR(i,0,n)
		cin>>v[i];
	FOR(i,0,n)
		cin>>c[i];
		
	FOR(i,0,q){
		long long a,b;
		cin>>a>>b;
		cout<<solve(a,b,n)<<endl;
	}
}
