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
#define MOD 1000000000
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

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

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
	    elems.push_back(item);
	}
}

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

LL f[200001];

void init() {
	f[0] = 1;
	f[1] = 1;
	forn(i, 2, 200001) {
		f[i] = (f[i-1] + f[i-2])%MOD;
	}
}

int main()
{
	int n, m;
	cin>>n>>m;

	LL a[n];
	forn(i, 0, n)
		cin>>a[i];

	init();	

	forn(i, 0, m) {
		int t;
		cin>>t;
		if (t == 1) {
			int x, v;
			cin>>x>>v;
			x--;
			a[x] = v;
		}
		else if (t == 2) {
			int l, r;
			cin>>l>>r;
			l--; r--;
			LL ans = 0;
			forn(i, 0, r-l+1) {
				//cout<<f[i]<<endl;
				ans = (ans + (f[i]*a[l+i])%MOD)%MOD;
			}
			cout<<ans<<endl;
		}
		else {
			int l, r, d;
			cin>>l>>r>>d;
			l--; r--;
			forn(i, l, r+1) {
				a[i] += d;
			}
		}
	}	
	return 0;
}
