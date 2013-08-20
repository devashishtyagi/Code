#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>


using namespace std;

double mytan(double angle) {
	return tan(angle*M_PI/180.0);
}

double dist(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1-x2,2) + pow(y1-y2, 2));
}

int main() {
	int n;
	cin>>n;

	double D, l, ha, hb, errdist;

	cin>>D>>l>>ha>>hb>>errdist;

	for(int i = 0; i < n; i++) {
		double a, b, c, d;
		cin>>a>>b>>c>>d;

		if (c == d) {
			printf("%d DISQUALIFIED\n", i+1);
			continue;
		}

		double x = D*mytan(d)/(mytan(d) - mytan(c));
		double y = mytan(c)*x;


		if (y < 0 || x < 0 || x > D) {
			printf("%d DISQUALIFIED\n", i+1);
			continue;
		} 

		double base1 = dist(x, y, 0, 0);
		double base2 = dist(x, y, D, 0);

		double h1 = ha + base1*mytan(a);
		double h2 = hb + base2*mytan(b);

		if (fabs(h1-h2) <= errdist) {
			double h = (h1+h2)/2.0;
			printf("%d %.0lf\n", i+1, h);
		}
		else {
			printf("%d ERROR\n", i+1);
		}
	}	

	return 0;
}
