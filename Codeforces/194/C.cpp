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

int cnt = 0, m, k;
char s[9];
vector<string> cstr(10001);

string toString(int i) {
	stringstream ss;
	ss<<i;
	return ss.str();
}

void fillRest(int index) {
	if (index == 8) {
		printf("%s\n", s);
		cnt++;
		return;
	}
	for(int i= 0; i < 10; i++) {
		s[index] = i+'0';
		fillRest(index+1);
		if(cnt == m)
			return;
	}
}

void findAll(int num, int done, int index) {
	if (index == 8) {
		if (num == 1) {
			printf("%s\n", s);
			cnt++;
		}
		return;
	}
	for(int i = 1; i*i <= num; i++) {
		if (num%i == 0) {
			int other = num/i;
			if (8-index >= cstr[i].size()) {
				for(int j = 0; j < cstr[i].size(); j++)
					s[index+j] = cstr[i][j];
				findAll(other, ((done == 0)?i:done*i), index+cstr[i].size());
			}
			if (cnt == m)
				return;
			if (other != i && 8-index >= cstr[other].size()) {
				for(int j = 0; j < cstr[other].size(); j++)
					s[index+j] = cstr[other][j];
				findAll(i, ((done == 0)?i:done*other), index+cstr[other].size());				
			}
			if (cnt == m)
				return;
		}
	}
	if (cnt == m)
		return;

	if (done == k) {
		s[index] = '0';
		fillRest(index+1);
	}
}

int main()
{
	scanf("%d %d", &k, &m);
	s[8] = '\0';

	for(int i = 0; i < 10001; i++) {
		cstr[i] = toString(i);
	}

	
	findAll(k, 0, 0);
	

	return 0;
}
