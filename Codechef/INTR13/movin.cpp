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

int n[9][4];
n[1][0] =  7; n[1][1] =  2; n[1][2] = 6; n[1][3] =  3;
n[2][0] =  8; n[2][1] =  3; n[2][2] = 5; n[2][3] =  1;
n[3][0] =  9; n[3][1] =  1; n[3][2] = 4; n[3][3] =  2;
n[4][0] =  3; n[4][1] =  6; n[4][2] = 9; n[4][3] =  5;
n[5][0] =  2; n[5][1] =  4; n[5][2] = 8; n[5][3] =  6;
n[6][0] =  1; n[6][1] =  5; n[6][2] = 7; n[6][3] =  4;
n[7][0] =  6; n[7][1] =  8; n[7][2] = 1; n[7][3] =  9;
n[8][0] =  5; n[8][1] =  9; n[8][2] = 2; n[8][3] =  7;
n[9][0] =  4; n[9][1] =  7; n[9][2] = 3; n[9][3] =  8;

int main()
{

}
