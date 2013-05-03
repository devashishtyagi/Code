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
#define MOD 1000000007
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

int fact[1000001];
int invfact[1000001];

int binpow(int n, int r) {
	if (r == 0)
		return 1;
	else{
		int x = binpow(n, r/2);
		x = x*1LL*x%MOD;
		if (r&1)
			x = x*1LL*n%MOD;
		return x;
	}
}

void init() {
	fact[0] = 1;
	fact[1] = 1;
	for(int i = 2; i < 1000001; i++) {
		fact[i] = fact[i-1]*1LL*i%MOD;
	}
	invfact[1000000] = binpow(fact[1000000], MOD-2);
	for(int i = 1000000; i > 0; i--) {
		invfact[i-1] = invfact[i]*1LL*i%MOD;
	}
}

int nCr(int n, int r) {
	if (n == r)
		return 1;
	else if (n < r)
		return 0;
	int ans = fact[n]*1LL*invfact[r]%MOD;
	ans = ans*1LL*invfact[n-r]%MOD;
	return ans;
}

bool isgood(int n, int a, int b) {
	if (n == 0)
		return false;
	while(n > 0){
		int rem = n%10;
		if (rem != a && rem != b)
			return false;
		n = n/10;
	}
	return true;
}

int main()
{
	int a, b, n;
	int ans = 0;
	init();
	cin>>a>>b>>n;
	for(int i = 0; i <= n; i++) {
		int sum = i*a + (n-i)*b;
		if (isgood(sum, a, b)) {
			ans = ((long long)ans+nCr(n,i))%MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}
