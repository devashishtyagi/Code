/* Segment Tree
 * Segment tree is 1-indexed based. Supports range queries and range updates.
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

class SegmentTree{
private:
	class Node {
	public:
		pair<int, int> f;
		long long upd;
		int len;
	};

	int N;
	vector< Node > tree;

	void combine(int node) {		
	}

	void applyUpdate(int node, int upd) {
	}

	void pushUpdate(int node) {
		// Push update to 2*node and 2*node+1
	}

	void build(int node, int l, int r, vector<int>& store) {
		if (l > r)
			return;
		if (l == r) {
			// Initialize content
			return;
		}
		int mid = (l+r)>>1;
		build(2*node, l, mid, store);
		build(2*node +1 , mid+1, r, store);
		combine(node);
	}

	pair<int, int> get(int node, int l, int r, int a, int b){
		if (l > r || a > b || a > r || b < l)
			return IDENTITY;
		else if (a == l && b == r)
			return tree[node].f;

		pushUpdate(node);

		int mid = (l+r)>>1;
		pair<int, int> p1 = get(2*node, l, mid, a, min(mid, b));
		pair<int, int> p2 = get(2*node+1, mid+1, r, max(a, mid+1), b);

		// Return some combination of both results

		return ;
	}

	void update(int node, int l, int r, int a, int b, int v) {
		if (l > r || a > b || r < a || l > b)
			return;
		else if (l == a && r == b){
			applyUpdate(node, v);
			return;
		}

		pushUpdate(node);

		int mid = (l+r)>>1;
		update(2*node, l, mid, a, min(b, mid), v);
		update(2*node + 1, mid+1, r, max(mid+1, a), b, v);
		
		combine(node);
	}

	void modify(int node, int l, int r, int index, int v) {
		if (l > r || index > r || index < l)
			return;
		else if (l == r){
			tree[node].f = make_pair(v, v);
			return;
		}

		pushUpdate(node);

		int mid = (l+r)>>1;
		modify(2*node, l, mid, index, v);
		modify(2*node + 1, mid+1, r, index, v);

		combine(node);
	}

public:
	SegmentTree(int n, vector<int>& store){
		N = n;
		tree.resize(4*N+2);
		build(1, 1, N, store);
	}

	int calculate(int i, int j){
		return get(1, 1, N, i, j).first;
	}

	void range_update(int i, int j, int v){
		update(1, 1, N, i, j, v);
	}

	void point_update(int i, int x) {
		modify(1, 1, N, i, x);
	}
};