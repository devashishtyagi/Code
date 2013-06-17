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
	int n, k;
	cin>>n>>k;

	vector<LL> sides(n);
	vector<int> index(n);

	forn(i, 0, n)
		cin>>sides[i];

	set< pair<int,int> > sideSet;
	forn(i, 0, n)
		sideSet.insert(make_pair(sides[i], i+1));

	int z = 0;
	foreach(sideSet, it) {
		sides[z] = it->first;
		index[z] = it->second;
		z++;
	}

	LL sum[n+1];
	sum[0] = 0;
	forn(i, 0, n)
		sum[i+1] = sum[i] + sides[i];

	int min_index = n, max_index = -1;

	forn(i, k-1, n) {
		if (sum[i] - sum[i-k+1] > sides[i]){
			min_index = min(min_index, i);
			max_index = max(max_index, i);
		}
	}

	if (max_index - min_index >= k) {
		cout<<"Yes"<<endl;
		forn(i, min_index-k+1, min_index+1)
			cout<<index[i]<<" ";
		forn(i, max_index-k+1, max_index+1)
			cout<<index[i]<<" ";
		cout<<endl;
		return 0; 
	}


	vector<int> perm(2*k);
	forn(i, 0, n-2*k+1) {
		forn(j, 0, k)
			perm[j] = 0;
		forn(j, k, 2*k)
			perm[j] = 1;

		do {
			LL secondLast, firstLast;
			LL secondSum = 0, firstSum = 0;
			forn(j, 0, 2*k) {
				if (perm[j] == 0) {
					firstSum += sides[i+j];
					firstLast = sides[i+j];
				}
				else {
					secondSum += sides[i+j];
					secondLast = sides[i+j];
				}
			}
			if ((secondSum - 2*secondLast > 0) && (firstSum - 2*firstLast > 0)) {
				cout<<"Yes"<<endl;
				forn(j, 0, 2*k)
					if (perm[j] == 0)
						cout<<index[i+j]<<" ";
				forn(j, 0, 2*k)
					if (perm[j] == 1)
						cout<<index[i+j]<<" ";
				cout<<endl; 
				return 0;
			}
		}while(next_permutation(perm.begin(), perm.end()));
	}

	cout<<"No"<<endl;

	return 0;
}
