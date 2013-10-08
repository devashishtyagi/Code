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


int calc(int n, int k) {
	n = n-2;
	int m = k-2;

	return n*(n-1)/2 + 2*n -m;
}

int main()
{
	int n, m, k;
	cin>>n>>m>>k;

	vector<int> perm(k);

	for(int i = 0; i < k; i++) {
		cin>>perm[i];
		perm[i]--;
	}

	if (m <= calc(n, k) && k < n){
		int matrix[n][n];
		memset(matrix, 0, sizeof matrix);

		int edges = 0;
		int N = n-2;
		int K = k-2;

		for(int i = 0; i < N-1; i++) { 
			matrix[i][i+1] = 1;
		}
		edges += N-1;
		int v = 0;
		int u = 2;
		while(edges < m-2 && edges < N*(N-1)/2) {
			if (u >= N) {
				v++;
				u = v+2;
			}
			matrix[v][u] = 1;
			u++;
			edges++;
		}

		for(int i = K; i < N && edges < m; i++) {
			matrix[i][N] = 1;
			edges++;
			if (edges < m) {
				matrix[i][N+1] = 1;
				edges++;
			}
		}

		for(int i = 0; i < K && edges < m; i++) {
			matrix[i][N] = 1;
			edges++;
		}

		int mapping[n];
		vector<bool> taken(n ,false);

		for(int i = 0; i < K; i++) {
			mapping[i] = perm[i];
			taken[perm[i]] = true;
		}
		mapping[N] = perm[K];
		mapping[N+1] = perm[K+1];
		taken[perm[K]] = true;
		taken[perm[K+1]] = true;

		for(int i = K; i < N; i++) {
			for(int j = 0; j < n; j++) {
				if (!taken[j]) {
					taken[j] = true;
					mapping[i] = j;
					break;
				}
			}
		} 

		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				if (matrix[i][j] == 1) {
					cout<<mapping[i]+1<<" "<<mapping[j]+1<<endl;
				}
			}
		}

	}
	else {
		cout<<-1<<endl;
	}

	return 0;
}
