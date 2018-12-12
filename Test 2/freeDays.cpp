#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

// 0 means rest
// 1 means sports complex
// 2 means contest
int main(){
    int n;
    cin >> n;

    int *input = new int [n];
    for(int i = 0; i < n; i++) cin >> input[i];

    int **dp = new int *[n];
    for(int i = 0; i < n; i++){
        dp[i] = new int[3];
        for(int j = 0; j < 3; j++) dp[i][j] = 101;
    }

    if(input[0] == 0){
        dp[0][0] = 1;
    }
    else if(input[0] == 1){
        dp[0][0] = 1;
        dp[0][2] = 0;
    }
    else if(input[0] == 2){
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    else{
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 0;
    }

    for(int i = 1; i < n; i++){
        if(input[i] == 0){
            for(int j = 0; j < 3; j++) dp[i][0] = min(dp[i-1][j]+1, dp[i][0]);
        }
        else if(input[i] == 1){
            for(int j = 0; j < 3; j++) dp[i][0] = min(dp[i-1][j]+1, dp[i][0]);
            for(int j = 0; j < 3; j++){
                if(j == 2) continue;
                dp[i][2] = min(dp[i][2], dp[i-1][j]);
            }
        }
        else if(input[i] == 2){
            for(int j = 0; j < 3; j++) dp[i][0] = min(dp[i-1][j]+1, dp[i][0]);
            for(int j = 0; j < 3; j++){
                if(j == 1) continue;
                dp[i][1] = min(dp[i][1], dp[i-1][j]);
            }
        }
        else{
            for(int j = 0; j < 3; j++) dp[i][0] = min(dp[i-1][j]+1, dp[i][0]);
            for(int j = 0; j < 3; j++){
                if(j == 2) continue;
                dp[i][2] = min(dp[i][2], dp[i-1][j]);
            }
            for(int j = 0; j < 3; j++){
                if(j == 1) continue;
                dp[i][1] = min(dp[i][1], dp[i-1][j]);
            }
        }
    }

    int minRest = 101;
    for(int i = 0; i < 3; i++) minRest = min(minRest, dp[n-1][i]);
    cout << minRest << endl;
}
