/* CPP Tempelate
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

int grundy[5001];

void init() {
	grundy[0] = 0;

	bool taken[5001];

	for(int i = 1; i < 5001; i++) {
		memset(taken, false, sizeof taken);
		for(int j = 0; j < i; j++) {
			taken[grundy[max(0, j-1)]^grundy[max(0, i-j-2)]] = true;
		}

		int t = 0;
		for(int j = 0; j < 5001; j++) {
			if (taken[j])
				t++;
			else
				break;
		}
		grundy[i] = t;
	}
}

int main()
{

	init();

	string str;
	cin>>str;

	int xorsum = 0, cnt = 0, start = 1;
	vector< pair<int,int> > portions;

	for(int i = 1; i < str.size(); i++) {
		if (i < str.size()-1 && str[i-1] == str[i+1]) {
			cnt++;
		}
		else {
			portions.push_back(make_pair(start, cnt));
			//cout<<start<<" "<<cnt<<endl;
			xorsum ^= grundy[cnt];
			cnt = 0;
			start = i + 1;
		}
 	} 

	if (xorsum == 0)
		cout<<"Second"<<endl;
	else {
		cout<<"First"<<endl;
		for(int i = 0; i < portions.size(); i++) {
			for(int j = 0; j < portions[i].second; j++) {
				int temp = xorsum^grundy[portions[i].second];
				int len = portions[i].second;
				temp ^= grundy[max(0, len-j-2)];
				temp ^= grundy[max(0, j-1)];
				//cout<<portions[i].first<<" "<<j<<" "<<temp<<endl;
				if (temp == 0) {
					cout<<portions[i].first+j+1<<endl;
					return 0;
				}
			}
		}
	}

	return 0;
}
