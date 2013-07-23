#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <random>

int main(void) {
	freopen ("test.txt","w",stdout);

	int n = 100000;
	int q = 10000;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> cdistribution(0, 1);
	std::uniform_int_distribution<int> vdistribution(1, n);

	printf("%d %d\n", n, q);

	for(int i = 2; i <= n; i++) {
		std::uniform_int_distribution<int> distribution(1,i-1);
		int number = distribution(generator);
		printf("%d %d\n", number, i);
	}

	for(int i = 0; i < q; i++) {
		printf("%d %d\n", cdistribution(generator), vdistribution(generator));
	}


	fclose(stdout);
}
