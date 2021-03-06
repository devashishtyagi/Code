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
#define MOD 1000000007 

using namespace std;
typedef long long ll;

int C[1001][1001];

void init(){
	memset(C, 0, sizeof C);
	C[0][0] = 1;
	for(int i=1; i<1001; i++){
		C[i][0] = 1;
		for(int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
	}
}

int pow(int n, int p){
	if (p == 0)
		return 1;
	else if (p&1)
		return (ll)n*pow(n,p-1)%MOD;
	else{
		int value = pow(n,p/2);
		return (ll)value*value%MOD;
	}
}

int main()
{
	int t;
	init();
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			int temp;
			cin>>temp;
		}
		int ans = pow(2,n-1);
		if (!(n&1)){
			ans = ans - (ll)C[n][n/2]*500000004%MOD;
			ans = (ans+MOD)%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
