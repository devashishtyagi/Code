using namespace std;
#include <cmath>
#include <cstdio>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
typedef long long ll; 
typedef pair<int,int> pii; 
#define FOR(i,n) for (int i = 0; i < n; i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define MP make_pair
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)

const int maxn = 105;
int totalCases, testNum;
int N, M;
char grid[maxn][1005];
int w[maxn][maxn];
int mr[maxn], mc[maxn];
int seen[maxn];

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

void input(){
  sf(N); sf(M);
  for(int i = 0; i < N; i++)
    scanf("%s",grid[i]);
} 

bool prime(int val)
{
  if(val == 1)return false;
  if(val%2 == 0) return false;
  for(int p = 3; p*p <= val; p++)
    if(val % p == 0)
      return false;
  return true;
}

void solve(){
  if (N%2 == 1){
    printf("YES\n");
    return;
  }
  memset(w, 0, sizeof w);
  for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
      int cnt = 0;
      for(int k = 0; k < M; k++)
        cnt += (grid[i][k] != grid[j][k])?1:0;
      if (prime(cnt)){
        w[i][j] = 1;
        w[j][i] = 1;
      }
    }
  }
  int value = BipartiteMatching();
  if (value == N)
    printf("NO\n");
  else
    printf("YES\n");
}

int main()
{
  sf(totalCases);
  for(testNum = 1; testNum <= totalCases; testNum++)
  {
    input();
    solve();
  }
}
