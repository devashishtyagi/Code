#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <numeric>
#include <iostream>
#include <map>
#include <cstdio>
#include <cmath>


#define EPS 10E-10
#define REMOVE_REDUNDANT


using namespace std;

class Point {
public:
	double x, y;

	Point() {}
	 
	Point(double xv, double yv){
		setX(xv);
		setY(yv);
	}
	
	void setX(double value) {
		x = value;
	} 

	void setY(double value) {
		y = value;
	}

	Point operator+ (const Point &p) const {
		Point temp;
		temp.setX(p.x + x);
		temp.setY(p.y + y);
		return temp;
	}

	Point operator- (const Point &p) const {
		Point temp;
		temp.setX(p.x - x);
		temp.setY(p.y - y);
		return temp;	
	}

	Point operator/ (double c) const {
		Point temp;
		temp.x = x/c;
		temp.y = y/c;
		return temp;
	}

	bool operator== (const Point &p) const {
		return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
	}

	bool operator< (const Point &p) const {
		return (y < p.y || (y == p.y && x < p.x));
	}

	double distance(const Point &p) {
		return hypot(x - p.x , y - p.y);
	}
};

double dot(Point p, Point q) {
	return (p.x*q.x+p.y*q.y);
}

double cross(Point p, Point q) {
	return (p.x*q.y - p.y*q.x);
}

double dist2(Point p, Point q) {
	return hypot(p.x-q.x, p.y-q.y);
}

ostream &operator<<(ostream &os, const Point &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

/* Returns
	Signed area of the triangle
	> 0 if P3 is left of P1 and P2 segment
	= 0 if P3 if on the P1 and P2 segment
	< 0 if P3 is right of P1 and P2 segment
*/
double area2(Point P1, Point P2, Point P3) {
	double value = (P3.x - P2.x)*(P1.y - P2.y) - (P3.y - P2.y)*(P1.x - P2.x);
	return value;
}

/* Returns
	true if P3 lies between P1 and P2 segment
*/
bool InsideLineSegment(Point P1, Point P2, Point P3) {
	if (fabs(area2(P1, P2, P3)) < EPS && (P3.x - P2.x)*(P1.x - P2.x) + (P3.y - P2.y)*(P1.y - P2.y) > 0)
		return true;
	else
		return false;
}

/* Computes Convex Hull using Graham Scan
	The vector returned contains the indices of the points on the convex hull
	If multiple copies of a point exist, the last one to appear is given in the answer
*/

bool comparator(pair<double, int> p1, pair<double, int> p2) {
	if (p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second))
		return true;
	else
		return false;
}

void ConvexHull(vector<Point> &pts) {
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	vector<Point> up, dn;
	for (int i = 0; i < pts.size(); i++) {
		while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
		while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
		up.push_back(pts[i]);
		dn.push_back(pts[i]);
	}
	pts = dn;
	for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

	#ifdef REMOVE_REDUNDANT
	if (pts.size() <= 2) return;
	dn.clear();
	dn.push_back(pts[0]);
	dn.push_back(pts[1]);
	for (int i = 2; i < pts.size(); i++) {
		if (InsideLineSegment(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
		dn.push_back(pts[i]);
	}
	if (dn.size() >= 3 && InsideLineSegment(dn.back(), dn[0], dn[1])) {
		dn[0] = dn.back();
		dn.pop_back();
	}
	pts = dn;
	#endif
}

double DiameterPolygon(vector<Point> &pt) {
	int a = 0;
	double ans = 0;
	for(int i = 0; i < pt.size(); i++) {
		if (a == i) {
			a = i+1;
			if (a == pt.size()) a = 0;
		}
		while(true) {
			int t = a+1;
			if (t >= pt.size()) t = 0;
			if (t == i) break;
			double s1 = dist2(pt[i], pt[a]);
			double s2 = dist2(pt[i], pt[t]);
			if (s2 >= s1)
				a = t;
			else
				break;
		}
		ans = max(ans, dist(pt[i], pt[a]));
	}	
	return ans;
}