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

struct Point {
	LL m, b;
	Point(LL x, LL y) {
		m = x;
		b = y;
	} 
};

vector<struct Point> optimal;
int ptr;

void add(Point p) {
	if (optimal.size() < 2) {
		optimal.push_back(p);
	}
	else {
		int index = optimal.size() - 2;
		Point p1 = optimal.at(index);
		Point p2 = optimal.at(index+1);
		double x1 = (double)(p.b - p1.b)/(double)(p1.m - p.m);
		double x2 = (double)(p.b - p2.b)/(double)(p2.m - p.m);
		if (x2 >= x1) {
			optimal.pop_back();
			if (ptr > 0)
				ptr--;
			add(p);
		}
		else {
			optimal.push_back(p);
		}
	}
}

void exchg() {
	ptr = 0;
	optimal.clear();
}

Point find(LL j) {
	while(ptr < optimal.size() - 1  &&  (j*optimal[ptr].m + optimal[ptr].b) <= (j*optimal[ptr+1].m + optimal[ptr+1].b)){
		ptr++;
	}
	return optimal[ptr];
}

int main()
{
	int n, m, p;
	cin>>n>>m>>p;

	LL D[n];
	D[0] = 0;
	FOR(i, 0, n-1) {
		cin>>D[i+1];
		D[i+1] += D[i];
	}

	vector<LL> times;
	LL total = 0;
	FOR(i, 0, m) {
		int s,t;
		cin>>s>>t;
		times.push_back(t - D[s-1]);
		total += (t - D[s-1]);
	}

	sort(times.begin(), times.end());

	LL dp[p][m];

	FOR(i, 0, m) {
		dp[0][i] = (i+1)*times[i];
	}


	FOR(i, 1, p) {
		exchg();

		add(Point(1, 0));

		FOR(j, 0, m) {
			add(Point(-j, dp[i-1][j]));
			Point p = find(times[j]); 
			dp[i][j] = times[j]*p.m + p.b + j*times[j];
			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;	
		}
	}

	LL ans = dp[p-1][m-1];
	
	cout<<ans-total<<endl;

	return 0;
}