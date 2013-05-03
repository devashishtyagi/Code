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

vector< vector<int> > graph;

int main()
{
	int n,m;
	sf(n); sf(m);
	vector<int> degree(n, 0);
	graph.resize(n);

	for(int i = 0; i < m; i++) {
		int x,y;
		sf(x); sf(y);
		x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}

	bool star = false, ring = false, line = false;
	// Check for star
	int degree1 = 0, degree2 = 0;
	for(int i = 0; i < n; i++) {
		if (degree[i] == 1)
			degree1++;
		else if (degree[i] == n-1)
			degree2++;
	}
	if (degree1 == n-1 && degree2 == 1) {
		star = true;
	}

	// Check for ring
	if (m == n && !star) {
		int degree2 = 0;
		for(int i = 0; i < n; i++) {
			if (degree[i] == 2)
				degree2++;
		}
		if (degree2 == n)
			ring = true;
	}

	// Check for line
	if (m == n-1 && !star && !ring) {
		int degree2 = 0, degree1 = 0;
		for(int i = 0; i < n; i++) {
			if (degree[i] == 2)
				degree2++;
			if (degree[i] == 1)
				degree1++;
		}
		if (degree2 == n-2 && degree1 == 2)
			line = true;
	}

	if (star) {
		cout<<"star topology"<<endl;
	}
	else if (ring) {
		cout<<"ring topology"<<endl;
	}
	else if (line) {
		cout<<"bus topology"<<endl;
	}
	else {
		cout<<"unknown topology"<<endl;
	}
	return 0;
}
