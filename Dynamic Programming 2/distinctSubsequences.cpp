#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();

        int *occurence = new int[256];
        for(int i = 0; i < 256; i++) occurence[i] = -1;

        int *dp = new int[n+1];
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i] = (2*dp[i-1])%MOD;
            if(occurence[s[i-1]] != -1){
                dp[i] = (dp[i]-dp[occurence[s[i-1]]]+MOD)%MOD;
            }
            occurence[s[i-1]] = i-1;
        }

        cout << dp[n] << endl;
    }
}
