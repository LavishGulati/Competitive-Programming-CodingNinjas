#include <bits/stdc++.h>
using namespace std;

int squareBrackets(int id, int numOpen, int *input, int n, int **dp){
    int numClose = id-numOpen;

    if(id == n){
        if(numOpen == numClose) return 1;
        else return 0;
    }

    if(dp[id][numOpen] != -1) return dp[id][numOpen];

    if(numOpen-numClose > n-id) return 0;
    if(numClose > numOpen) return 0;

    if(id == input[0]){
        int answer = squareBrackets(id+1, numOpen+1, input+1, n, dp);
        dp[id][numOpen] = answer;
        return answer;
    }

    if(numOpen == numClose){
        int answer = squareBrackets(id+1, numOpen+1, input, n, dp);
        dp[id][numOpen] = answer;
        return answer;
    }

    if(numOpen-numClose == n-id){
        int answer = squareBrackets(id+1, numOpen, input, n, dp);
        dp[id][numOpen] = answer;
        return answer;
    }

    int a = squareBrackets(id+1, numOpen+1, input, n, dp);
    int b = squareBrackets(id+1, numOpen, input, n, dp);
    dp[id][numOpen] = a+b;
    return a+b;
}

int main(){
    int d;
    cin >> d;
    while(d--){
        int n, k;
        cin >> n >> k;

        int *input = new int[k];
        int x;
        for(int i = 0; i < k; i++){
            cin >> x;
            input[i] = x-1;
        }

        sort(input, input+k);
        int **dp = new int *[2*n+1];
        for(int i = 0; i <= 2*n; i++){
            dp[i] = new int[2*n+1];
            for(int j = 0; j <= 2*n; j++) dp[i][j] = -1;
        }

        if(input[0] < 0 || input[k-1] >= 2*n){
            cout << 0 << endl;
            continue;
        }

        cout << squareBrackets(0, 0, input, 2*n, dp) << endl;
    }
}
