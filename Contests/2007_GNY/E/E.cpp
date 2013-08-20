#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long f[1001], g[1001], h[1001];

void init() {
	g[0] = 1; h[0] = 1; f[0] = 1; f[1] = 1;  g[1] = 1; h[1] = 2;

	for(int i = 2; i < 1001; i++) {
		f[i] = f[i-2] + f[i-1] + g[i-2] + 2*h[i-2];
		g[i] = f[i] + g[i-2];
		h[i] = f[i] + h[i-1];
	}
}


int main() {
	init();	

	int n;
	cin>>n;

	for(int i = 0; i < n; i++) {
		int w;
		cin>>w;
		cout<<i+1<<" "<<f[w]<<endl;
	}

	return 0;
}