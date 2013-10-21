/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <functional>
#include <numeric>
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


// Compiler utility
#define int_msb(x) ((31) - __builtin_clz(x))

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
#define MOD 1000000009
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

map< string, set<char> > nextmoves;
vector<string> T;
string buffer;
int n;

void solve(int i, int j) {
	string str = buffer.substr(0, i+j);

	//out<<i<<" "<<j<<" "<<str<<endl;

	if (nextmoves.find(str) == nextmoves.end()) {
		nextmoves[str] = set<char>();
	}

	nextmoves[str].insert(T[i][j]);

	buffer[i+j] = T[i][j];
	if (i+1 < n)
		solve(i+1, j);
	if (j+1 < n)
		solve(i, j+1);
} 

int win(int moves, string& str) {
	if (moves == 2*n-1) {
		int c1 = count(str.begin(), str.end(), 'a');
		int c2 = count(str.begin(), str.end(), 'b');
		if (c1 == c2)
			return 0;
		else if (c1 > c2)
			return 1;
		else
			return -1;
	}

	int p = moves%2;
	int best = -1;
	if (p == 1)
		best = 1;

	string curr = str.substr(0, moves);
	for(set<char>::iterator it = nextmoves[curr].begin(); it != nextmoves[curr].end(); ++it) {
		str[moves] = *it;
		if (p == 0)
			best = max(best, win(moves+1, str));
		else 
			best = min(best, win(moves+1, str));
	}

	return best;
}

int main()
{
	cin>>n;
	
	buffer.resize(2*n-1);
	T.resize(n);

	for(int i = 0; i < n; i++)
		cin>>T[i];
		

	solve(0, 0);

	cout<<"Done"<<endl;

	string str(n, ' ');

	int result = win(0, str);

	if (result == 0)
		cout<<"DRAW"<<endl;
	else if (result == 1)
		cout<<"FIRST"<<endl;
	else
		cout<<"SECOND"<<endl;

	return 0;
}
