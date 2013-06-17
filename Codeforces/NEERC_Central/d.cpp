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

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define init0(a) memset((a),0,sizeof(a))

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

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
	    elems.push_back(item);
	}
}

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

int main()
{

	ifstream fin;
	ofstream fout;
	fin.open("Input.txt");
	fout.open("Output.txt");

	int n;
	fin>>n;
	string str;
	fin>>str;

	int q[n+1];
	q[n] = 0;
	int count = 0;

	for(int i = n-1; i >= 0; i--) {
		q[i] = q[i+1] + ((str[i] == '*') ? 1 : 0);
		if (str[i] == '*')
			count++;
	}

	for(int i = 0; i < n+1; i++)
		q[i] = 2*q[i] + i;

	int max_op = 0;
	int l = 0, r = 0;
	int max_l = 0;

	for(int i = 1; i < n+1; i++) {
		if (q[i] - q[max_l] < max_op) {
			max_op = q[i] - q[max_l];
			l = max_l;
			r = i;
		}
		if (q[i] > q[max_l])
			max_l = i;
	}

	if (max_op + count + 2 >= count) {
		fout<<count<<endl;
		bool first = true;
		for(int i = 0; i < n; i++){
			if (str[i] == '*') {
				if (!first)
					fout<<"Ctrl+"<<i+1<<endl;
				else {
					fout<<i+1<<endl;
					first = false;
				}
			}
		}
	}
	else {
		fout<<max_op+count+2<<endl;
		fout<<l+1<<endl;
		fout<<"Shift+"<<r<<endl;
		for(int i = 0; i < l; i++) 
			if (str[i] == '*')
				fout<<"Ctrl+"<<i+1<<endl;
		for(int i = r; i < n; i++)
			if (str[i] == '*')
				fout<<"Ctrl+"<<i+1<<endl;
		for(int i = l; i < r; i++)
			if (str[i] != '*')
				fout<<"Ctrl+"<<i+1<<endl;
	}

	return 0;
}
