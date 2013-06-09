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

LL a[100001];
LL b[100001];
LL c[100001];
int len;

LL minheight(int l, int r) {
	int c_l = l/len, c_r = r/len;
	LL maxheight = -1;
	if (c_l == c_r) {
		for(int i = l; i <= r; i++) {
			if (b[c_l] == -1)
				maxheight = max(maxheight, a[i]);
			else
				maxheight = max(maxheight, b[c_l]);
		}
	}
	else{
		for(int i = l; i <= (c_l+1)*len-1; i++) {
			if (b[c_l] == -1)
				maxheight = max(maxheight, a[i]);
			else
				maxheight = max(maxheight, b[c_l]);
		}
		for(int i = c_l+1; i <= c_r-1; i++) {
			maxheight = max(maxheight, c[i]);
		}
		for(int i = c_r*len; i <= r; i++) {
			if (b[c_r] == -1)
				maxheight = max(maxheight, a[i]);
			else
				maxheight = max(maxheight, b[c_r]);
		}
	}
	return maxheight;
}

void update(int l, int r, LL h) {
	int c_l = l/len, c_r = r/len;
	if (c_l == c_r) {
		for(int i = c_l*len; i <= (c_l+1)*len-1; i++) {
			if (b[c_l] != -1) {
				a[i] = b[c_l];
			}
		}
		b[c_l] = -1;
		for(int i = l; i <= r; i++){
			a[i] = h;
			c[c_l] = max(c[c_l], a[i]);
		}
	}
	else{
		for(int i = c_l*len; i <= (c_l+1)*len-1; i++) {
			if (b[c_l] != -1) {
				a[i] = b[c_l];
			}
		}
		b[c_l] = -1;
		for(int i = l; i <= (c_l+1)*len-1; i++){
			a[i] = h;
			c[c_l] = max(c[c_l], a[i]);
		}
		for(int i = c_l+1; i <= c_r-1; i++) {
			b[i] = h;
			c[i] = max(c[i], b[i]);
		}
		for(int i = c_r*len; i <= (c_r+1)*len-1; i++) {
			if (b[c_r] != -1) {
				a[i] = b[c_r];
			}
		}
		b[c_r] = -1;
		for(int i = c_r*len; i <= r; i++){
			a[i] = h;
			c[c_r] = max(c[c_r], a[i]);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	len = sqrt(n+.0) + 1;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	memset(b, -1, sizeof b);
	for(int i = 0; i < n; i++)
		c[i/len] = max(c[i/len], a[i]);
	int q;
	cin>>q;
	FOR(i, 0, q) {
		int w, h;
		cin>>w>>h;
		LL base = minheight(0, w-1);
		LL newheight = base + h;
		update(0, w-1, newheight);
		cout<<base<<endl;
	}
	return 0;
}	