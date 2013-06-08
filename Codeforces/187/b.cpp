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
	int b, d;
	string a, c;
	cin>>b>>d;
	cin>>a>>c;

	vector<int> occ(a.size(), -1);
	vector<int> added(a.size(), -1);
	int i = 0, j = 0;
	int add = 1;
	int submatch = 0;
	int cycle = -1;
	int cyclelength = -1;
	int cyclebegin = -1;

	while(add <= 100 && add <= b) {
		if (a[i] != c[j]) {
			i++;
		}
		else {
			j++;
			if (j == c.size()) {
				submatch++;
				j = 0;
				if (occ[i] == -1) {
					occ[i] = submatch;
					added[i] = add;
				}
				else {
					cycle = submatch - occ[i] + 1;
					cyclelength = add - added[i] + 1;
					cyclebegin = i;
					break;
				}
			}
			i++;
		}
		if (i == a.size()){
			add++;
			i = 0;
		}
	}

	if(submatch == 0)
	{
		cout<<0<<endl;
		return 0;
	}

	if (cycle == -1) {
		cout<<submatch/d<<endl;		 
	}
	else {

		cout<<cyclebegin<<" "<<cycle<<" "<<cyclelength<<endl;

		int total_matches = 0;
		total_matches += submatch;
		int total = added[cyclebegin];
		while(total + cyclelength <= b) {
			total_matches += cycle;
			total += cyclelength;
		}
		if (cyclebegin != a.size()-1 || total != b) {
			i = (cyclebegin + 1)%a.size();
			j = 0;
			while(total <= b) {
				if (a[i] != c[j]) {
					i++;
				}
				else {
					j++;
					if (j == c.size()) {
						total_matches++;
						j = 0;
					}
					i++;
				}
				if (i == a.size()){ 
					i = 0;
					total++;
				}
			}
		}

		cout<<total_matches/d<<endl;
	}

	return 0;

}