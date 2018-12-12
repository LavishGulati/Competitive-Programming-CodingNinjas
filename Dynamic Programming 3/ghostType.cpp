#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<ll, int> umapii;
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
#define MOD 1000000007

int main(){
    ll n;
    cin >> n;
    bool flag;

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    ll *dp = new ll[(1<<n)];
    dp[0] = 1;

    for(ll mask = 1; mask < (1<<n); mask++) dp[mask] = 0;

    for(ll mask = 0; mask < (1<<n)-1; mask++){
        for(ll i = 0; i < n; i++){
            if(!(mask&(1<<i))){
                ll x = 1+i;
                flag = true;

                for(ll j = 0; j < n; j++){
                    if(mask&(1<<j)){
                        ll y = j+1;
                        if((x&y) == x){
                            flag = false;
                            break;
                        }
                    }
                }

                if(flag){
                    dp[mask|(1<<i)] += dp[mask];
                }
            }
        }
    }

    cout << dp[(1<<n)-1] << endl;
}
