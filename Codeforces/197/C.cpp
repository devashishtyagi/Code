/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <functional>
#include <numeric>
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


// Compiler utility
#define int_msb(x) ((31) - __builtin_clz(x))

#define sf(a) scanf("%d",&a)
#define ssf(a,b) scanf("%d %d",&a,&b)
#define pf(a) printf("%d\n",a)
#define foreach(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.end()

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define init0(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define MOD 1000000009
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;


vector<int> moves;
int dp[11][11][1001];
int m;


int dfs(int diff, int last, int n) {
	if (n >= m)
		return 1;

	if (dp[diff][last][n] != -1)
		return dp[diff][last][n];

	int ans = 0;

	for(int i = 0; i < moves.size(); i++) {
		if (moves[i] != last && moves[i]-diff > 0)
			ans |= dfs(moves[i]-diff, moves[i], n+1);
	}
	
	dp[diff][last][n] = ans;

	return dp[diff][last][n];
}

void reconstruct(int diff, int last, int n) {
	
	if (n >= m)
		return;

	for(int i = 0; i < moves.size(); i++) {
		if (moves[i] != last && moves[i]-diff > 0 && (n+1 >= m || dp[moves[i]-diff][moves[i]][n+1] == 1)) {
			cout<<moves[i]<<" ";
			reconstruct(moves[i]-diff, moves[i], n+1);
			return;
		}			
	}
}

int main()
{
	memset(dp, -1, sizeof dp);

	string str;
	cin>>str;

	for(int i = 0; i < 10; i++) {
		if (str[i] == '1')
			moves.push_back(i+1);
	}

	cin>>m;

	if (dfs(0, 0, 0) == 1) {
		cout<<"YES"<<endl;
		reconstruct(0, 0, 0);
		cout<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}

	return 0;
}
