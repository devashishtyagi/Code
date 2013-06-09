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

int main()
{
	int n;
	cin>>n;
	int a[2*n-1];
	FOR(i, 0, 2*n-1)
		cin>>a[i];

	int dp[2*n-1][2*n];
	CLEAR(dp);

	dp[0][0] = a[0];
	dp[0][1] = -a[0];

	FOR(i, 1, 2*n-1) {
		FOR(j, 0, i+2) {
			if (j == 0) {
				dp[i][j] = dp[i-1][j] + a[i];
			}
			else if (j == i+1) {
				dp[i][j] = dp[i-1][j-1] - a[i];
			}
			else {
				dp[i][j] = max(dp[i-1][j] + a[i], dp[i-1][j-1] - a[i]);
			}
		}
	}

	int max_sum = dp[2*n-2][0];
	if (n%2 == 0) {
		for(int i = 0; i < 2*n-1; i += 2) {
			max_sum = max(max_sum, dp[2*n-2][i]);
		}
	}
	else {
		for(int i = 0; i <= 2*n-1; i++) {
			max_sum = max(max_sum, dp[2*n-2][i]);
		}
	}

	cout<<max_sum<<endl;

	return 0;

}