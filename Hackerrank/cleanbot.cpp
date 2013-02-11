#include<iostream>
#include<vector>
using namespace std;

/* Head ends here */
void next_move(int posx, int posy, vector <string> board) {
    //add logic here
    if (board[posx][posy] == 'd'){
		cout<<"CLEAN"<<endl;
		return;
	}
    
	int left = 0, right = 0, up = 0, down = 0;
	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[0].size(); j++){
			if (board[i][j] == 'd'){
				if (j > posy)
					right++;
				else if(j < posy)
					left++;
				if (i > posx)
					down++;
				else if (i < posx)
					up++;
					
			}
		}
	}
	if (left != 0 || right != 0 || up != 0 || down != 0){
		int maxvalue = max(max(left,right), max(up,down));
		int i = posx, j = posy;
		if (maxvalue == left){
			cout<<"LEFT"<<endl;
		}
		else if (maxvalue == right){
			cout<<"RIGHT"<<endl;
		}
		else if (maxvalue == up){
			cout<<"UP"<<endl;
		}
		else if (maxvalue == down){
			cout<<"DOWN"<<endl;
		}
	}
	else
		return;
}

/* Tail starts here */
int main() {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}