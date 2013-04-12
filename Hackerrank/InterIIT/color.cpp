#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdio>

#define EPS 10e-3

using namespace std;

vector<double> r(65000);
vector<double> g(65000);
vector<double> b(65000);
vector<bool> label(65000);

 void read() {
 	ifstream myfile;
 	myfile.open("trainingdata.txt");
 	
 	int n;
 	int l;

 	myfile>>n;
 	for(int i = 0; i < n; i++){
 		myfile>>r[i]>>g[i]>>b[i]>>l;
 		r[i] /= 255.0;
 		g[i] /= 255.0;
 		b[i] /= 255.0;
 		if (l == 1)
 			label[i] = true;
 		else
 			label[i] = false;
 	}
 }

double dist(double r1, double g1, double b1, double r2, double g2, double b2) {
	return (pow(r1-r2,2) + pow(b1-b2,2) + pow(g1-g2,2));
}

 bool verdict(double a, double q, double c) {
 	int index = 0;
 	double mindist = dist(r[0], g[0], b[0], a, q, c);
 	for(int i = 1; i < 65000; i++) {
 		double now = dist(r[i], g[i], b[i], a, q, c);
 		if (now < mindist) {
 			mindist = now;
 			index = i;
 		}
 		else if (fabs(now-mindist) < EPS && label[i]){
 			mindist = now;
 			index = i;
 		}
 	}
 	return label[index];
 }

int main() {
	int t;
	read();
	cin>>t;
	while(t--) {
		double a, b, c;
		cin>>a>>b>>c;
		a /= 255.0;
		b /= 255.0;
		c /= 255.0;
		bool ans = verdict(a,b,c);
		if (ans)
			cout<<1<<endl;
		else
			cout<<2<<endl;
	}
	return 0;
}