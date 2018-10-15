#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();

        int countR = 0, countK = 0;
        int totalR = 0, totalK = 0, maxR;
        int i, j;
        for(i = 0; i < n; i++){
            if(s[i] == 'R') totalR++;
            else totalK++;
        }

        if(totalK == 0){
            cout << totalR-1 << endl;
            continue;
        }

        maxR = totalR; i = 0; j = 0;

        while(i < n){
            while(j < n && countK-countR >= 0){
                if(s[j] == 'K') countK++;
                else countR++;

                if(totalR-countR+countK > maxR){
                    maxR = totalR-countR+countK;
                }

                j++;
            }

            if(s[i] == 'K') countK--;
            else countR--;

            i++;
        }

        cout << maxR << endl;
    }
}
