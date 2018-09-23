#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll *calorie = new ll[n];
    for(ll i = 0; i < n; i++) cin >> calorie[i];

    sort(calorie, calorie+n);

    ll multiplier = 1;
    ll distance = 0;
    for(ll i = n-1; i >= 0; i--){
        distance += multiplier*calorie[i];
        multiplier *= 2;
    }

    cout << distance << endl;
}
