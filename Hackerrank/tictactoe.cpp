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

/* Complete the function below to print 2 integers separated by a single space which will be your next move 
   */

char opp(char c){
    if (c == 'X')
        return 'O';
    else
        return 'O';
}

int win(char player, vector <string> board) {
    int wincount = 0;
    
    // Test along the rows
    for(int i=0; i<3; i++) { 
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == player)
            wincount++;
    }
    
    // Test along the columns
    for(int i=0; i<3; i++) { 
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == player)
            wincount++;
    }
    
    // Test along the diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == player)
            wincount++;    
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == player)
            wincount++;
    
    return wincount;
    
}

int bestMove(char player, vector <string> board) {
    vector< pair<int,int> > moves;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (board[i][j] == '_')
                moves.push_back(make_pair(i,j));
        }
    }
    
    if (win(opp(player), board) || moves.size() == 0)
        return 0;
    
    int wincount = 0;
    for(int i=0; i<moves.size(); i++) {
        board[moves[i].first][moves[i].second] = player;
        int wins = win(player, board);
        if (wins == 0){
            for(int j=0; j<moves.size(); j++){
                if (i == j)
                    continue;
                board[moves[j].first][moves[j].second] = opp(player);
                wincount += bestMove(player, board);
            }
        }
        else{
            wincount += wins;
        }
    }
    return wincount;
}

void nextMove(char player, vector <string> board){
    vector< pair<int,int> > moves;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (board[i][j] == '_')
                moves.push_back(make_pair(i,j));
        }
    }
    
    vector<int> count(moves.size(), 0);
    int ans = -1;
    
    for(int i=0; i<moves.size(); i++) {
        board[moves[i].first][moves[i].second] = player;
        int wins = win(player, board);
        if (win == 0){
            for(int j=0; j<moves.size(); j++){
                if (i == j)
                    continue;
                board[moves[j].first][moves[j].second] = opp(player);
                count[i] += bestMove(player, board);
            }
        }
        else{
            ans = i;
            break;
        }
    }
    
    if (ans = -1){
        ans = 0;
        for(int i=1; i<count.size(); i++){
            if (count[ans] < count[i])
                ans = i;
        }
    }
    
    cout<<moves[ans].first<<" "<<moves[ans].second<<endl;
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
