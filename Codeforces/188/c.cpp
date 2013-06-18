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

int dp[(1<<20)];

int grundy(int nums, int choosen) {
	vector<int> taken(nums+1, 0);

	if (choosen < (1<<20) && dp[choosen] != -1)
		return dp[choosen];

	for(int i = 0; i < nums; i++) {
		if ((choosen>>i) & 1)
			continue;
		int newchoosen = choosen;
		int element = i+1;
		while(element <= nums) {
			if (!((newchoosen>>(element-1)) & 1))
				newchoosen += (1<<(element-1));
			element += (i+1);
		}
		taken[grundy(nums, newchoosen)]++;
	}

	int x = 0;
	for(int i = 0; i < taken.size(); i++) {
		if (taken[x] > 0)
			x++;
		else
			break;
	}

	if (choosen < (1<<20))
		dp[choosen] = x;

	return x;
}

int main()
{
	
	for(int i = 1; i <= 29; i++) {
		memset(dp, -1, sizeof dp);
		cout<<grundy(i, 0)<<endl;
	}
}
