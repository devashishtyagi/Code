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
typedef long long ll;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int convertString(string s)
{
    int num;
    stringstream sstr(s); // create a stringstream
    sstr>>num; // push the stream into the num
    return num;
}

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

vector<int> dp(14,0);
int f[14][10][10];
long long pow_10[14];

void init(){
	dp[1] = 0;
	dp[2] = 9;
	for(int i=3; i<14; i++){
		dp[i] = dp[i-1] + dp[i-2]*9;
	}
	for(int i=3; i<14; i++){
		dp[i] += dp[i-1];
	}
	pow_10[0] = 1;
	for(int i=1; i<14; i++)
		pow_10[i] = pow_10[i-1]*10;
	
	memset(f, -1, sizeof f);
}

int solve(int i, int j, int k){
	if (i == 0)
		return (j == k) ? 1:0;
	if (f[i][j][k] != -1)
		return f[i][j][k];
	f[i][j][k] = 0;
	if (j == k){
		for(int l=0; l<10; l++){
			f[i][j][k] += solve(i-1, l, j);
		}
	}
	else{
		f[i][j][k] += solve(i-1, j, j);
	}
	return f[i][j][k];
}

long long dfs(int l, int n, int p, int q){
	if (l == 0 && n == 1)
		return (p == q)?0:-1;
	long long ans = 0;
	if (p == q){
		for(int i=0; i<10; i++){
			if (i == p){
				int val = solve(l-1, p, p);
				if (n <= val){
					ans = p*pow_10[l-1] + dfs(l-1, n, p, p);
					break;
				}
				else{
					n -= val;
				}
			}
			else{
				int val = (l >= 2) ? solve(l-2, i, i): 0;
				if (n <= val){
					ans = i*pow_10[l-1] + i*pow_10[l-2] + dfs(l-2, n, i, i);
					break;
				}
				else{
					n -= val;
				}
			}
		}
	}
	else{
		ans = p*pow_10[l-1] + dfs(l-1, n, p, p);
	}
	return ans;
}

int main()
{
	init();
	int t;
	cin>>t;
	while(t--){
		int a;
		cin>>a;
		int len = (lower_bound(dp.begin()+2, dp.end(), a) - dp.begin());
		if (len > 2)
			a -= dp[len-1];
		long long num = 0;
		for(int i=1; i<10; i++){
			int val = solve(len-2, i, i);
			if (a <= val){
				num = i*pow_10[len-1] + i*pow_10[len-2] + dfs(len-2, a, i, i);
				break;
			}
			else{
				a -= val;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
