#include <bits/stdc++.h>
using namespace std;

bool isMovesLeft(char **board){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == '_') return true;
        }
    }

    return false;
}

int evaluate(char **board){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if(board[i][0] == 'x') return 10;
            else if(board[i][0] == 'o') return -10;
        }
    }

    for(int j = 0; j < 3; j++){
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]){
            if(board[0][j] == 'x') return 10;
            else if(board[0][j] == 'o') return -10;
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if(board[0][0] == 'x') return 10;
        else if(board[0][0] == 'o') return -10;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[1][1] == 'x') return 10;
        else if(board[1][1] == 'o') return -10;
    }

    return 0;
}

int minimax(char **board, int depth, bool isMax){
    int score = evaluate(board);

    if(score == 10) return score;
    else if(score == -10) return score;

    if(!isMovesLeft(board)) return 0;

    if(isMax){
        int maxScore = INT_MIN;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == '_'){
                    board[i][j] = 'x';
                    maxScore = max(maxScore, minimax(board, depth+1, !isMax));
                    board[i][j] = '_';
                }
            }
        }

        return maxScore;
    }
    else{
        int minScore = INT_MAX;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == '_'){
                    board[i][j] = 'o';
                    minScore = min(minScore, minimax(board, depth+1, !isMax));
                    board[i][j] = '_';
                }
            }
        }

        return minScore;
    }
}

void findBestMove(char **board){
    int maxScore = INT_MIN;
    int row = -1;
    int col = -1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == '_'){
                board[i][j] = 'x';
                int moveScore = minimax(board, 0, false);
                board[i][j] = '_';

                if(moveScore > maxScore){
                    row = i;
                    col = j;
                    maxScore = moveScore;
                }
            }
        }
    }

    // cout << row << " " << col << endl;
    cout << maxScore << " row: " << row << " col: " << col << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        char **board = new char *[3];
        for(int i = 0; i < 3; i++){
            board[i] = new char[3];
            for(int j = 0; j < 3; j++) cin >> board[i][j];
        }

        findBestMove(board);
    }
}
