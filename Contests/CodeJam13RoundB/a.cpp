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

int findN(long long value, long long a) {
	int low = 1, high = 10000;
	int minn = high;
	while(low <= high) {
		int mid = (low + high)/2;
		long long sum = a*mid*1LL*(mid+1)/2;
		if (sum <= value) {
			low = mid+1;
		}
		else {
			minn = min(mid, minn);
			high = mid-1;
		}
	}
	return minn;
}

int main()
{
	int t;
	sf(t);
	for(int k = 1; k <= t; k++) {
		long long A;
		cin>>A;
		int n;
		cin>>n;
		vector<long long> sizes(n);
		for(int j = 0; j < n; j++)
			cin>>sizes[j];
		sort(sizes.begin(), sizes.end());
		int ops = 0;
		int minops = n;
		for(int i = 0; i < n; i++) {
			if (A > sizes[i]) {
				A += sizes[i];
				minops = min(ops + n-i-1, minops);
			}
			else {
				if (A > 1) {
					int addops = 0;
					while (A <= sizes[i]) {
						A += (A-1);
						addops++;
					}
					ops += addops;
					A += sizes[i];
				}
				else {
					ops += 1;
				}
				minops = min(ops+n-i-1, minops);
			}
		}
		cout<<"Case #"<<k<<": "<<minops<<endl;
	}
	return 0;
}
