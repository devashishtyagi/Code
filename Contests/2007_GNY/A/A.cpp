#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	int n;
	cin>>n;

	for(int i = 1; i <=n ; i++)	{
		double v;
		string unit;
		cin>>v>>unit;
		cout<<i<<" ";
		if (unit == "kg") {
			printf("%.4f lb", v*2.2046f);
		}
		else if (unit == "lb") {
			printf("%.4f kg", v*0.4536f);
		}
		else if (unit == "l") {
			printf("%.4f g", v*0.2642f);
		}
		else {
			printf("%.4f l", v*3.7854f);
		}
		printf("\n");
	}

	return 0;
}