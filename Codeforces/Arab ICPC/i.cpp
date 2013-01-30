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
	int n,m;
	cin>>n>>m;
	
	vector<int> teamcount(100,0);
	int grid[n+2][m+2];
	memset(grid, 0, sizeof grid);
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>grid[i][j];
		
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=-1; k<=1; k++){
				for(int l=-1; l<=1; l++){
					if (k == 0 && l == 0)
						continue;
					if (grid[i+k][j+l] == grid[i][j] && grid[i][j] != -1)
						teamcount[grid[i][j]-1]++;
				}
			}
		}
	}
	
	int ans = 0;
	for(int i=0; i<100; i++){
		if (teamcount[i] > 0)
			ans++;
	}
	
	cout<<ans<<endl;
}
