#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>

using namespace std;

vector< vector<int> > matrix;

int numDigits(int c) {
	if (c < 10)
		return 1;
	else return 2;
}

int main() {
	int n;
	string inp;
	getline(cin, inp);
	stringstream fss(inp);
	fss>>n;

	for(int i = 1; i <= n; i++) {
		int r, c;
		string tokens;
		getline(cin, inp);
		stringstream ss(inp);
		ss>>r>>c;
		int len = numDigits(r)+1+numDigits(c)+1;
		tokens = inp.substr(len);

		matrix.clear();
		matrix.resize(r, vector<int>(c, -1));

		string final;

		for(int j = 0; j < tokens.size(); j++) {
			int cvalue;
			if (tokens[j] == ' ')
				cvalue = 0;
			else
				cvalue = tokens[j]-'A'+1;
			bitset<5> bit(cvalue);
			final += bit.to_string();
		}
		final.resize(r*c, '0');

		int x = 0, y = -1;
		int index = 0;
		int dir = 0;

		while(index < final.size()) {
			if (dir == 0) {
				y++;
				matrix[x][y] = final[index++] - '0';
				if (y == c-1)
					dir++;
				else if (matrix[x][y+1] != -1)
					dir++;
			}
			else if (dir == 1) {
				x++;
				matrix[x][y] = final[index++] - '0';
				if (x == r-1)
					dir++;
				else if (matrix[x+1][y] != -1)
					dir++;

			}
			else if (dir == 2) {
				y--;
				matrix[x][y] = final[index++] - '0';
				if (y == 0)
					dir++;
				else if (matrix[x][y-1] != -1)
					dir++;
			}
			else if (dir == 3) {
				x--;
				matrix[x][y] = final[index++] - '0';
				if (x == 0)
					dir = 0;
				else if (matrix[x-1][y] != -1)
					dir = 0;
			}
		}

		string output;

		for(int k = 0; k < r; k++)
			for(int j = 0; j < c; j++) {
				output.push_back('0'+matrix[k][j]);
			}


		cout<<i<<" "<<output<<endl;
	}

	return 0;
}