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
#define s(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)

int totalCases, testNum;

int rowtot[1005];
int N, M;

int adjmat[105][105];

void input()
{
  string x;
  s(N);
  s(M);
  for(int i = 0; i < N; i++)
  {
    cin >> x;
    rowtot[i] = 0;
    for(int j = 0; j < M; j++)
      rowtot[i] += x[j] - '0';
  }
}

bool prime(int val)
{
  if(val == 1)return false;
  for(int p = 3; p*p <= val; p++)
    if(val % p == 0)
      return false;
  return true;
}

int matchL[105];
int matchR[105];
bool visit[105];

bool bpm(int u)
{
  if(visit[u])
    return false;
  visit[u] = true;
  for(int v = 0; v < N; v++)
  {
    if(adjmat[u][v])
    {
      if(matchR[v] == -1 || bpm(matchR[v]))
      {
	matchR[v] = u;
	matchL[u] = v;
	return true;
      }
    }
  }
  return false;
}

void solve()
{
  memset(adjmat, 0, sizeof adjmat);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    {
      if(abs(rowtot[i] - rowtot[j]) % 2 == 0)
	continue;
      if(prime(abs(rowtot[i] - rowtot[j])))
	adjmat[i][j] = 1;
    }
  
  if(N % 2 == 1)
  {
    printf("YES\n");
    return;
  }
    
  memset(matchL, -1, sizeof matchL);
  memset(matchR, -1, sizeof matchR);
  int ans = 0;
  for(int i = 0; i < N; i++)
  {
    if(rowtot[i] % 2 == 0 && matchL[i] == -1)
    {
      memset(visit, false, sizeof visit);
      if(bpm(i))
	ans++;
    }
  }
  
  if(ans == N/2)
    printf("NO\n");
  else
    printf("YES\n");
}

int main()
{
  s(totalCases);
  for(testNum = 1; testNum <= totalCases; testNum++)
  {
    input();
    solve();
  }
}
