#include <bits/stdc++.h>
using namespace std;

int minSalary(int *assistant, int *captain, int n, int x, int **memo){
    if(n == 0) return 0;

    if(memo[n][x] != -1) return memo[n][x];

    if(x == 0){
        int answer = assistant[0]+minSalary(assistant+1, captain+1, n-1, x+1, memo);
        memo[n][x] = answer;
        return answer;
    }
    else if(x == n){
        int answer = captain[0]+minSalary(assistant+1, captain+1, n-1, x-1, memo);
        memo[n][x] = answer;
        return answer;
    }
    else{
        int a = assistant[0]+minSalary(assistant+1, captain+1, n-1, x+1, memo);
        int b = captain[0]+minSalary(assistant+1, captain+1, n-1, x-1, memo);
        int answer = min(a, b);
        memo[n][x] = answer;
        return answer;
    }
}

int main(){
    int n;
    cin >> n;

    int *captain = new int[n];
    int *assistant = new int[n];
    for(int i = 0; i < n; i++){
        cin >> captain[i] >> assistant[i];
    }

    int **memo = new int *[n+1];
    for(int i = 0; i <= n; i++){
        memo[i] = new int[(n/2)+1];
        for(int j = 0; j <= n/2; j++) memo[i][j] = -1;
    }

    cout << minSalary(assistant, captain, n, 0, memo) << endl;
}
