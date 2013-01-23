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

using namespace std;
typedef long long ll;

int pow_10[9];
bool valid[10][10];
string S,M,R;

int solve(int, int);
int update(int, int, int);

void init(){
	pow_10[0] = 1;
	for(int i=1; i<9; i++){
		pow_10[i] = pow_10[i-1]*10;
	}
	memset(valid, false, sizeof valid);
	
	valid[0][8] = true;valid[1][0] = true;valid[1][3] = true;	valid[1][4] = true;valid[1][7] = true;	valid[1][8] = true;
	valid[1][9] = true;	valid[2][8] = true;	valid[3][8] = true;	valid[3][9] = true;	valid[4][8] = true;	valid[4][9] = true;
	valid[5][6] = true;	valid[5][8] = true;	valid[5][9] = true;	valid[6][8] = true;	valid[7][0] = true;	valid[7][3] = true;
	valid[7][8] = true;	valid[7][9] = true;	valid[9][8] = true;
}

bool convert(char i, int j){
	if (i == 'X' || i-'0' == j)
		return true;
	else{
		return valid[i-'0'][j];
	}
}

int convertString(string s)
{
    int num;
    stringstream sstr(s); // create a stringstream
    sstr>>num; // push the stream into the num
    return num;
}


int solve(){
	int prefix_equal = 0, prefix_less = -1;
	for(int i = 0; i < M.size(); i++){
		if (prefix_less == -1 && prefix_equal == -1)
			return -1;
		int new_prefix_equal = -1, new_prefix_less = -1;
		for(int j=9; j>=0; j--){
			if (!convert(R[i],j))
				continue;
			if (j < M[i]-'0'){
				if (prefix_equal != -1)
					new_prefix_less = max(prefix_equal*10+j, new_prefix_less);
				if (prefix_less != -1)
					new_prefix_less = max(prefix_less*10+j, new_prefix_less);
			}
			else if (j > M[i]-'0'){
				if (prefix_less != -1)
					new_prefix_less = max(prefix_less*10+j, new_prefix_less);
			}
			else{
				if (prefix_equal != -1)
					new_prefix_equal = prefix_equal*10 + j;
			}
		}
		prefix_equal = new_prefix_equal;
		prefix_less = new_prefix_less;
	}
	return max(prefix_equal, prefix_less);
}

int main()
{
	init();
	int t;
	cin>>t;
	
	while(t--){
		cin>>S>>M;
		int ans = convertString(S);
		int diff = M.size() - S.size();
		for(int i = 0; i <= diff; i++){
			R.clear();
			for(int j=0; j<i; j++)
				R.push_back('X');
			R.append(S);
			for(int j=0; j<(diff-i); j++)
				R.push_back('X');
			ans = max(ans, solve());
		}
		cout<<ans<<endl;
	}
	return 0;
}
