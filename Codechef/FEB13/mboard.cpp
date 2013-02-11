#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

class BIT{
private:
	int N;
	vector<int> tree;
public:
	BIT(int n): 
	N(n), tree(n, 0) {}
	int read(int idx){
		int sum = 0;
		while (idx > 0){
			sum += tree[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	void update(int idx ,int val){
		while (idx <= N){
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}
};

int main(){
	int n,q;
	char op[20];
	scanf("%d %d",&n,&q);
	int s = max(n,q);
	BIT row0(s+1), row1(s+1), col0(s+1), col1(s+1);
	int colins[n][2], rowins[n][2];
	memset(rowins, 0, sizeof rowins);
	memset(colins, 0, sizeof colins);
	
	int t = 1;
	for(int i=0; i<q; i++){
		scanf("%s",op);
		if (strcmp(op, "RowQuery") == 0){
			int num, ans = 0;
			scanf("%d",&num);
			num--;
			if (rowins[num][1] == 0){
				ans = n - (col1.read(s) - col1.read(rowins[num][0]));
			}
			else{
				ans = col0.read(s) - col0.read(rowins[num][0]);
			}
			printf("%d\n",ans);
		}
		else if (strcmp(op, "ColQuery") == 0) {
			int num, ans = 0;
			scanf("%d",&num);
			num--;
			if (colins[num][1] == 0){
				ans = n - (row1.read(s) - row1.read(colins[num][0]));
			}
			else{
				ans = row0.read(s) - row0.read(colins[num][0]);
			}
			printf("%d\n",ans);
		}
		else if (strcmp(op, "RowSet") == 0){
			int i,x;
			scanf("%d %d",&i,&x);
			i--;
			if (rowins[i][1] == 0 && rowins[i][0] > 0)
				row0.update(rowins[i][0], -1);
			if (rowins[i][1] == 1 && rowins[i][0] > 0)
				row1.update(rowins[i][0], -1);
			rowins[i][1] = x; rowins[i][0] = t++;
			if (rowins[i][1] == 0 && rowins[i][0] > 0)
				row0.update(rowins[i][0], 1);
			if (rowins[i][1] == 1 && rowins[i][0] > 0)
				row1.update(rowins[i][0], 1);
		}
		else{
			int i,x;
			scanf("%d %d",&i,&x);
			i--;
			if (colins[i][1] == 0 && colins[i][0] > 0)
				col0.update(colins[i][0], -1);
			if (colins[i][1] == 1 && colins[i][0] > 0)
				col1.update(colins[i][0], -1);
			colins[i][1] = x; colins[i][0] = t++;
			if (colins[i][1] == 0 && colins[i][0] > 0)
				col0.update(colins[i][0], 1);
			if (colins[i][1] == 1 && colins[i][0] > 0)
				col1.update(colins[i][0], 1);
		}
	}
	return 0;
}