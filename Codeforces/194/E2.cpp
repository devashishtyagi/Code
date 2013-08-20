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
#define EPS 10E-7
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

class point {
public:
	int x, y;
};

int n;
point pts[3001], pt[3001], up[3001], dn[3001];

inline int area2(point &p1, point &p2, point &p3) {
	return (p3.x - p2.x)*(p1.y - p2.y) - (p3.y - p2.y)*(p1.x - p2.x);
}

inline int dist(point p1, point p2) {
	return (p2.y - p1.y)*(p2.y - p1.y)+  (p2.x - p1.x)*(p2.x - p1.x);
}

bool comp(const point &p1, const point &p2) {
	if (make_pair(p1.y, p1.x) < make_pair(p2.y, p2.x))
		return true;
	else
		return false;
}

bool verify(double v, int sz) {
	if (sz < 2)
		return false;

	int l = 0, m = 0;
	for(int i = 0; i < sz; i++) {
		while(l > 1 && area2(up[l-2], up[l-1], pt[i]) >= 0) up[l--];
		while(m > 1 && area2(dn[m-2], dn[m-1], pt[i]) <= 0) dn[m--];
		up[l++] = pt[i];
		dn[m++] = pt[i];
	}
	for(int i = l-1; i >= 0; i--) dn[m++] = up[i];

	// Write something to compute diameter of the convex hull
	if (m == 2) {
		if (dist(dn[0], dn[1]) >= v)
			return true;
		else
			return false;
	}

	int a = 0;
	for(int i = 0; i < m; i++) {
		if (a == i) {
			a = i+1;
			if (a == m) a = 0;
		}
		while(true) {
			int t = a+1;
			if (t >= m) t = 0;
			if (t == i) break;
			double s1 = dist(dn[i], dn[a]);
			double s2 = dist(dn[i], dn[t]);
			if (s2 >= s1)
				a = t;
			else
				break;
		}
		if (dist(dn[i], dn[a]) >= v)
			return true;
	}	
	return false;
}

bool check(double v) {
	for(int i = 0; i < n; i++) {
		int k = 0;
		for(int j = i+1; j < n; j++) {
			if (dist(pts[i], pts[j]) >= v) {
				pt[k++] = pts[j];
				//cout<<pts[i].x<<" "<<pts[i].y<<" "<<pts[j].x<<" "<<pts[j].y<<endl;
			}
		}
		if (verify(v, k)) {
			//cout<<pts[i].x<<" "<<pts[i].y<<" "<<v<<" "<<pt.size()<<endl;
			return true;
		}
	}
	return false;
}

int main(void)
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d %d", &pts[i].x, &pts[i].y);
	}

	sort(pts, pts+n, comp);

	double low = 0.0, high = 10E9;

	for(int i = 0; i < 85; i++) {
		double mid = (low+high)/2.0;
		if (check(mid))
			low = mid;
		else
			high = mid;
	}

	printf("%.8lf\n", sqrt(low/4.0));

	return 0;
}
