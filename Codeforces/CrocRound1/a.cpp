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
	queue< pair<int,int> > Q1, Q2;
	int size = 0, t= 1;
	sf(n);
	
	for(int i = 0; i < n; i++) {
		int t,c;
		sf(t); sf(c);
		Q1.push(make_pair(t,c));
	}

	int maxsize = 0, prev_t = 1;
	while(!Q1.empty() || !Q2.empty()) {
		int next_t = -1;
		if (!Q2.empty()) {
			next_t = t + Q2.front().second;
		}
		if (!Q1.empty()) {
			if (next_t == -1) {
				next_t = Q1.front().first;
			}
			else {
				next_t = min(Q1.front().first, next_t);	
			}
		}
		if (!Q2.empty()) {
			Q2.front().second -= (next_t - t);
			size -= (next_t - t);
			if (Q2.front().second == 0)
				Q2.pop();
		}
		if (!Q1.empty()) {
			if (t == Q1.front().first) {
				Q2.push(Q1.front());
				size += Q1.front().second;
				Q1.pop();
			}
		}
		maxsize = max(size, maxsize);
		t = next_t;
	}

	cout<<t<<" "<<maxsize<<endl;

	return 0;
}

