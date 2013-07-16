/* Segment Tree
 * Store is 0-indexed based. And segment tree is 1-indexed based.
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
		int d, sum;
	};

	int N;
	vector<Node> tree;

	inline int f(int a, int b) {
		return min(a, b);
	}

	void combine(int node) {
		// Do something here
	}

	void build(int node, int l, int r, int* store) {
		if (l > r)
			return;
		if (l == r) {
			// Do something here
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
			// Do something here
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