#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Head ends here */

char opp(char player){
	switch(player){
		case 'W': return 'B';
		case 'B': return 'W';
		default: return 'W';
	}
}

pair<int,int> up(int i, int j, vector <string> board){
	if (i == 0)
		return make_pair(-1,-1);
	i--;
	while(i >= 0){
		if (board[i][j] == '|')
			i--;
		else
			return make_pair(i,j);
	}
}

pair<int,int> down(int i, int j, vector <string> board){
	if (i == 6)
		return make_pair(-1,-1);
	i++;
	while(i >= 0){
		if (board[i][j] == '|')
			i++;
		else
			return make_pair(i,j);
	}
}

pair<int,int> left(int i, int j, vector <string> board){
	if (j == 0)
		return make_pair(-1,-1);
	j--;
	while(j >= 0){
		if (board[i][j] == '|')
			j--;
		else
			return make_pair(i,j);
	}
}

pair<int,int> right(int i, int j, vector <string> board){
	if (j == 6)
		return make_pair(-1,-1);
	j++;
	while(j >= 0){
		if (board[i][j] == '|')
			j++;
		else
			return make_pair(i,j);
	}
}

isMill(int i, int j, char player, vector<string> board){
	
}

void nextMove(char player, string move, vector <string> board){
    //your logic here
    srand ( time(NULL) );
    if (move == "INIT"){
		vector< pair<int,int> > positions;
		for(int i=0; i<board.size(); i++){
			for(int j=0; j<board[i].size(); j++){
				if (board[i][j] == 'O'){
					positions.push_back(make_pair(i,j));
				}
			}
		}
		int pos = rand()%positions.size();
		cout<<positions[pos].first<<" "<<positions[pos].second<<endl;
	}
	else if (move == "MILL"){
		vector< pair<int,int> > positions;
		vector< pair<int,int> > millpos;
		for(int i=0; i<board.size(); i++){
			for(int j=0; j<board[i].size(); j++){
				if (board[i][j] == opp(player)){
					positions.push_back(make_pair(i,j));
				}
				if (board[i][j] == opp(player) && isMill(i,j,opp(player),board)){
					millpos.push_back(make_pair(i,j));
				}
			}
		}
		int pos;
		if (millpos.size() > 0){
			pos = rand()%millpos.size();
			cout<<millpos[pos].first<<" "<<millpos[pos].second<<endl;
		}
		else{
			pos = rand()%positions.size();
			cout<<positions[pos].first<<" "<<positions[pos].second<<endl;
		}
	}
	else{
		for(int i=0; i<board.size(); i++){
			for(int j=0; j<board[i].size(); j++){
				
			}
		}	
	}
}
/* Tail starts here */
int main() {

    char player;
    string move;
    vector <string> board;

    cin >> player;
    cin >> move;
    for(int i=0; i<7; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    nextMove(player, move, board);

    return 0;
}