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

int dp[2013];
int next[2013];
string s;


int check(int i){
	int count = 0;
	if (i > s.length()-4)
		return 0;
	if (s[i] == '?' || s[i] == 'C')
		count++;
	if (s[i+1] == '?' || s[i+1] == 'H')
		count++;
	if (s[i+2] == '?' || s[i+2] == 'E')
		count++;
	if (s[i+3] == '?' || s[i+3] == 'F')
		count++;
	if (count == 4)
		return 1;
	else
		return 0;
}

int solve(int i){
	if (i >= s.length())
		return 0;
	if (dp[i] != -1){
		return dp[i];
	}
	int index = i+1;
	int maxValue = solve(i+1);
	
	int value = solve(i+2);
	if (value >= maxValue){
		maxValue = value;
		index = i+2;
	}
	
	value = solve(i+3);
	if (value >= maxValue){
		maxValue = value;
		index = i+3;
	}
	
	value = solve(i+4) + check(i);
	if (value > maxValue){
		maxValue = value;
		index = i+4;
	}
	
	dp[i] = maxValue;
	next[i] = index;
	return dp[i];
}

int main()
{
  int t;
  cin>>t;
  while(t--){
	  cin>>s;
	  memset(dp, -1, sizeof dp);
	  memset(next, -1, sizeof next);
	  solve(0);
	  int index = 0;
	  while(index < s.length()){
		  if (next[index] == index+4){
			  if (check(index) == 1){
				  s[index] = 'C';
				  s[index+1] = 'H';
				  s[index+2] = 'E';
				  s[index+3] = 'F';
			}
			else{
				for(int i = index; i<next[index] && i<s.length(); i++){
					if (s[i] == '?')
						s[i] = 'A';
				}
			}
		}
		else{
			for(int i=index; i<next[index] && i<s.length(); i++){
				if (s[i] == '?')
					s[i] = 'A';
			}
		}
		index = next[index];
	}
	cout<<s<<endl;
  }
  return 0;
}

