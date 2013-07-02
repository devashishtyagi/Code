/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define sf(a) scanf("%d",&a)
#define ssf(a,b) scanf("%d %d",&a,&b)
#define pf(a) printf("%d\n",a)
#define foreach(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.end()

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define init0(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define MOD 1000000009
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

vector< vector<int> > tree;
vector< vector<char> > clash;
vector<char> label;
vector<bool> visited;

bool dfs(int v) {
	visited[v] = true;
	vector<int> letterCount(26, 0);

	for(int i = 0; i < tree[v].size(); i++) {
		int to = tree[v][i];
		if (!visited[to]) {
			dfs(to);
			for(int j = 0; j < clash[to].size(); j++)
				letterCount[clash[to][j]-'A']++;
		}
	}

	char apt = '$';
	for(char c = 'A'; c <= 'Z'; c++) {
		bool valid = true;
		for(int i = c-'A'+1; i < 26; i++) {
			if (letterCount[i] > 1)
				valid = false;
		}
		if (letterCount[c-'A'] > 0)
			valid = false;
		if (valid) {
			apt = c;
			break;
		}
	}

	if (apt == '$')
		return false;
	else {
		clash[v].push_back(apt);
		for(int i = apt-'A'+1; i < 26; i++) {
			if (letterCount[i] > 0)
				clash[v].push_back(i+'A');
		}
		label[v] = apt;
		return true;
	}
}


int main()
{
	int n;
	cin>>n;

	tree.resize(n);
	clash.resize(n);

	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin>>a>>b;
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	label.resize(n);
	visited.resize(n, false);

	if (dfs(0)) {
		for(int i = 0; i < n; i++)
			cout<<(char)(('Z'-label[i])+'A')<<" ";
		cout<<endl;
	}
	else {
		cout<<"Impossible!"<<endl;
	}

	return 0;
}
