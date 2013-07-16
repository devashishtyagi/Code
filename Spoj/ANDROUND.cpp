/* CPP Template
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

using namespace std;

class SegmentTree {
private:
	class Node {
	public:
		int d;
	};

	int N;
	vector<Node> tree;

	void combine(int node) {
		tree[node].d = tree[2*node].d&tree[2*node+1].d; 
	}

	void build(int node, int l, int r, int* store) {
		if (l > r)
			return;
		if (l == r) {
			tree[node].d = store[l-1];
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
			return -1;
		else if (l > b || r < a)
			return -1;
		else if (l == a && r == b) 
			return tree[node].d;
		int mid = (l+r)>>1;
		int p1 = get(2*node, l, mid, a, min(b, mid));
		int p2 = get(2*node+1, mid+1, r, max(mid+1, a), b);
		if (p1 == -1 && p2 == -1)
			return -1;
		else if (p1 == -1)
			return p2;
		else if (p2 == -1)
			return p1;
		else
			return p1&p2;
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
};


int total[100001];

int main(void) {
	int t;
	scanf("%d",&t);

	while(t--) {
		int n, k;
		scanf("%d %d",&n,&k);
	
		for(int i = 0; i < n; i++) {
 			scanf("%d", &total[i]);
 			total[n+i] = total[i];
 		}

 		SegmentTree stree(2*n, total);


		for(int i = 0; i < n; i++) {
			if (k > n/2) {
				printf("%d", stree.calc(0, n-1));
			}
			else {
				int start = i-k;
				if (start < 0)
					start += n;
				int end = start + 2*k;
				
				int ans = stree.calc(start, end);

				printf("%d", ans);
			}
			if (i == n-1)
				printf("\n");
			else
				printf(" ");
		}
	}

	return 0;
}
