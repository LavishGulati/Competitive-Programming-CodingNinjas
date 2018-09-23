#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct worker{
    int t, x, y;

    worker(int _t, int _x, int _y){
        t = _t;
        x = _x;
        y = _y;
    }
};

vector<worker> input;

bool way(worker a, worker b){
    if(a.t == b.t){
        if(a.y == b.y){
            return a.x < b.x;
        }
        return a.y > b.y;
    }
    return a.t < b.t;
}

int main(){
    int n, x, y, t;
    ll d;
    cin >> n;
    cin >> d;

    for(int i = 0; i < n; i++){
        cin >> t >> x >> y;
        input.push_back(worker(t, x, y));
    }

    sort(input.begin(), input.end(), way);

    ll area = 0;
    ll bestSpeed = 0, cost = 0, lasTime = input[0].t;

    for(int i = 0; i < n; i++){
        ll additional = bestSpeed * 1LL * (input[i].t - lasTime);
        area += additional;
        if(area >= d) break;
        if(input[i].y > bestSpeed){
            bestSpeed = input[i].y;
            cost += input[i].x;
        }
        lasTime = input[i].t;
    }

    cout << cost << endl;
}
