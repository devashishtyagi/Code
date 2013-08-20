#include <cmath>
#include <limits>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;


typedef vector<int> VI;
typedef vector<VI> VVI;
typedef int L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) : 
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), 
    found(N), dist(N), pi(N), width(N), dad(N) {}
  
  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }
  
  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;
    
    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};



vector<int> parent;

void clear(int n) {
    parent.clear();
    parent.resize(n, -1);
}

int find(int v) {
    if (parent[v] == -1)
        return v;
    else
        return parent[v] = find(parent[v]);
}

void join(int v, int u) {
    int a = find(v);
    int b = find(u);
    if (a == b)
        return;
    else
        parent[a] = b;
}

int n;
int repair[31][31];
int maintain[31][31];

int calc(int v) {
    return 0;
}


int main(void) {
    
    cin>>n;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin>>repair[i][j];

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin>>maintain[i][j];

    int number[n][n];
    int num = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < i; j++)
        number[i][j] = number[j][i] = num++;

    int ans = (int)10E9;

    memset(dp, -1, sizeof dp);

    for(int v = 0; v < n; v++) {

        int amt = calc(v);

        MinCostMaxFlow mcmf(2+n+n+1);

        mcmf.AddEdge(0, 1, n-1, 0);

        for(int i = 0; i < n; i++) {
            if (v != i)
                mcmf.AddEdge(1, 2+i, 1, 0);
            else
                mcmf.AddEdge(1, 2+i, 0, 0);
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mcmf.AddEdge(2+i, 2+n+j, 1, maintain[i][j]);

        for(int i = 0; i < n; i++)
            mcmf.AddEdge(2+n+i, 2+n+n, 1, 0);

        amt += mcmf.GetMaxFlow(0, 2+n+n).second;
        ans = min(ans, amt);
    }

    cout<<ans<<endl;

    return 0;
}
