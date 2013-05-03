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
typedef long long ll;

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

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

int main()
{
	int t;
	cin>>t;
	for(int k = 1; k <= t; k++) {
		int n,m;
		cin>>n>>m;
		int a[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin>>a[i][j];
		int mrow[n], mcol[m];
		CLEAR(mrow); CLEAR(mcol);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				mrow[i] = max(mrow[i], a[i][j]);
				mcol[j] = max(mcol[j], a[i][j]);
			}
		}
		bool possible = true;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++){
				if (a[i][j] != mrow[i] && a[i][j] != mcol[j])
					possible = false;
			}
		}
		cout<<"Case #"<<k<<": ";
		if (possible){
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
