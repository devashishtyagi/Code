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

int main(){
	int n;
	cin>>n;
	
	vector<int> colcount(n, 0);
	vector<int> rowcount(n, 0);
	vector< pair<int, pair<int,int> > > ops;
	vector< vector<int> > matrix(n, vector<int>(n,0));
	
	for(int i=0; i<n-1; i++){
		int x,y;
		cin>>x>>y;
		rowcount[x-1]++;
		colcount[y-1]++;
		matrix[x-1][y-1] = 1;
	}
	
	int size = n;
	while(size > 0){
		int col = -1;
		for(int i=0; i<size-1; i++){
			if (colcount[i] == 0){
				col = i+1;
				break;
			}
		}
		if (col != -1 && colcount[size-1] > 0){
			ops.push_back(make_pair(2, make_pair(col,size)));
			swap(colcount[col-1], colcount[size-1]);
			for(int i=0; i<size; i++){
				swap(matrix[i][col-1], matrix[i][size-1]);
			}
		}
		int row = -1;
		for(int i=0; i<size-1; i++){
			if (rowcount[i] > 0){
				row = i+1;
				break;
			}
		}
		if (row != -1 && rowcount[size-1] == 0){
			ops.push_back(make_pair(1, make_pair(row,size)));
			swap(rowcount[row-1], rowcount[size-1]);
			for(int i=0; i<size; i++){
				swap(matrix[row-1][i], matrix[size-1][i]);
			}
		}
		for(int i=0; i<size; i++){
			colcount[i] -= matrix[size-1][i];
			rowcount[i] -= matrix[i][size-1];
		}
		size--;
	}
	
	cout<<ops.size()<<endl;
	for(int i=0; i<ops.size(); i++){
		cout<<ops[i].first<<" "<<ops[i].second.first<<" "<<ops[i].second.second<<endl;
	}
	
	return 0;
}