#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1024

int main(){
    int n, k, x;
    cin >> n >> k >> x;

    int *input = new int[MAX];
    for(int i = 0; i < MAX; i++) input[i] = 0;

    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        input[a]++;
    }

    int *helper = new int[MAX];
    int count;
    while(k--){
        for(int i = 0; i < MAX; i++) helper[i] = 0;
        count = 0;

        for(int i = 0; i < MAX; i++){
            if(count%2 == 0){
                count += input[i];
                helper[x^i] += (input[i]+1)/2;
                input[i] -= (input[i]+1)/2;
                helper[i] += input[i];
            }
            else{
                count += input[i];
                helper[x^i] += input[i]/2;
                input[i] -= input[i]/2;
                helper[i] += input[i];
            }
        }

        for(int i = 0; i < MAX; i++) input[i] = helper[i];
    }

    for(int i = MAX-1; i >= 0; i--){
        if(input[i] > 0){
            cout << i << " ";
            break;
        }
    }
    for(int i = 0; i < MAX; i++){
        if(input[i] > 0){
            cout << i << endl;
            break;
        }
    }
}
