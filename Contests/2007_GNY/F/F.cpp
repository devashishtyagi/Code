#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>

using namespace std;

void print_matrix(vector< vector<char> > &m, int r, int c) {
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			cout<<m[i][j]<<" ";
		cout<<endl;
	}
}

int main() {
	int n;
	cin>>n;

	for(int k = 1; k <= n; k++) {
		int r, c;
		string encode;
		cin>>r>>c>>encode;

		vector< vector<char> > matrix(r, vector<char>(c));
		vector< vector<bool> > visited(r, vector<bool>(c, false));

		for(int i = 0; i < r; i++) 
			for(int j = 0; j < c; j++)
				matrix[i][j] = encode[i*c+j];

		string tokens; 

		int x = 0, y = -1;
		int dir = 0;
		
		while(tokens.size() < r*c) {
			if (dir == 0) {
				y++;
				tokens.push_back(matrix[x][y]);
				visited[x][y] = true;
				if (y == c-1)
					dir++;
				else if (visited[x][y+1])
					dir++;
			}
			else if (dir == 1) {
				x++;
				//cout<<x<<" "<<y<<" "<<matrix[x][y]<<endl;
				tokens.push_back(matrix[x][y]);
				visited[x][y] = true;
				if (x == r-1)
					dir++;
				else if (visited[x+1][y])
					dir++;

			}
			else if (dir == 2) {
				y--;
				tokens.push_back(matrix[x][y]);
				visited[x][y] = true;
				if (y == 0)
					dir++;
				else if (visited[x][y-1])
					dir++;
			}
			else if (dir == 3) {
				x--;
				tokens.push_back(matrix[x][y]);
				visited[x][y] = true;
				if (x == 0)
					dir = 0;
				else if (visited[x-1][y])
					dir = 0;
			}
		}

		//cout<<tokens<<endl;

		string ans;

		for(int i = 0; i < tokens.size(); i += 5) {
			if (i+5 > tokens.size())
				break;

			string token;
			for(int j = 0; j < 5; j++)
				token.push_back(tokens[i+j]);

			bitset<5> bit(token);
			if (bit.to_ulong() == 0)
				ans.push_back(' ');
			else
				ans.push_back(bit.to_ulong()-1+'A');
		}

		int index = -1;
		for(int i = ans.size()-1; i >= 0; i--) {
			if (ans[i] != ' ') {
				index = i;
				break;
			}
		}

		ans = ans.substr(0, index+1);

		cout<<k<<" "<<ans<<endl;
	}

	return 0;
}