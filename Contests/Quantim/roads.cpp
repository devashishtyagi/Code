#include <cmath>
#include <limits>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
// the maximum number of vertices + 1
#define NN 1024
#define INT_MAX 1000000000

// adjacency matrix (fill this up)
int cap[NN][NN];

// cost per unit of flow matrix (fill this up)
int cost[NN][NN];

// flow network and adjacency list
int fnet[NN][NN], adj[NN][NN], deg[NN];

// Dijkstra's successor and depth
int par[NN], d[NN];        // par[source] = source;

// Labelling function
int pi[NN];

#define CLR(a, x) memset( a, x, sizeof( a ) )
#define Inf (INT_MAX/2)

// Dijkstra's using non-negative edge weights (cost + potential)
#define Pot(u,v) (d[u] + pi[u] - pi[v])
bool dijkstra( int n, int s, int t )
{
    for( int i = 0; i < n; i++ ) d[i] = Inf, par[i] = -1;
    d[s] = 0;
    par[s] = -n - 1;

    while( 1 ) 
    {
        // find u with smallest d[u]
        int u = -1, bestD = Inf;
        for( int i = 0; i < n; i++ ) if( par[i] < 0 && d[i] < bestD )
            bestD = d[u = i];
        if( bestD == Inf ) break;

        // relax edge (u,i) or (i,u) for all i;
        par[u] = -par[u] - 1;
        for( int i = 0; i < deg[u]; i++ )
        {
            // try undoing edge v->u      
            int v = adj[u][i];
            if( par[v] >= 0 ) continue;
            if( fnet[v][u] && d[v] > Pot(u,v) - cost[v][u] ) 
                d[v] = Pot( u, v ) - cost[v][u], par[v] = -u-1;
        
            // try edge u->v
            if( fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) + cost[u][v] ) 
                d[v] = Pot(u,v) + cost[u][v], par[v] = -u - 1;
        }
    }
  
    for( int i = 0; i < n; i++ ) if( pi[i] < Inf ) pi[i] += d[i];
  
    return par[t] >= 0;
}
#undef Pot

int mcmf3( int n, int s, int t, int &fcost )
{
    // build the adjacency list
    CLR( deg, 0 );
    for( int i = 0; i < n; i++ )
    for( int j = 0; j < n; j++ ) 
        if( cap[i][j] || cap[j][i] ) adj[i][deg[i]++] = j;
        
    CLR( fnet, 0 );
    CLR( pi, 0 );
    int flow = fcost = 0;
    
    // repeatedly, find a cheapest path from s to t
    while( dijkstra( n, s, t ) ) 
    {
        // get the bottleneck capacity
        int bot = INT_MAX;
        for( int v = t, u = par[v]; v != s; u = par[v = u] )
            bot = min(bot, fnet[v][u] ? fnet[v][u] : ( cap[u][v] - fnet[u][v] ));

        // update the flow network
        for( int v = t, u = par[v]; v != s; u = par[v = u] )
            if( fnet[v][u] ) { fnet[v][u] -= bot; fcost -= bot * cost[v][u]; }
            else { fnet[u][v] += bot; fcost += bot * cost[u][v]; }
    
        flow += bot;
    }
  
    return flow;
}

void AddEdge(int i, int j, int cp, int ct) {
  cost[i][j] = ct;
  cap[i][j] = cp;
}

int main(void) {
  int n;
  cin>>n;
  int repair[n][n];
  int maintain[n][n];

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

  int ans = -1;  
	for(int a = 0; a < n; a++) {
		for(int b = 0; b < n; b++) {
		  
      for(int i = 0; i < n; i++) {
        cost[0][i+1] = 0;
        cap[0][i+1] = 1;
      }

		    for(int i = 0; i < n; i++) {
		        if (i == a)
		          continue;
		        for(int j = 0; j < n; j++) {
		        	if (i == j)
		            	continue;
		            AddEdge(i+1, n+1+number[i][j], 1, repair[i][j]);
		        }
		    }

		    for(int i = 0; i < n; i++) {
		        if (i == b)
		          continue;
		        for(int j = 0; j < n; j++) {
		        	if (i == j)
		            	continue;
		            AddEdge(n+1+number[i][j], n+num+i+1, 1, maintain[i][j]);
		        }
		    }

        for(int i = 0; i < n; i++)
          AddEdge(n+num+i+1, n+num+n+1, 1, 0);

        int value;
        mcmf3(n+num+n+2, 0, n+num+n+1, value);

        if (ans == -1)
          ans = value;
        else
          ans = min(ans, value);
		}
  }

  cout<<ans<<endl;

  return 0;
}
