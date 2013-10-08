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

vector<long long> a;
int b[8];
int primeCount;


int findTree(int index, vector<int> tree) {
	if (index == a.size()) {
		int sum = 0;
		int num = 0;
		for(int i = 0; i < tree.size(); i++) {
			if (tree[i] == -1) {
				num++;
				sum += b[i];
			}
		}
		return (sum + (num>1) + (int)a.size() - primeCount);
	}

	int value = findTree(index+1, tree);

	for(int i = 0; i < index; i++) {
		long long prod = 1;
		for(int j = 0; j < index; j++) {
			if (tree[j] == i)
				prod = prod*a[j];
		}
		prod = prod*a[index];
		if (a[i]%prod == 0) {
			tree[index] = i;
			value = min(value, findTree(index+1, tree));
		}
	}
	return value;
}


int main()
{
	int n;
	cin>>n;

	primeCount = 0;
	a.resize(n);

	for(int i = 0; i < n; i++)
		cin>>a[i];

	sort(a.rbegin(), a.rend());

	for(int i = 0; i < n; i++) {
		long long x = a[i];
		b[i] = 0;
		for(int j = 2; j*1LL*j <= x; j++) {
			while(x%j == 0) {
				b[i]++;
				x /= j;
			}
		}

		if (x > 1)
			b[i]++;
		if (x == a[i])
			primeCount++;
	}

	vector<int> tree(n, -1);

	cout<<findTree(0, tree)<<endl;
}
