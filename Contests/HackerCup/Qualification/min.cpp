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

#define PB push_back
#define MP make_pair
#define sz(a) (int)(a).size()

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 3.1415926535897932

using namespace std;

int MaxVal = 0;
int tree[100002];
int occur[100002];

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int getMin(int lo, int hi){
	int ans = -1;
	while(lo <= hi){
		int mid = (lo + hi)>>1;
		int val = read(mid);
		if (val < mid){
			if (occur[mid-1] == -1){
				ans = mid-1;
			}
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n,k,a,b,c,r;
		cin>>n>>k;
		cin>>a>>b>>c>>r;
		MaxVal = k+1;
		
		CLEAR(tree);
		memset(occur, -1, sizeof occur);
		vector<int> m(k);
		vector<int> period(k+1, -1);
		
		m[0] = a;
		if (m[0] <= k){
			update(m[0]+1, 1);
			occur[m[0]] = 0;
		}
		
		for(int j=1; j<k; j++){
			m[j] = ((long long)b*m[j-1]+(long long)c)%r;
			if (m[j] <= k){
				if (occur[m[j]] == -1)
					update(m[j]+1, 1);
				occur[m[j]] = j;
			}
		}
		for(int j=0; j<=k; j++){
			period[j] = getMin(1, k+1);	
			if (m[j] <= k && occur[m[j]] == j){
				update(m[j]+1, -1);
				occur[m[j]] = -1;
			}
			occur[period[j]] = j;
			update(period[j]+1, 1);
		}
		int index = (n-k-1)%(k+1);
		cout<<"Case #"<<i+1<<": "<<period[index]<<endl;
	}
	return 0;
}