/*
 	C++ Template
	Pradeep George Mathias
 */


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define DREP(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define INDEX(a, val) (lower_bound(all(a), val) - a.begin())

const int maxn = 1005;
const int MOD = 1000000007;

int totalCases, testNum;
int N, M;

vector<int> adjl[maxn];
bool incycle[maxn];
bool visit[maxn];
vector <int> children[maxn];
int DP1[maxn];
int DP2[maxn];
int DP3[maxn];

int adjmat[maxn][maxn];

int curcomp[maxn]; int csz;

int p0(const int&);
int q0(const int&);
int p1(const int&);
int q1(const int&);
int f(const int&);
int g(const int&);
int h(const int&);
int ch(const int&);

void preprocess()
{
	
}

inline void reinit()
{
	for(int i = 0; i < N; i++)
	{	
		children[i].clear();
		adjl[i].clear();
	}
	fill(visit, false);
	fill(incycle, false);
	fill(DP1, -1);
	fill(DP2, -1);
	fill(DP3, -1);
}

bool input()
{
	s(N);
	s(M);
	
	fill(adjmat, 0);
	for(int i = 0; i < M; i++)
	{
		int a, b;
		s(a);
		s(b);
		a--; b--;
		if(adjmat[a][b] != 1)
		{
			adjl[a].push_back(b);
			adjl[b].push_back(a);			
		}
		adjmat[a][b] = adjmat[b][a] = 1;
	}
	return true;
}

int dfs(const int &u, const int &p)
{
	visit[u] = true;
	curcomp[csz++] = u;
	int ret = -5;
	incycle[u] = false;
	for(int i = 0; i < adjl[u].size(); i++)
	{
		int v = adjl[u][i];
		if(v == p)
			continue;
		if(visit[v])
		{
			incycle[u] = true;
			ret = v;
		}
		else
		{
			int rec = dfs(v, u);
			if(rec >= 0)
			{
				incycle[u] = true;
				if(u == rec)
					ret = -5;
				else 
					ret = rec;
			}
		}
	}
	return ret;
}

int tree(const int &u, const int &p)
{
	for(int i = 0; i < adjl[u].size(); i++)
	{
		int v = adjl[u][i];
		if(!(incycle[v] || v == p))
		{	
			children[u].push_back(v);
			tree(v, u);
		}
	}
}

int ch(const int &u)
{
	if(DP3[u] >= 0)
		return DP3[u];
	
	int term1 = 1;
	for(int i = 0; i < children[u].size(); i++)
	{
		int v= children[u][i];
		term1 = (term1 * 1ll * h(v)) % MOD;
	}
	return DP3[u] = term1;
}

//int g(int);

int h(const int &u)
{//DP1
	if(DP1[u] >= 0)
		return DP1[u];
	
	int ret = 1;
	for(int i = 0; i < children[u].size(); i++)
	{
		int v = children[u][i];
		ret = (ret * 1ll * g(v)) % MOD;
	}
	return DP1[u] = ret;
}

int g(const int &u)
{//DP2
	if(DP2[u] >= 0)
		return DP2[u];
	
	int ans = 0;
	int term1 = 1, term2 = 1;
	term1 = ch(u);
	term2 = h(u);
	DP2[u] = term1 + term2;
	if(DP2[u] >= MOD) DP2[u] -= MOD;
	return DP2[u];
}

int path[maxn]; int psz;

int q0(const int &pos)
{
	if(pos == psz - 1)
		return h(path[pos]);
	
	int term1 = (h(path[pos]) * 1ll * q0(pos+1)) % MOD;
	int term2 = (ch(path[pos]) * 1ll * p0(pos+1)) % MOD;
	return (term1 + term2 >= MOD) ? (term1 + term2 - MOD) : (term1 + term2);
}

int p0(const int &pos)
{
	if(pos == psz-1)
		return h(path[pos]);
	
	return (h(path[pos]) * 1ll * q0(pos+1)) % MOD;
}


int q1(const int &pos)
{
	if(pos == psz - 1)
		return g(path[pos]);
	
	int term1 = (h(path[pos]) * 1ll * q1(pos+1)) % MOD;
	int term2 = (ch(path[pos]) * 1ll * p1(pos+1)) % MOD;
	return (term1 + term2) % MOD;
}

int p1(const int &pos)
{
	if(pos == psz-1)
		return h(path[pos]);
	
	return (h(path[pos]) * 1ll * q1(pos+1)) % MOD;
}


int f(const int &v)
{
	csz = 0;
	//do a dfs and mark the cycle if exists
	dfs(v, v);		//O(E)
	bool hasCycle = false;
	for(int i = 0; i < csz; i++)
	{
		int u = curcomp[i];		//O(N)
		hasCycle = hasCycle || incycle[u];
	}
	if(hasCycle)
	{
		psz = 0;
		
		for(int i = 0; i < csz; i++)
		{		//O(N)
			int u = curcomp[i];
			if(incycle[u])
			{
				path[psz++] = u;
				int prev=-1;
				for(int j = u; true; )		//O(N)
				{
					int v;
					for(int k = 0; k < adjl[j].size(); k++)
					{
						v = adjl[j][k];
						if(incycle[v] && v != prev)
						{
							break;
						}
					}
					if(v == u)
						break;
					path[psz++] = v;
					prev = j;
					j = v;
				}
				
				for(int i = 0; i < psz; i++)
					tree(path[i], -1);
				
				int ret = 0;
				//choose 0
				int term1 = (ch(path[0]) * 1ll * p0(1)) % MOD;
				
				//dont choose 0
				int term2 = (h(path[0]) * 1ll * q1(1)) % MOD;
				ret = (term1 + term2) % MOD;
				return ret;
			}
		}
	}
	else 
	{
		tree(curcomp[0], -1);		//O(E)
		int ans = g(curcomp[0]);	//O(E)
		return ans;
	}
}

void solve()
{
	int ans = 1;
	for(int i = 0; i < N; i++)
	{
		if(!visit[i])
		{
			ans = (ans * 1ll * f(i))% MOD;
		}
	}
	printf("%d\n", ans);
}

int main()
{
	preprocess();
	s(totalCases);
	N = maxn;
	reinit();
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		solve();
		reinit();
	}
}
