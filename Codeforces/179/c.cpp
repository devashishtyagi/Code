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
	int n,m,k;
	sf(n); sf(m); sf(k);
	long long a[n];
	long long q[m][3];
	long long suma[n+1];
	long long sumq[m+1];
	CLEAR(suma); CLEAR(sumq);
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = 0; i < m; i++)
		cin>>q[i][0]>>q[i][1]>>q[i][2];
	for(int i = 0; i < k; i++) {
		int x, y;
		cin>>x>>y;
		sumq[x-1] += 1;
		sumq[y] -= 1;
	}
	suma[q[0][0]-1] += q[0][2]*sumq[0];
	suma[q[0][1]] -= q[0][2]*sumq[0];
	for(int i = 1; i < m; i++) {
		sumq[i] += sumq[i-1];
		suma[q[i][0]-1] += q[i][2]*sumq[i];
		suma[q[i][1]] -= q[i][2]*sumq[i];
	}
	a[0] += suma[0];
	cout<<a[0]<<" ";
	for(int i = 1; i < n; i++) {
		suma[i] += suma[i-1];
		a[i] += suma[i];
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
