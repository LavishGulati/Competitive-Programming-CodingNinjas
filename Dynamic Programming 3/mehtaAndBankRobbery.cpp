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
typedef pair<long long, long long> pll;

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

int main(){
    ll n, w;
    cin >> n >> w;

    ll primes[10] = {2,3,5,7,11,13,17,19,23,29};

    pll *input = new pll[n];
    for(ll i = 0; i < n; i++) cin >> input[i].f >> input[i].s;

    sort(input, input+n);

    ll dp[11][2][w+1];
    for(ll p = 0; p <= 10; p++){
        for(ll j = 0; j <= w; j++){
            dp[p][0][j] = 0;
            dp[p][1][j] = 0;
        }
    }

    ll id = 1;
    for(ll i = 1; i <= n; i++){
        for(ll p = 0; p <= 10; p++){
            for(ll j = 0; j <= w; j++){
                dp[p][id][j] = dp[p][1^id][j];
                if(j >= input[i-1].s){
                    dp[p][id][j] = max(dp[p][id][j], dp[p][1^id][j-input[i-1].s] + input[i-1].f);
                    if(p >= 1) dp[p][id][j] = max(dp[p][id][j], dp[p-1][1^id][j-input[i-1].s] + primes[p-1]*(input[i-1].f));
                }
            }
        }

        id = 1^id;
    }

    cout << dp[10][1^id][w] << endl;
}
