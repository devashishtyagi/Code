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
#define MOD 1000000007
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

int a[305], next[305], b[305], visited[305];

void dfs(int i) {
	if (b[i] > 0)
		return;
	if (next[i] == -1) {
		b[i] = a[i];
	}
	else {
		dfs(next[i]);
		b[i] = a[i] + b[next[i]];
	}
}

bool check(int i) {
	if (next[i] == -1 || visited[i] == 2)
		return false;
	else if (visited[i] == 1)
		return true;
	else{
		visited[i] = 1;
		bool value = check(next[i]);
		visited[i] = 2;
		return value;
	}
}

int main(){
	int n,q;
	long long t;
	cin>>n>>q>>t;
	FOR(i, 0, n)
		cin>>a[i];
	memset(next, -1, sizeof next);
	memset(b, 0, sizeof b);
	memset(visited, 0, sizeof visited);
	FOR(i, 0, q) {
		int a,b;
		cin>>a>>b;
		a--; b--;
		next[b] = a;
	}
	for(int i = 0; i < n; i++) {
		if (check(i)){
			cout<<0<<endl;
			return 0;
		}
	}

	for(int i = 0; i < n; i++)
		dfs(i);
	
	for(int i = 0; i < n; i++)
		t = t - (b[i] - a[i]);

	if (t  < 0) {
		cout<<0<<endl;
	}
	else{
		int sum[100001];
		CLEAR(sum);
		sum[0] = 1;
		for(int i = 0; i < n; i++) {
			for(int j = b[i]; j <= t; j++) {
				sum[j] = (sum[j] + sum[j-b[i]])%MOD;
			}
		}
		cout<<sum[t]<<endl;
	}
	return 0;
} 

