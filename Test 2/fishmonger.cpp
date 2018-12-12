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

int memo[101][1001];

ll calculateMinToll(ll **time1, ll **toll, bool *isVisited, ll n, ll currCity, ll t){
    if(memo[currCity][t] != -1) return memo[currCity][t];

    if(t < 0){
        memo[currCity][t] = INT_MAX;
        return INT_MAX;
    }

    if(currCity == n-1){
        memo[currCity][t] = 0;
        return 0;
    }

    isVisited[currCity] = true;
    ll minToll = INT_MAX;
    for(ll i = 0; i < n; i++){
        if(i == currCity) continue;
        if(!isVisited[i]){
            ll x = calculateMinToll(time1, toll, isVisited, n, i, t-time1[currCity][i]);
            x += toll[currCity][i];
            minToll = min(x, minToll);
        }
    }

    isVisited[currCity] = false;
    memo[currCity][t] = minToll;
    return minToll;
}

int main(){
    ll n, t;
    cin >> n >> t;

    ll **time1 = new ll *[n];
    for(ll i = 0; i < n; i++){
        time1[i] = new ll[n];
        for(ll j = 0; j < n; j++) cin >> time1[i][j];
    }

    ll **toll = new ll *[n];
    for(ll i = 0; i < n; i++){
        toll[i] = new ll[n];
        for(ll j = 0; j < n; j++) cin >> toll[i][j];
    }

    bool *isVisited = new bool[n];
    for(ll i = 0; i < n; i++) isVisited[i] = false;

    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 1001; j++) memo[i][j] = -1;
    }

    cout << calculateMinToll(time1, toll, isVisited, n, 0, t) << endl;
}
