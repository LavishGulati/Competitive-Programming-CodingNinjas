#include <bits/stdc++.h>
using namespace std;

int grundy(int n){
    if(n == 0) return 0;

    int a = grundy(n/2);
    int b = grundy(n/3);
    int c = grundy(n/6);

    for(int i = 0; ; i++){
        if(i != a && i != b && i != c) return i;
    }
}

int main(){
    int n;
    cin >> n;
    cout << grundy(n) << endl;
}
