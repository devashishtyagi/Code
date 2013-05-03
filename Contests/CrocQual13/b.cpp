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
typedef long long LL;

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

string str;
vector<string> lexemes;

int extract(int i) {
	while(i < str.size() && isspace(str[i]))
		i++;
	if (i >= str.size())
		return i;
	char end = ' ';
	if (str[i] == '"'){
		end = '"';
		i++;
	}
	string lexeme;
	while(i < str.size() && str[i] != end) {
		lexeme.push_back(str[i]);
		i++;
	}
	lexemes.push_back(lexeme);
	i++;
	return i;
}

int main()
{
	getline(cin, str);
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

	int index = 0;
	while(index < str.size()) {
		index = extract(index);
	}

	for (int i = 0; i < lexemes.size(); ++i)
	{
		/* code */
		cout<<"<"<<lexemes[i]<<">\n";
	}

	return 0;
}
