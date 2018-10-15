#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 10000000000

int main(){
    ll n;
    cin >> n;

    double total = 0;
    ll x;
    for(ll i = 0; i < n; i++){
        cin >> x;
        total += log(x);
    }

    ll start = 1;
    ll end = MAX;
    ll answer, mid;
    while(start <= end){
        mid = (start+end)/2;

        if(n*log(mid) > total){
            end = mid-1;
            answer = mid;
        }
        else{
            start = mid+1;
        }
    }

    cout << answer << endl;
}
