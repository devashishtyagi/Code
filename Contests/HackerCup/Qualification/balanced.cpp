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

int dp[101][101];
string str;

int singleChar(char c){
	if (c >= 'a' && c <= 'z')
		return 1;
	else if (c == ' ')
		return 1;
	else if (c == ':')
		return 1;
	else
		return 0;
}

int solve(int i, int j){
	if (i > j)
		return 1;
	if (i == j)
		return singleChar(str[i]);
	if ((j-i) == 1){
		if (str[i] == ':' && (str[i+1] == '(' || str[i+1] == ')'))
			return 1;
	}
	if (dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = 0;
	if (str[i] == '(' && str[j] == ')')
		dp[i][j] |= solve(i+1,j-1);
	for(int k=i; k<j; k++)
		dp[i][j] |= (solve(i,k) & solve(k+1,j));
	return dp[i][j];
}

int main(){
	int n;
	char extra;
	cin>>n;
	extra = getchar();
	for(int i=0; i<n; i++){
		memset(dp, -1, sizeof dp);
		getline(cin, str, '\n');
		if (solve(0, str.size() - 1) == 1){
			cout<<"Case #"<<i+1<<": YES"<<endl;
		}
		else{
			cout<<"Case #"<<i+1<<": NO"<<endl;
		}
	}
	return 0;
}