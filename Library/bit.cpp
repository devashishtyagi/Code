#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BIT{
private:
	int N;
	vector<int> tree;
public:
	BIT(int n): 
	N(n), tree(n, 0) {}
	int read(int idx){
		int sum = 0;
		while (idx > 0){
			sum += tree[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	void update(int idx ,int val){
		while (idx <= N){
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}
};