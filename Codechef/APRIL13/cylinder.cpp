/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
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
#define PI 3.1415926535897932384626433832795028841971693993751058209

using namespace std;
typedef long long ll;

double first(double w, double h) {
	double start1 = w/(2.0*(2.0+PI)), end1 = w/(2.0*(1.0+PI));
	double start2 = h/2.0, end2 = h/4.0;
	double r;
	if (start1 >= start2) {
		r = start2;
	}
	else if (end1 <= end2) {
		r = end1;
	}
	else {
		double a = h*h + w*w;
		double A = h*(1+PI) - w;
		double b = 2*A*h;	
		double c = A*A - w*w;
		double soln = (-b + sqrt(b*b - 4*a*c))/(2.0*a);
		r = w/(2.0*(1+PI+soln));
	}
	double vol = PI*r*r*h;
	return vol;
}

double second(double w, double h) {
	double begin = w/3.0, end = w/6.0;
	double flat = h/(2*PI);
	double vol;
	if (begin <= flat) {
		double r = begin;
		vol = PI*r*r*(w - 2*r);
	}
	else if (end > flat) {
		double r = flat;
		vol = PI*r*r*(w - 2*r);
	}
	else {
		double r = flat;
		vol = PI*r*r*(w - 2*r);	
	}
	return vol;
}


int main()
{
	int t;
	sf(t);
	while(t--) {
		double w, h;
		scanf("%lf %lf", &w, &h);
		double vol = first(w, h);
		vol = max(vol, second(w, h));
		vol = max(vol, first(h, w));
		vol = max(vol, second(h, w));
		printf("%.16lf\n",vol);
	}  
	return 0;
}
