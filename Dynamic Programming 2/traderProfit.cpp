#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second

int maxProfit(int *input, int id, int n, int k, bool buy, pii **memo){
    if(k == 0 || id == n) return 0;

    if(buy){
        if(memo[id][k].f != -1) return memo[id][k].f;
    }
    else{
        if(memo[id][k].s != -1) return memo[id][k].s;
    }

    if(buy){
        int a = maxProfit(input, id+1, n, k, false, memo)-input[id];
        int b = maxProfit(input, id+1, n, k, true, memo);
        memo[id][k].f = max(a, b);
        return max(a, b);
    }
    else{
        int a = input[id]+maxProfit(input, id+1, n, k-1, true, memo);
        int b = maxProfit(input, id+1, n, k, false, memo);
        memo[id][k].s = max(a, b);
        return max(a, b);
    }
}

int main(){
    int q;
    cin >> q;
    while(q--){
        int k, n;
        cin >> k >> n;

        int *input = new int[n];
        for(int i = 0; i < n; i++) cin >> input[i];

        pii **memo = new pii *[n+1];
        for(int i = 0; i <= n; i++){
            memo[i] = new pii[k+1];
            for(int j = 0; j <= k; j++){
                memo[i][j].f = -1;
                memo[i][j].s = -1;
            }
        }

        cout << maxProfit(input, 0, n, k, true, memo) << endl;
    }
}
