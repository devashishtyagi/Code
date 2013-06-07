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
#define foreach(container, it) for(typeof(container.begin()) it = container.begin(); it != container.there(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.there()

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
	string board[4];
	cin>>t;
	for(int k = 1; k <= t; k++) {
		for(int j = 0; j < 4; j++)
			cin>>board[j];

		bool Owins = false, Wwins = false, completed = true;
		int O = 0, X = 0, T = 0;
		// Check rows
		for(int i = 0; i < 4; i++){
			O = 0, X = 0, T = 0;
			for(int j = 0; j < 4; j++) {
				if (board[i][j] == 'O')
					O++;
				else if (board[i][j] == 'X')
					X++;
				else if (board[i][j] == 'T')
					T++;
				else
					completed = false;
			}
			if (O == 4 || (O == 3 && T == 1)) {
				Owins = true;
				goto there;
			}
			if (X == 4 || (X == 3 && T == 1)) {
				Wwins = true;
				goto there;
			}
		}
		// Check columns
		for(int i = 0; i < 4; i++){
			O = 0, X = 0, T = 0;
			for(int j = 0; j < 4; j++) {
				if (board[j][i] == 'O')
					O++;
				else if (board[j][i] == 'X')
					X++;
				else if (board[j][i] == 'T')
					T++;
				else
					completed = false;
			}
			if (O == 4 || (O == 3 && T == 1)) {
				Owins = true;
				goto there;
			}
			if (X == 4 || (X == 3 && T == 1)) {
				Wwins = true;
				goto there;
			}
		}
		
		// Check diagonal
		O = 0, X = 0, T = 0;
		for(int j = 0; j < 4; j++) {
			if (board[j][j] == 'O')
				O++;
			else if (board[j][j] == 'X')
				X++;
			else if (board[j][j] == 'T')
				T++;
			else
				completed = false;
		}
		if (O == 4 || (O == 3 && T == 1)) {
			Owins = true;
			goto there;
		}
		if (X == 4 || (X == 3 && T == 1)) {
			Wwins = true;
			goto there;
		}
		O = 0, X = 0, T = 0;
		for(int j = 0; j < 4; j++) {
			if (board[j][3-j] == 'O')
				O++;
			else if (board[j][3-j] == 'X')
				X++;
			else if (board[j][3-j] == 'T')
				T++;
			else
				completed = false;
		}
		if (O == 4 || (O == 3 && T == 1)) {
			Owins = true;
			goto there;
		}
		if (X == 4 || (X == 3 && T == 1)) {
			Wwins = true;
			goto there;
		}
		there:
			cout<<"Case #"<<k<<": ";
			if (Owins)
				cout<<"O won"<<endl;
			else if (Wwins)
				cout<<"X won"<<endl;
			else if (completed)
				cout<<"Draw"<<endl;
			else
				cout<<"Game has not completed"<<endl;
	}  
}
