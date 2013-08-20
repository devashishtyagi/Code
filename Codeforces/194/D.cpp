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

int n, m;
int a[1000][1000];
int b[1000][50];

int countOnes(int v) {
	if (v == 0)
		return 0;
	else if (v & (v-1))
		return 2;
	else
		return 1;
}

bool check(int x) {
	int width = (m+30)/31;

	for(int i = 0; i < n; i++) {
		int index = 0;
		for(int j = 0; j < m; j += 31) {
			b[i][index] = 0;
			for(int k = 0; k < 31; k++) {
				if (j+k < m)
					b[i][index] += ((a[i][j+k] >= x)<<k);
			}
			index++;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			int value = 0;
			for(int k = 0; k < width; k++) {
				value += countOnes(b[i][k] & b[j][k]);
				if (value >= 2) {
					return true;
				}
			}
		}
	}

	return false;
}


int main()
{
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);


	int low = 0, high = 1000000001;
	while(high - low > 1) {
		int mid = (low+high)>>1;
		if (check(mid)) {
			low = mid;
		}
		else {
			high = mid;
		}
	}

	printf("%d\n", low);

	return 0;
}
