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

int twoCount(int n) {
	int count = 0;
	while(n > 0) {
		if (n % 2 == 0) {
			count++;
			n /= 2;
		}
		else
			break;
	}
	return count;
}

int binpow(int a, int x, int m) {
	if (x == 0)
		return 1;
	else {
		int v = binpow(a, x/2, m);
		v = (LL)v*v%m;
		if (x % 2 == 1)
			v = (LL)v*a%m;
		return v;
	}
}

int main()
{
	int n, m;
	vector< pair<int,int> > points;
	cin>>n;
	FOR(i, 0, n) {
		int a;
		cin>>a;
		points.push_back(make_pair(a, i));
	}	
	FOR(i, 0, n) {
		int b;
		cin>>b;
		points.push_back(make_pair(b, i));
	}
	cin>>m;
	sort(all(points));
	LL ans = 1;
	int p = 1;
	int totalcounts = 0;
	int dupcounts = 0;
	FOR(i, 1, 2*n) {
		if (points[i] == points[i-1])
			dupcounts++;
		if (points[i].first == points[i-1].first) {
			p++;
			int x = twoCount(p);
			totalcounts += x;
			int rem = p/(1<<x);
			ans = ans*rem%m;
		}
		else {
			int v = binpow(2, totalcounts - dupcounts, m);
			ans = ans*v%m;
			p = 1;
			totalcounts = 0;
			dupcounts = 0;
		}
	}
	ans = ans*binpow(2, totalcounts-dupcounts, m)%m;
	cout<<ans<<endl;

	return 0;
}