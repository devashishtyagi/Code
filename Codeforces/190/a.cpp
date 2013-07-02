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

bool check(int a, int b) {
	if (a == -2 || b == -2)
		return false;
	else if (a == -1 && b != -2)
		return true;
	else if (a != -2 && b == -1)
		return true;
	else if (a == b)
		return true;
	return false;
}

int main()
{
	int a, b;
	cin>>a>>b;

	int x = 0, y = 0;
	string s;
	cin>>s;

	int xc[s.size()+1], yc[s.size()+1];
	xc[0] = 0; yc[0] = 0;

	for(int i = 0; i < s.size(); i++) {
		if (s[i] == 'U')
			y++;
		if (s[i] == 'D')
			y--;
		if (s[i] == 'L')
			x--;
		if (s[i] == 'R')
			x++;
		xc[i+1] = x;
		yc[i+1] = y;
	}

	for(int i = 0; i <= s.size(); i++) {
		int adiv = -2, bdiv = -2;

		if (x == 0 && a-xc[i] == 0)
			adiv = -1;
		else if (x != 0 && (a-xc[i])%x == 0 && (a-xc[i])/x >= 0)
			adiv = (a-xc[i])/x;

		if (y == 0 && b-yc[i] == 0)
			bdiv = -1;
		else if (y != 0 && (b-yc[i])%y == 0 && (b-yc[i])/y >= 0)
			bdiv = (b-yc[i])/y;

		if (check(adiv, bdiv)) {
			cout<<"Yes"<<endl;
			return 0;
		}
	}

	cout<<"No"<<endl;

	return 0;
}
