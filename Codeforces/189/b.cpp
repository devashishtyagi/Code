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

int main()
{
	int n;
	cin>>n;
	int a[n];

	for(int i = 0; i < n; i++)
		cin>>a[i];

	int steps = 0;
	stack< pair<int,int> > S;

	S.push(mp(a[n-1], 0));

	for(int i = n-2; i >= 0; i--) {
		int killed = 0;

		while(!S.empty() && S.top().first < a[i]){
			int op = S.top().second;
			S.pop();
			killed += (max(0, op-killed-1) + 1);
		}

		steps = max(steps, killed);

		S.push(mp(a[i], killed));
	}

	cout<<steps<<endl;


	return 0;
}
