#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	vector<int> num(n);
	int high[2][n], low[2][n];

	for(int i = 0; i < n; i++)
		scanf("%d",&num[i]);

	long long maxsum = 0, minsum = 0;
	for(int i = 0; i < n; i++) {
		high[0][i] = num[i];
		low[0][i] = num[i];
		maxsum += num[i];
		minsum += num[i];
	}

	int prev = 0, curr = 1;
	for(int k = 1; k < n; k++) {
		for(int i = 0; i < n-k; i++){
			high[curr][i] = max(high[prev][i], num[i+k]);
			low[curr][i] = min(low[prev][i], num[i+k]);
			maxsum += high[curr][i];
			minsum += low[curr][i];
		}
		swap(prev, curr);
	}
	printf("%lld\n", maxsum-minsum);

	return 0;
}