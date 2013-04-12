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

const int MOD = 1000000007;

int totalCases, testNum;

vector <vector <int> > T;
int N;

void preprocess()
{
	T.resize(4);
	for(int i = 0; i < 4; i++)
		T[i].resize(4, 0);
	T[0][0] = 1;
	T[0][1] = 2;
	T[0][2] = 3;
	T[0][3] = 1;
	for(int i = 1; i < 4; i++)
		T[i][i-1] = 1;
}

vector <vector<int> > mult(vector <vector<int> > A, vector <vector<int> > B)
{
	vector <vector <int> > ret;
	ret.resize(4);
	for(int i = 0; i < 4; i++)
	{
		ret[i].resize(4);
		for(int j = 0; j < 4; j++)
		{
			ret[i][j] = 0;
			for(int k = 0; k < 4; k++)
				ret[i][j] = (ret[i][j] + A[i][k] * 1ll * B[k][j]) % MOD;
		}
	}
	return ret;
}

vector <vector <int> > mypow(vector <vector<int> > M, long long expo)
{
	if(expo == 1)
		return M;
	
	vector <vector<int> > rec = mypow(mult(M, M), expo>>1);
	if(expo & 1)
		return mult(rec, M);
	else 
		return rec;
}

bool input()
{
	s(N);
	return true;
}

void solve()
{
	if(N == 1)
	{
		printf("1\n");
		return;
	}
	
	vector <vector<int> > Tm = mypow(T, N-1);
	int ans = (12ll * Tm[3][0] + 5ll * Tm[3][1] + 2ll * Tm[3][2] + Tm[3][3]) % MOD;
	printf("%d\n", ans);
	
}

int main()
{
	preprocess();
	s(totalCases);
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		solve();
	}
}
