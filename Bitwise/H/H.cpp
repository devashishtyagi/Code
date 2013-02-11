#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstdio>
#include <cstring>

#define FOR(i,n) for (int i = 0; i < n; i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define MP make_pair
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
#define INF 2000000000

using namespace std;

const int maxn = 105;
int w[maxn][maxn];
int mr[maxn], mc[maxn];
int seen[maxn];
int N;

bool FindMatch(int i) {
  for (int j = 0; j < N; j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j])) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching() {
	memset(mr, -1, sizeof mr);
	memset(mc, -1, sizeof mc);
  
	int ct = 0;
	for (int i = 0; i < N; i++) {
		memset(seen, 0, sizeof seen);
		if (FindMatch(i)) ct++;
	}
	return ct;
}

void transitiveClosure(){
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				w[i][j] |= w[i][k] & w[k][j];
}

int main(){
  int t;
  sf(t);
  while(t--){
    sf(N);
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
	sf(w[i][j]);
    transitiveClosure();

    int maxFlow = BipartiteMatching();

    pf(N-maxFlow);
  }
  return 0;
}