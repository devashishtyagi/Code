#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int magic[] = {8,3,4,1,5,9,6,7,2};
int rmagic[] = {3,8,1,2,4,6,7,0,5};

char opp(char c){
    if (c == 'X')
        return 'O';
    else
        return 'X';
}

int makeWin(char player, vector<string> board, vector<int> moves) {
    int move = -1;

    for(int i=0; i<moves.size() && move == -1; i++){
      for(int j=0; j<moves.size() && move == -1; j++){
		// Not a valid collinear move
		if (i == j)
			continue;
		int place = 15-moves[i]-moves[j];
		// Not a collinear move
		if (place <= 0 || place > 9 || place == moves[i] || place == moves[j])
			continue;
		
		place = rmagic[place-1];
		if (board[place/3][place%3] == '_')
		move = place;
      }
    }
    return move;
}

int makeTwo(char player, vector<string> board) {
	if (board[1][1] == '_')
		return 4;
	else{
		vector<int> wincount(9,0);
		vector<int> blockcount(9,0);
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if (i == j || board[i/3][i%3] != '_' || board[j/3][j%3] != '_')
					continue;
				int place = 15-magic[i]-magic[j];
				// Not a collinear move
				if (place <= 0 || place > 9 || place == magic[i] || place == magic[j])
					continue;
				place = rmagic[place-1];
				// Count in how many ways this move can result in win position
				if (board[place/3][place%3] == player || board[place/3][place%3] == '_')
					wincount[i]++;
				// Count in how many ways this move can result in block position
				if (board[place/3][place%3] == opp(player) || board[place/3][place%3] == '_')
					blockcount[i]++;
			}
		}
		int move = -1;
		for(int i=0; i<9; i++){
			if (move == -1){
				if (board[i/3][i%3] == '_')
					move = i;
			}
			else{
				if (wincount[i] > wincount[move])
					move = i;
				else if (wincount[i] == wincount[move] && blockcount[i] > blockcount[move])
					move = i;
			}	
		}
		return move;
	}
}

/* Complete the function below to print 2 integers separated by a single space which will be your next move 
   */
void nextMove(char player, vector <string> board){
	vector<int> pmoves, omoves;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if (board[i][j] == player)
				pmoves.push_back(magic[i*3+j]);
			else if (board[i][j] == opp(player))
				omoves.push_back(magic[i*3+j]);
		}
	}
	int move = makeWin(player, board, pmoves);
	if (move == -1){
		move = makeWin(opp(player), board, omoves);
		if (move == -1)
			move = makeTwo(player, board);
	}
	cout<<move/3<<" "<<move%3<<endl;
}

int main() {

    char player;
    vector <string> board;

    //If player is X, I'm the first player.
    //If player is O, I'm the second player.
    cin >> player;

    //Read the board now. The board is a 3x3 array filled with X, O or _.
    for(int i=0; i<3; i++) {
		string s; cin >> s;
		board.push_back(s);
    }

	nextMove(player,board);

    return 0;
}
