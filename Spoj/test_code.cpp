#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int kMaxN = 100000;
int n, cnt, begin[kMaxN], end[(kMaxN - 1) * 2], next[(kMaxN - 1) * 2];
int q[kMaxN], qh, qt, dep[kMaxN], par[kMaxN], sz[kMaxN], hvst[kMaxN], jump[kMaxN];
int buf[kMaxN], buf_idx;
int m;

void AddEdge(int u, int v) {
	next[cnt] = begin[u];
	begin[u] = cnt;
	end[cnt ++] = v;
}

struct Node {
	int l, r, v, t, g;
	Node *son[2];
	void update() {
		g = (son[0]->g == -1 ? son[1]->g : son[0]->g);
	}
} node_pool[kMaxN * 2 - 1], *node_idx = node_pool, *root[kMaxN];

Node *BuildTree(int l, int r) {
	Node *res = node_idx ++;
	res->l = l, res->r = r;
	if (l == r) res->v = 0, res->t = buf[dep[buf[0]] - l], res->g = -1;
	else {
		int mid = (l + r) >> 1;
		res->son[0] = BuildTree(l, mid);
		res->son[1] = BuildTree(mid + 1, r);
		res->update();
	}
	return res;
}

void ChangeOnPoint(int x, Node *pos) {
	if (pos->l == pos->r) {
		pos->v ^= 1;
		if (pos->v) pos->g = pos->t;
		else pos->g = -1;
		return;
	}
	int mid = (pos->l + pos->r) >> 1;
	if (x <= mid) ChangeOnPoint(x, pos->son[0]);
	else ChangeOnPoint(x, pos->son[1]);
	pos->update();
}

int AskOnRange(int l, int r, Node *pos) {
	if (l <= pos->l && r >= pos->r) return pos->g;
	int mid = (pos->l + pos->r) >> 1;
	int a = -1, b = -1;
	if (l <= mid) a = AskOnRange(l, r, pos->son[0]);
	if (r > mid) b = AskOnRange(l, r, pos->son[1]);
	return (a == -1 ? b : a);
}

int main() {
	memset(begin, -1, sizeof(begin));
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < n - 1; ++ i) {
		scanf("%d%d", &u, &v);
		-- u, -- v;
		AddEdge(u, v);
		AddEdge(v, u);
	}
	par[q[qt ++] = 0] = -1;
	while (qh < qt) {
		int u = q[qh ++];
		for (int now = begin[u], v; now != -1; now = next[now])
			if ((v = end[now]) != par[u]) {
				par[q[qt ++] = v] = u;
				dep[v] = dep[u] + 1;
			}
	}
	memset(hvst, -1, sizeof(hvst));
	memset(sz, 0, sizeof(sz));
	for (int i = n - 1; i >= 0; -- i) {
		int u = q[i];
		++ sz[u];
		if (par[u] != -1) {
			sz[par[u]] += sz[u];
			if (hvst[par[u]] == -1 || sz[u] > sz[hvst[par[u]]])
				hvst[par[u]] = u;
		}
	}
	for (int i = n - 1; i >= 0; -- i) {
		int u = q[i];
		if (root[u]) continue;
		buf_idx = 0;
		int p = u;
		do {
			buf[buf_idx ++] = p;
			if (par[p] == -1 || hvst[par[p]] != p) break;
			p = par[p];
		} while (true);
		Node *tmp = BuildTree(dep[buf[buf_idx - 1]], dep[buf[0]]);
		for (int j = 0; j < buf_idx; ++ j) {
			jump[buf[j]] = par[p];
			root[buf[j]] = tmp;
		}
	}
	for (int t, u; m --; ) {
		scanf("%d%d", &t, &u);
		-- u;
		if (t == 1) {
			int res = -1;
			while (u != -1) {
				int tmp = AskOnRange(root[u]->l, dep[u], root[u]);
				if (tmp != -1) res = tmp;
				u = jump[u];	
			}
			if (res != -1) ++ res;
			printf("%d\n", res);
		}
		else ChangeOnPoint(dep[u], root[u]);
	}
	return 0;
}