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

int a[200002], b[200002];
long long sum = 0;
int len = 1;
int chunk = (int)sqrt(200002) + 1;

void add(int l, int r, int x) {
	int c_l = l / chunk, c_r = r / chunk;
	if (c_l == c_r) {
		for(int i = l; i <= r; i++){
			a[i] += x;
		}
	}
	else {
		for (int i=l, end=(c_l+1)*chunk-1; i<=end; ++i)
			a[i] += x;
		for (int i=c_l+1; i<=c_r-1; ++i)
			b[i] += x;
		for (int i=c_r*chunk; i<=r; ++i)
			a[i] += x;
	}
}

void cleanup() {
	int c_l = (len-2)/chunk;
	int c_r = (len-1)/chunk;
	if (c_l != c_r)
		b[c_r] = 0;
	if (len%chunk == 0) {
		int index = (len-1) / chunk;
		for(int i = index*chunk; i < (index+1)*chunk; i++) {
			a[i] += b[index];
		}
		b[index] = 0;
	}
}

int main()
{
	int n;
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	cin>>n;
	while(n--) {
		int t;
		cin>>t;
		if (t == 1) {
			int a,x;
			cin>>a>>x;
			add(0,a-1,x);
			sum += a*1LL*x; 
			printf("%.8lf\n",(double)sum/(double)len);
		}
		else if (t == 2) {
			int k;
			cin>>k;
			a[len++] = k;
			sum += k;
			printf("%.8lf\n",(double)sum/(double)len);
		}
		else {
			int value = b[(len-1)/chunk];
			sum -= (value+a[len-1]);
			cleanup();
			len--;
			printf("%.8lf\n",(double)sum/(double)len);
		}
	}  
	return 0;
}