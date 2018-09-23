#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 4294967296

int main(){
    ll n, M, a, b;
    cin >> n >> M >> a >> b;

    ll *profit = new ll[n+1];
    ll x = 0;
    profit[0] = 0;

    for(ll i = 1; i <= n; i++){
        x = ((x%M)*a+b)%MOD;
        profit[i] = x>>8;
    }

    ll maxProfit = 0-profit[1];
    for(ll i = 2; i <= n; i++){
        if(profit[i] < profit[i-1]){
            maxProfit = maxProfit+profit[i-1]-profit[i];
        }
    }

    maxProfit += profit[n];
    cout << maxProfit << endl;
}
