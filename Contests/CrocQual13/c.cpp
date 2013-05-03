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
	int n,k;
	sf(n); sf(k);
	
	vector<long long> ips(n);

	for (int i = 0; i < n; ++i)
	{
		string ip;
		long long num = 0;
		vector<string> elems;
		cin>>ip;
		split(ip, '.', elems);
		for(int j = 0; j < 4; j++) {
			num = num*256 + convertString(elems[j]);
		}
		ips[i] = num;
	}

	map<long long, int> mymap;
	int subnet = -1;
	long long mask = (1LL<<31);
	for(int i = 1; i < 32; i++) {
		mymap.clear();
		for(int j = 0; j < n; j++) {
			long long network = mask & ips[j];
			mymap[network] = 1;
		}
		if (mymap.size() == k) {
			subnet = i;
			break;
		}
		mask = (mask>>1) + (1LL<<31);
	}

	if (subnet == -1) {
		pf(-1);
	}
	else{
		vector<int> ans;
		for(int i = 0; i < 4; i++) {
			ans.push_back(mask%256);
			mask = mask/256;
		}
		cout<<ans[3];
		for(int i = 2; i >= 0; i--)
			cout<<"."<<ans[i];
		cout<<endl;
	}
	return 0;
}
