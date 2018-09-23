#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool compare(pii a, pii b){
    return a.first < b.first;
}

int main(){
    int n, total, finishTime, i;
    cin >> n;

    pair<int, int> *activityTime = new pair<int, int>[n];
    for(i = 0; i < n; i++){
        cin >> activityTime[i].second;
        cin >> activityTime[i].first;
    }

    sort(activityTime, activityTime+n, compare);

    total = 1;
    finishTime = activityTime[0].first;
    for(i = 1; i < n; i++){
        if(activityTime[i].second >= finishTime){
            total++;
            finishTime = activityTime[i].first;
        }
    }

    cout << total << endl;
}
