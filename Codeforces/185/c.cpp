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

#define INF 1E18
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

/* Number and cost of treasure cells */
LL a[100001];
int c[100001];

/* Minimum cell reachable in a group */
LL D[10001];

/* Priority queue storing max elements */
priority_queue< pair<int,int> >  Q;

/* Reachability elements */
vector<LL> elements;
bool taken[100001];
int groups[100001];
bool removed[100001];

void reconstruct(int n, int k) {
	priority_queue<LL> pq;
	pq.push(0);

	while(!pq.empty()) {
		LL v = pq.top();
		pq.pop();

		forn(i, 0, elements.size()) {
			LL to = -v + elements[i];
			int g = to%k;
			if (D[g] > to) {
				D[g] = to;
				pq.push(-to);
			}
		}
	}

	forn(i, 0, n) {
		if (D[groups[i]] != INF) {
			if (!taken[i] && D[groups[i]] <= a[i]) {
				taken[i] = true;
				Q.push(mp(c[i], -i));
			}
		}
	}
}


int main()
{
	LL h;
	int n, m, k;	
	CLEAR(taken);
	CLEAR(removed);

	cin>>h;
	cin>>n>>m>>k;

	forn(i, 0, n) {
		cin>>a[i]>>c[i];
		a[i]--;
	}

	D[0] = 0;
	forn(i, 1, k)
		D[i] = INF;

	forn(i, 0, n) {
		if (a[i]%k == 0) {
			Q.push(mp(c[i], -i));
			taken[i] = true;
		}
		groups[i] = a[i]%k;
	}

	while(m--) {
		int op;
		cin>>op;
		if(op == 1) {
			LL x;
			cin>>x;
			elements.pb(x);
			reconstruct(n, k);
		}
		else if (op == 2) {
			int x, cx;
			cin>>x>>cx;
			x--;
			c[x] -= cx;
			if (taken[x] && !removed[x] && cx > 0)
				Q.push(mp(c[x], -x));
		}
		else {
			int best_value = 0;
			while(!Q.empty() && c[-Q.top().second] != Q.top().first)
				Q.pop();

			if (!Q.empty()) {
				best_value = Q.top().first;
				removed[-Q.top().second] = true;
				Q.pop();
			}
			cout<<best_value<<endl;
		}
	}
}