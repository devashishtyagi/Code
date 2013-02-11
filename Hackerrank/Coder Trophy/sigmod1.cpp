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
#define split(str) {vs.clear();istringstream ss(str);while(ss>>(str))vs.push_back(str);}
#define PI 3.141592653589793
#define EPS 1e-10
int main()
{
  int t;
  sf(t);
  while(t--)
  {
    double w;
    cin>>w;
    vector<double> v;
    vector<double> sinval;
    vector<double> cosval;
    double t=0.0;
    FOR(i,100)
    {
      double a;
      cin>>a;
      v.PB(a);
      sinval.PB(sin(PI*w*t));
      cosval.PB(cos(PI*w*t));
      t+=1/10000.0;
    }
      double b = v[0], a = 0.0;
      vector<double> values;
      for(int i=0; i<100; i++){
          if (abs(sinval[i]) > EPS){
              double temp = (v[i] - b*cosval[i])/sinval[i];
              values.push_back(temp);
          }
      }
      sort(values.begin(), values.end());
	  if (values.size() % 2 == 0)
		a = (values[values.size()/2] + values[(values.size()-1)/2])/2.0;
	  else
		  a = values[values.size()/2];
      values.clear();
      
      for(int i=0; i<100; i++){
          if (abs(cosval[i]) > EPS){
              double temp = (v[i] - a*sinval[i])/cosval[i];
              values.push_back(temp);
          }
      }
      sort(values.begin(), values.end());
	  if (values.size() % 2 == 0)
		b = (values[values.size()/2] + values[(values.size()-1)/2])/2.0;
	  else
		b = values[values.size()/2];
      cout<<a<<" "<<b<<endl;
  }
}
