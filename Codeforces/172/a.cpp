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

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int convertString(string s)
{
  int num;
  stringstream sstr(s); // create a stringstream
  sstr>>num; // push the stream into the num
  return num;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
	    elems.push_back(item);
	}
}

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }


double cot(double angle) {
	return 1.0/tan(angle);
}


int main()
{
	double w, h;
	cin>>w>>h;
	double a;
	cin>>a;

	if (a == 90) {
		cout<<min(w,h)*min(w,h)<<endl;
		return 0;
	}
	else if (a == 180 || a == 0) {
		cout<<w*h<<endl;
		return 0;
	}

	a = a*PI/180.0;

	double x1 = w/2.0 + h/2.0*(cot(a) - 1/sin(a));
	double y1 = w/2.0*tan(a) + h/2.0*(1.0 - 1.0/cos(a));

	double x2 = h/2.0*tan(a) + w/2.0*(1.0 - 1/cos(a));
	double y2 = h/2.0 + w/2.0*(cot(a) - 1.0/sin(a));

	double area1 = h*h*tan(a)/4.0 + w*h*(1.0 - 1.0/cos(a))/2.0 + w*w/4.0*(cot(a) - 2.0/sin(a) + 1/(sin(a)*cos(a)));
	double area2 = w*w*tan(a)/4.0 + w*h*(1.0 - 1.0/cos(a))/2.0 + h*h/4.0*(cot(a) - 2.0/sin(a) + 1/(sin(a)*cos(a)));

	cout<<area1<<" "<<area2<<endl;

	double sum;
	if (area1 < 0 ) {
		sum = -area2 - area1;
	}
	else if (area2 < 0) {
		sum = -area1 - area2;
	}
	else {
		sum = area1 + area2;
	}

	printf("%.9f\n", w*h - sum);


	return 0;

}