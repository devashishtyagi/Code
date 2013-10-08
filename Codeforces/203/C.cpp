/* CPP Tempelate
 * @author "D"evashish Tyagi
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


// Compiler utility
#define int_msb(x) ((31) - __builtin_clz(x))

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


int main()
{
	int n;
	cin>>n;

	vector< pair<int, int> > first, second, third, fourth;

	int k = 0;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin>>x>>y;
		if (x >= 0 && y >= 0)
			first.push_back(make_pair(x, y));
		else if (x < 0 && y >= 0)
			second.push_back(make_pair(-x, y));
		else if (x < 0 && y < 0)
			third.push_back(make_pair(-x, -y));
		else
			fourth.push_back(make_pair(x, -y));
		k += ((x != 0) + (y != 0));
	}

	k = 2*k;
	k += 2*n;

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	sort(third.begin(), third.end());
	sort(fourth.begin(), fourth.end());

	cout<<k<<endl;

	for(int i = 0; i < first.size(); i++) {
		if (first[i].first != 0)
			cout<<1<<" "<<first[i].first<<" "<<"R"<<endl;
		if (first[i].second != 0)
			cout<<1<<" "<<first[i].second<<" "<<"U"<<endl;
		cout<<2<<endl;
		if (first[i].first != 0)
			cout<<1<<" "<<first[i].first<<" "<<"L"<<endl;
		if (first[i].second != 0)
			cout<<1<<" "<<first[i].second<<" "<<"D"<<endl;
		cout<<3<<endl;
	}

	first = second;

	for(int i = 0; i < first.size(); i++) {
		if (first[i].first != 0)
			cout<<1<<" "<<first[i].first<<" "<<"L"<<endl;
		if (first[i].second != 0)
			cout<<1<<" "<<first[i].second<<" "<<"U"<<endl;
		cout<<2<<endl;
		if (first[i].first != 0)
			cout<<1<<" "<<first[i].first<<" "<<"R"<<endl;
		if (first[i].second != 0)
			cout<<1<<" "<<first[i].second<<" "<<"D"<<endl;
		cout<<3<<endl;
	}

	first = fourth;

	for(int i = 0; i < first.size(); i++) {
		if (first[i].first != 0)
			cout<<1<<" "<<first[i].first<<" "<<"R"<<endl;
		if (first[i].second != 0)
			cout<<1<<" "<<first[i].second<<" "<<"D"<<endl;
		cout<<2<<endl;
		if (first[i].first != 0)
			cout<<1<<" "<<first[i].first<<" "<<"L"<<endl;
		if (first[i].second != 0)
			cout<<1<<" "<<first[i].second<<" "<<"U"<<endl;
		cout<<3<<endl;
	}


	first = third;

	for(int i = 0; i < first.size(); i++) {
		if (first[i].first != 0)
			cout<<1<<" "<<first[i].first<<" "<<"L"<<endl;
		if (first[i].second != 0)
			cout<<1<<" "<<first[i].second<<" "<<"D"<<endl;
		cout<<2<<endl;
		if (first[i].first != 0)
			cout<<1<<" "<<first[i].first<<" "<<"R"<<endl;
		if (first[i].second != 0)
			cout<<1<<" "<<first[i].second<<" "<<"U"<<endl;
		cout<<3<<endl;
	}

	return 0;
}
