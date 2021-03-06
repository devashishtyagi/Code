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
typedef long long ll;

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

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

vector<int> primelist;

int sieve(){
	bool prime[351];
	CLEAR(prime);
	
	for(int i=2; i<351; i++){
		if (!prime[i]){
			prime[i] = true;
			primelist.push_back(i);
			int p = i;
			while(i*p < 351){
				prime[i*p] = true;
				p++;
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	vector<int> dp(100001,0);
	vector<int> a(n);
	vector<int> p;
	
	sieve();
	
	int ans = 0;
	FOR(i,0,n){
		cin>>a[i];
		p.clear();
		for(int j=0; j<primelist.size(); j++){
			if (a[i]%primelist[j] == 0){
				p.push_back(primelist[j]);
				while(a[i]%primelist[j] == 0)
					a[i] /= primelist[j];
			}
		}
		if (a[i] != 1)
			p.push_back(a[i]);
		int t = 0;
		for(int j=0; j<p.size(); j++){
			t = max(t, dp[p[j]]);
		}
		t++;
		ans = max(ans, t);
		for(int j=0; j<p.size(); j++){
			dp[p[j]] = t;
		}
	}
	cout<<ans<<endl;
	return 0;
}
