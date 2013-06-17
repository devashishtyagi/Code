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
#define init0(a) memset((a),0,sizeof(a))

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
	string s;
	cin>>s;

	int n;
	cin>>n;
	vector<string> p(n);
	vector<int> l(n);
	vector<int> r(n);

	forn(i, 0, n){
		cin>>p[i]>>l[i]>>r[i];
	}	

	int count = 0;
	map<string, bool> mymap;
	forn(i, 0, s.size()) {
		forn(j, i, s.size()) {
			string sub = s.substr(i, j-i+1);
			//cout<<sub<<endl;
			if (mymap.find(sub) == mymap.end()) {
				mymap[sub] = true;
				bool satisfied = true;
				forn(k, 0, n) {
					int occ = 0;
					forn(x, 0, (int)p[k].size()-(int)sub.size() + 1) {
						//cout<<"I am here"<<endl;
						bool found = true;
						forn(y, 0, sub.size()) {
							if (sub[y] != p[k][x+y]){
								found = false;
								break;
							}
						}
						if (found)
							occ++;
					}
					//cout<<p[k]<<" "<<occ<<endl;
					if (!(occ >= l[k] && occ <= r[k])){
						satisfied = false;
						break;
					}
				}
				if (satisfied)
					count++;
			}
		}
	}

	cout<<count<<endl;

	return 0;
}
