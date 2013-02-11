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

string str;
int dp[2][2][201];

int toggle(int a){
	return (a^1);
}

int solve(int a, int b, int index){
	if (index >= str.size())
		return 0;
	if (dp[a][b][index] != -1)
		return dp[a][b][index];

	dp[a][b][index] = INF;
	int next1 = str[index]-'0', next2;
	if (index+1 < str.size())
		next2 = str[index+1]-'0';
	// INSTR R and T
	if (next1 == a || next1 == b)
		dp[a][b][index] = min(dp[a][b][index], solve(a,b,index+1)+1);
	// INSTR E
	if (next1 == a && next2 == b)
		dp[a][b][index] = min(dp[a][b][index], solve(a,b,index+2)+1);
	// INSTR W
	dp[a][b][index] = min(dp[a][b][index], solve(a,toggle(b),index)+1);
	// INSTR Q
	dp[a][b][index] = min(dp[a][b][index], solve(toggle(a),b,index)+1);

	return dp[a][b][index];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp, -1, sizeof dp);
		cin>>str;
		cout<<solve(0,0,0)<<endl;
	}
	return 0;
}