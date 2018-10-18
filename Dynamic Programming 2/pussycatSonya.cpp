#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define MAX 100001

ll A[MAX], dp[105][1005], prefix[MAX], best[1001];
int main(){
    ll n, m, length, i, j, k;
    cin >> n >> m;

    for(i = 0; i <= n; i++){
        for(j = 0; j <= m; j++) dp[i][j] = 0;
    }

    for(k = 1; k <= n; k++){
        cin >> length;
        for(i = 0; i < length; i++) cin >> A[i];
        prefix[0] = 0;

        for(i = 0; i < length; i++){
            prefix[i+1] = prefix[i]+A[i];
        }
        for(i = 1; i <= m; i++) best[i] = INT_MIN;
        best[0] = 0;
        for(i = 1; i <= length; i++){
            for(j = i; j < i+m && j <= length; j++){
                best[j-i+1] = max(best[j-i+1], prefix[j]-prefix[i-1]);
            }
        }

        for(j = 0; j <= m; j++){
            for(ll take = 0; j+take <= m; take++){
                dp[k][j+take] = max(dp[k][j+take], dp[k-1][j]+best[take]);
            }
        }
    }

    cout << dp[n][m] << endl;
}
