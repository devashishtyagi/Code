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
#include <bitset>
#include <fstream>

#define sf(a) scanf("%d",&a)
#define ssf(a,b) scanf("%d %d",&a,&b)
#define pf(a) printf("%d\n",a)
#define foreach(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.end()

#define PB push_back
#define MP make_pair
#define sz(a) (int)(a).size()

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 2*acos(0.0)

using namespace std;

typedef long long ll;

int main()
{
  int n,m;
  map<string, string> chef;
  map<string, int> chefvote;
  map<string, int> countvote;
  
  cin>>n>>m;
  
  FOR(i,0,n)
  {
    string cf, ct;
    cin>>cf>>ct;
    chef[cf] = ct;
    chefvote[cf] = 0;
    countvote[ct] = 0;
  }
  
  FOR(i,0,m)
  {
    string cf;
    cin>>cf;
    chefvote[cf]++;
    countvote[chef[cf]]++;
  }
  
  string winchef, wincount;
  int maxvotes = -1;
  foreach(countvote, it)
  {
    if (maxvotes < it->second)
    {
      maxvotes = it->second;
      wincount = it->first;
    }
    else if (maxvotes == it->second && wincount > it->first)
      wincount = it->first;
  }
  cout<<wincount<<endl;

  maxvotes = -1;
  foreach(chefvote, it)
  {
    if (maxvotes < it->second)
    {
      maxvotes = it->second;
      winchef = it->first;
    }
    else if (maxvotes == it->second && winchef > it->first)
      winchef = it->first;
  }
  cout<<winchef<<endl;
  
  return 0;
}