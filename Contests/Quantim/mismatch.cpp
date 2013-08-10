#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int M[5001][5001];



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int k;
	char str[5001];
	scanf("%d", &k);
	scanf("%s", str);

	int n = strlen(str);

	long long count = 0;
	for(int j = 1; j < n; j++) {
		int l = 0;
		int r = l+j;
		int mismatch = 0;
		while(l+j < n) {
			while(r < n && (str[r-j] == str[r] || mismatch < k)) {
				if (str[r-j] != str[r])
					mismatch++;
				r++;
			}
			count += (r-l-j);
			if (str[l] != str[l+j])
				mismatch--;
			l++;
		}
	}


	printf("%lld\n", count);
 
    return 0;
}

