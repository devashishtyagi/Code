#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define INF 1000000000

using namespace std;

class SegmentTree {
private:
	class Node {
	public:
		int d, sum;
	};

	int N;
	vector<Node> tree;

	inline int f(int a, int b) {
		return min(a, b);
	}

	void combine(int node) {
		tree[node].d = f(tree[2*node].d, tree[2*node].sum + tree[2*node+1].d); 
		tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
	}

	void build(int node, int l, int r, int* store) {
		if (l > r)
			return;
		if (l == r) {
			tree[node].d = store[l-1];
			tree[node].sum = store[l-1];
		}
		else {
			int mid = (l+r)>>1;
			build(2*node, l, mid, store);
			build(2*node + 1, mid+1, r, store);
			combine(node);
		}
	}

	int get(int node, int l, int r, int a, int b) {
		if (l > r || a > b)
			return INF;
		else if (l > b || r < a)
			return INF;
		else if (l == a && r == b) 
			return tree[node].d;
		int mid = (l+r)>>1;
		int p1 = get(2*node, l, mid, a, min(b, mid));
		int p2 = get(2*node+1, mid+1, r, max(mid+1, a), b);
		return f(p1, p2);
	}

	void point_update(int node, int l, int r, int a, int val) {
		if (l > r || l > a || r < a)
			return;
		else if (l == a && r == a) {
			tree[node].sum += val;
			tree[node].d += val;
			return;
		}
		int mid = (l+r)>>1;
		point_update(2*node, l, mid, a, val);
		point_update(2*node+1, mid+1, r, a, val);
		combine(node);
	}

public:
	SegmentTree(int n, int* store) {
		init(n, store);
	}

	void init(int n, int* store) {
		N = n;
		tree.resize(4*N+2);
		build(1, 1, N, store);
	}

	int calc(int start, int end) {
		return get(1, 1, N, start+1, end+1);
	}

	int change_point(int p, int val) {
		point_update(1, 1, N, p+1, val);
	}
};

char brackets[30005];
int store[30005];

int main(void) {
	for(int i = 1; i <= 10; i++) {
		int n;
		scanf("%d", &n);
		scanf("%s", brackets);

		int total = 0;
		for(int j = 0; j < n; j++) {
			if (brackets[j] == '(')
				store[j] = 1;
			else
				store[j] = -1;
			total += store[j];
		}

		SegmentTree stree(n, store);

		int m;
		scanf("%d", &m);

		printf("Test %d:\n", i);

		while(m--) {
			int k;
			scanf("%d", &k);

			if (k == 0) {
				int val = stree.calc(0, n-1);
				if (total == 0 && stree.calc(0, n-1) >= 0)
					printf("YES\n");
				else 
					printf("NO\n");
			}
			else {
				k--;
				int change_val = -2*store[k];
				store[k] = -store[k];
				total += change_val;
				stree.change_point(k, change_val);
			}
		}
	}

	return 0;
}