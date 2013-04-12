#include<iostream>
#include<vector>
using namespace std;
/* Head ends here */
void nextMove( string player, int posx, int posy, vector <string> board) {
    //add logic here
    int l = -1, r = -1;
    char move = 'H';
    for(int i = 0; i < posx; i++) {
        for(int j = 0; j < posy; j++) {
            if (board[i][j] != '-')
                continue;
            // search horizontally
            if (j+1 < posy && board[i][j+1] == '-') {
                l = i; r = j; move = 'H';
                //goto end; 
            }
            // search vertically
            if (i+1 < posx && board[i+1][j] == '-') {
                l = i; r = j; move = 'V';
                //goto end; 
            }
        }
    }
    end:
    cout<<l<<" "<<r<<" "<<move<<endl;
}
/* Tail starts here */
int main() {
    int pos[2];
    vector <string> board;
    string player;
    cin >> player;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<pos[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    nextMove( player, pos[0], pos[1], board);
    return 0;
}