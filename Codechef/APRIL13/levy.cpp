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

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

int pairs[10001];

void init() {
	bool prime[10001];
	vector<int> primelist;

	memset(prime, false, sizeof prime);
	memset(pairs, 0, sizeof pairs);

	for(int i = 2; i < 10001; i++) {
		if (!prime[i]) {
			primelist.push_back(i);
			int p = i;
			while(i*p < 10001) {
				prime[i*p] = true;
				p++;
			}
		}
	}
	for(int i = 0; i < primelist.size(); i++) {
		for(int j = 0; j < primelist.size(); j++) {
			int n = primelist[i] + 2*primelist[j];
			if (n < 10001)
				pairs[n]++;
		}
	}
}

int main()
{
	int t;
	init();
	sf(t);
	while(t--) {
		int n;
		sf(n);
		pf(pairs[n]);
	}
	return 0;
}
