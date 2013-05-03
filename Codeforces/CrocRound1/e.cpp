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

int len;
int aux[100000];
bool valid[100000];
int a[100000];
int b[100000];

void update(int x, int y, int k) {
	int c_l = y/len, c_r = (y+k-1)/len;
	int l = y, r = y+k-1;
	if (c_l == c_r) {
		int v = aux[c_l];
		if (v != -1) {
			int start = (c_l)*len;
			for(int i = (c_l)*len; i <= (c_l+1)*len-1; i++) {
				b[i] = a[v+i-start];
			}
		}	
		aux[c_l] = -1;
		for(int i = l; i <= r; i++) {
			b[i] = a[x+i-l];
		}
	}
	else {
		
		// Set value of middle aux variable
		int v = x + (c_l+1)*len - l;
		for (int i=c_l+1; i<=c_r-1; ++i) {
			aux[i] = v;
			v += len;
		}

		// Update left corner
		v = aux[c_l];
		if (v != -1) {
			int start = (c_l)*len;
			for(int i = (c_l)*len; i <= (c_l+1)*len-1; i++) {
				b[i] = a[v+i-start];
			}
		}	
		aux[c_l] = -1;
		for(int i = l; i <= (c_l+1)*len-1; i++) {
			b[i] = a[x+i-l];
		}

		// Update right corner
		v = aux[c_r];
		if (v != -1) {
			int start = (c_r)*len;
			for(int i = (c_r)*len; i <= (c_r+1)*len-1; i++) {
				b[i] = a[v+i-start];
			}
		}	
		aux[c_r] = -1;
		for(int i = (c_r)*len; i <= r; i++) {
			b[i] = a[x + i - l];
		}
	}
}

int main()
{
	int n, m;
	sf(n); sf(m);
	len = (int)sqrt(n + .0) + 1;

	for(int i = 0; i < n; i++)
		sf(a[i]);
	for(int i = 0; i < n; i++)
		sf(b[i]);

	memset(aux, -1, sizeof aux);
	for(int i = 0; i < m; i++){
		int t;
		sf(t);
		if (t == 1) {
			int x,y,k;
			sf(x); sf(y); sf(k);
			update(x-1, y-1, k);
		}
		else{
			int x;
			sf(x);
			x--;
			int l = aux[x/len];
			if (l == -1) {
				pf(b[x]);
			}
			else {
				int diff = x - (x/len)*len;
				pf(a[diff+l]);
			}
		}
	}
}
