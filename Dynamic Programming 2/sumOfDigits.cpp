#include <bits/stdc++.h>
using namespace std;
#define MAX 10000001
typedef long long ll;

ll numDigits(ll x){
    ll num = 0;
    while(x != 0){
        num++;
        x /= 10;
    }
    return num-1;
}

ll sumOfDigits(ll x, unordered_map<ll, ll> &m){
    if(m.find(x) != m.end()) return m[x];

    ll n = numDigits(x);
    ll p = pow(10, n);
    ll a = x/p;
    ll sum = p*a*(a-1)/2 + a*((x%p)+1) + sumOfDigits(x%p, m) + a*sumOfDigits(p-1, m);
    m[x] = sum;
    return sum;
}

int main(){
    unordered_map<ll, ll> m;
    m[0] = 0;
    m[1] = 1;
    m[2] = 3;
    m[3] = 6;
    m[4] = 10;
    m[5] = 15;
    m[6] = 21;
    m[7] = 28;
    m[8] = 36;
    m[9] = 45;

    ll a, b;
    while(1){
        cin >> a >> b;
        if(a == -1 && b == -1) break;

        if(b == 0) b = 1;
        if(a == 0) a = 1;

        cout << sumOfDigits(b, m)-sumOfDigits(a-1, m) << endl;
    }
}
