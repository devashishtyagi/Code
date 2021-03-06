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
#define CLEAR(a) memset((a),-1,sizeof(a))

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

vector<int> graph[100000];
int level[100000];
int prev[100000];
int next[100000];

void dfs(int i, int p){
	if (p == -1){
		level[i] = 0;
		prev[i] = -1;
	}
	else{
		level[i] = level[p]+1;
		prev[i] = p;
	}
	for(int j=0; j<graph[i].size(); j++){
		int to = graph[i][j];
		if (level[to] >= 0){			
			if (next[i] == -1)
				next[i] = to;
			else if (level[next[i]] > level[to])
				next[i] = to;
		}
		else{
			dfs(to, i);
		}
	}
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	CLEAR(level);
	CLEAR(prev);
	CLEAR(next);
	FOR(i,0,m){
		int a,b;
		cin>>a>>b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	for(int i=0; i<n; i++){
		if (level[i] == -1){
			dfs(i,-1);
		}
	}
	int start = -1, end = -1;
	for(int i=0; i<n; i++){
		//cout<<i<<" "<<prev[i]<<" "<<next[i]<<" "<<level[i]<<endl;
		if (next[i] >= 0){
			if (level[i] - level[next[i]] >= k){
				start = i;
				end = next[i];
				break;
			}
		}
	}
	cout<<level[start]-level[end]+1<<endl;
	while(start != end){
		cout<<start+1<<" ";
		start = prev[start];
	}
	cout<<end+1<<endl;
	return 0;
}
