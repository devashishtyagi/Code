#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	int n, m;

	scanf("%d %d", &n, &m);

	int x[m], y[m];

	vector<int> row(n, true), col(n, true);

	row[0] = false;
	row[n-1] = false;
	col[0] = false;
	col[n-1] = false;

	for(int i = 0; i < m; i++) {
		scanf("%d %d", &x[i], &y[i]);
		x[i]--; y[i]--;
		row[x[i]] = false;
		col[y[i]] = false;
	}

	int cnt = 0;

	for(int i = 1; i <= (n-1)/2; i++) {
		if (i == n-1-i) {
			if (row[i] || col[i])
				cnt++;
		}
		else {
			cnt += (row[i] + row[n-1-i] + col[i] + col[n-1-i]);
		}
	}

	printf("%d\n", cnt);

	return 0;
}