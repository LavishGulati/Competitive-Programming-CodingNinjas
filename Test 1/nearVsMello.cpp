#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int *h = new int[n];
    for(int i = 0; i < n; i++) cin >> h[i];

    sort(h, h+n);
    int total = 0;
    for(int i = 0; i < n-2; i++){
        total += h[n-2]-h[i];
    }

    cout << total << endl;
}
