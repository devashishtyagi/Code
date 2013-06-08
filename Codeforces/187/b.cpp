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

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define clear(a) memset((a),0,sizeof(a))

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
	int p1, p2;
	cin>>p1>>p2;
	string s1, s2;
	cin>>s1>>s2;

	int l1 = s1.size();
	int l2 = s2.size();

	int i = 0, j = 0;
	int added = 1, matches = 0;
	vector<int> match(l1, -1);
	vector<int> adds(l1, -1);

	bool found = false;

	while(added <= p1) {
		if (s1[i] != s2[j]) {
			i = (i+1)%l1;
		}
		else {
			j = (j+1)%l2;
			if (j == 0) {
				matches++;
				if (match[i] == -1) {
					match[i] = matches + 1;
					adds[i] = added;
				}
				else if (!found) {
					int period = matches - match[i] + 1;
					int inbetween = added - adds[i] + 1;
					int to_add = (p1-added)/inbetween;
					added += to_add;
					matches += to_add*period;
					found = true;
					cout<<period<<" "<<i<<" "<<inbetween<<endl;
				}
			}
			i = (i+1)%l1;
		}
		if (i == 0)
			added++;
	}

	//cout<<matches<<endl;

	cout<<matches/p2<<endl;

	return 0;
}

