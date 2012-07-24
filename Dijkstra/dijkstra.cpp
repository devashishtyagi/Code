/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <list>

#define s(a) scanf("%d",&a)
#define ss(a,b) scanf("%d %d",&a,&b)
#define p(a) printf("%d\n",a)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>

#define INF 100000000

using namespace std;
typedef long long int LL;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int minVertex(vector<int> & dist, set<int> & nvisited){
    int minValue = *(nvisited.begin());
    for(set<int>::iterator it=nvisited.begin(); it!=nvisited.end(); it++){
        if (dist[*it] < dist[minValue])
            minValue = *it;
    }
    nvisited.erase(minValue);
    return minValue;
}

// Implementation of Dijkstra's algorthm.
// Time Completxity O(|V|^2)
// Space Completxity O(|V|^2)
// Starting vertex is considered to be 1 and destination vertex is N

int main(void){
    int N,M;       // Number of vertices and number of edges
    ss(N,M);  
    vector< pi > graph[N+1];
    vector<int> distance(N+1);
    vector<int> previous(N+1);
    set<int> notvisited;

    for(int i=0; i<M; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    for(int i=1; i<=N; i++){
        distance[i] = INF;
        previous[i] = 0;
        notvisited.insert(i);
    }
    distance[1] = 0;
    while(!notvisited.empty()){
        int current = minVertex(distance, notvisited);
        if (current == N)
            break;
        for(int i=0; i<graph[current].size(); i++){
            if (distance[current]+graph[current][i].second < distance[graph[current][i].first]){
                distance[graph[current][i].first] = distance[current] + graph[current][i].second;
                previous[graph[current][i].first] = current;
            }
        }
    }
    int path = N;
    while(path != 1){
        printf("%d ",path);
        path = previous[path];
    }
    printf("1\n");
}
