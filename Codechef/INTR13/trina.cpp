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

int main(){
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		vector<string> grid(m);
		for(int i=0; i<m; i++)
			cin>>grid[i];

		bool visited[m][n];
		queue< pair<int,int> > Q;
		string ans;
		for(int a='0'; a<='9'; a++){
			for(int b=a; b<='9'; b++){
				for(int c=b; c<='9'; c++){
					
					memset(visited, false, sizeof visited);
					for(int i=0; i<n; i++){
						if (grid[0][i] == a || grid[0][i] == b || grid[0][i] == c){
							Q.push(make_pair(0,i));
							visited[0][i] = true;
						}
					}
					bool reached = false;
					while(!Q.empty()){
						int i = Q.front().first;
						int j = Q.front().second;
						Q.pop();
						if (i == m-1){
							reached = true;
							break;
						}
						// DOWN
						if (i+1 < m && !visited[i+1][j] && (grid[i+1][j] == a || grid[i+1][j] == b || grid[i+1][j] == c)){
							Q.push(make_pair(i+1,j));
							visited[i+1][j] = true;
						}
						// UP
						if (i-1 >= 0 && !visited[i-1][j] && (grid[i-1][j] == a || grid[i-1][j] == b || grid[i-1][j] == c)){
							Q.push(make_pair(i-1,j));
							visited[i-1][j] = true;
						}
						// LEFT
						if (j-1 >= 0 && !visited[i][j-1] && (grid[i][j-1] == a || grid[i][j-1] == b || grid[i][j-1] == c)){
							Q.push(make_pair(i,j-1));
							visited[i][j-1] = true;
						}
						// RIGHT
						if (j+1 < n && !visited[i][j+1] && (grid[i][j+1] == a || grid[i][j+1] == b || grid[i][j+1] == c)){
							Q.push(make_pair(i,j+1));
							visited[i][j+1] = true;
						}
					}
					if (reached){
						ans.push_back(a); ans.push_back(b); ans.push_back(c);
						goto END;
					}
				}
			}
		}
		END: 
		if (ans.size() == 0)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
