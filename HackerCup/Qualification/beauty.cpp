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

int getCode(char c){
	if (c <= 'Z')
		return c-'A';
	else
		return c-'a';
}

int main()
{
	int n;
	char extra;
	string str;
	cin>>n;
	extra = getchar();
	for(int i=0; i<n; i++){
		vector<int> alphacount(26,0);
		getline(cin, str, '\n');
		for(int j=0; j<str.size(); j++){
			if (('A' <= str[j] && str[j] <= 'Z') || ('a' <= str[j] && str[j] <= 'z'))
				alphacount[getCode(str[j])]++;
		}
		sort(alphacount.rbegin(), alphacount.rend());
		int value = 0;
		for(int j=0; j<26; j++){
			value += (26-j)*alphacount[j];
		}
		cout<<"Case #"<<i+1<<": "<<value<<endl;
	}
	return 0;
}
