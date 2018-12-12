#include<bits/stdc++.h>
using namespace std;
#define MAXN 16

typedef long long ll;

long long solve(int like[][MAXN],int n){
    ll *dp = new ll[(1<<n)];
    dp[(1<<n)-1] = 1;

    for(ll mask = (1<<n)-2; mask >= 0; mask--){
        ll temp = mask;
        ll person = 0;
        while(temp > 0){
            person += temp&1;
            temp /= 2;
        }

        for(ll i = 0; i < n; i++){
            if(like[person][i] && !(mask&(1<<i))){
                dp[mask] += dp[mask|(1<<i)];
            }
        }
    }

    return dp[0];
}

int main()
{
	int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	cout<<solve(like,n)<<endl;
}
