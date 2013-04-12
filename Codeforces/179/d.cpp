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
	int n;
	sf(n);
	long long cost[n][n], adj[n][n];
	int perm[n];
	for(int i = 0; i < n; i++)
		for(int j =0; j < n; j++)
			cin>>cost[i][j];
	
	for(int i = n-1; i >= 0; i--) {
		sf(perm[i]);
		perm[i]--;
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			adj[i][j] = cost[perm[i]][perm[j]];

	vector<long long> output;
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
		long long sum = 0;
		for(int i = 0; i <=k; i++) 
			for(int j = 0; j <=k; j++)
				sum += adj[i][j];
		output.push_back(sum);
	}

	for(int i = n-1; i >= 0; i--)
		cout<<output[i]<<" ";
	cout<<endl;
	
	return 0;
}
