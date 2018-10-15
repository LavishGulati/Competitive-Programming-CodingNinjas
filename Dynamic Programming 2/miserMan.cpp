#include <bits/stdc++.h>
using namespace std;

int findFare(int **input, int n, int m, int row, int col, int **dp){
    if(row == n) return 0;

    if(dp[row][col] != -1) return dp[row][col];

    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if(col-1 >= 0) a = input[row][col]+findFare(input, n, m, row+1, col-1, dp);
    b = input[row][col]+findFare(input, n, m, row+1, col, dp);
    if(col+1 < m) c = input[row][col]+findFare(input, n, m, row+1, col+1, dp);

    dp[row][col] = min(a, min(b, c));
    return min(a, min(b, c));
}

int main(){
    int n, m;
    cin >> n >> m;

    int **input = new int *[n];
    for(int i = 0; i < n; i++){
        input[i] = new int[m];
        for(int j = 0; j < m; j++) cin >> input[i][j];
    }

    int **dp = new int *[n];
    for(int i = 0; i < n; i++) dp[i] = new int[m];

    int minFare = INT_MAX;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++) dp[j][k] = -1;
        }

        minFare = min(minFare, findFare(input, n, m, 0, i, dp));
    }

    cout << minFare << endl;
}
