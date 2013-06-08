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

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
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
	int n, k;
	cin>>n>>k;
	LL a[n];
	forn(i, 0, n)
		cin>>a[i];

	LL sum = 0;
	LL d[n];
	d[0] = 0;
	forn(i, 1, n) {
		d[i] = sum + a[i-1]*(i-1) - i*a[i]*(n-i-1);
		sum += a[i-1]*(i-1);
		//cout<<"original "<<i<<" "<<d[i]<<endl;
	}	

	LL change = 0;
	int removed = 0;
	forn(i, 0, n) {
		//cout<<i<<" "<<d[i] + change + (n-i-1)*a[i]*removed<<endl;
		if (d[i] + change + (n-i-1)*a[i]*removed < k) {
			change -= i*a[i];
			cout<<i+1<<endl;
			removed++;
		}
		else {
			change -= removed*a[i];
		}
	}

	return 0;
}