#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class point{
public:
    ll x, y;
};

ll areaTriangle(point a, point b, point c){
    ll x1 = b.x-a.x;
    ll y1 = b.y-a.y;
    ll x2 = c.x-a.x;
    ll y2 = c.y-a.y;

    return x1*y2-x2*y1;
}

int main(){
    string direction;
    cin >> direction;

    int n = direction.length();
    ll *length = new ll[n];
    for(int i = 0; i < n; i++) cin >> length[i];

    point *polygon = new point[n];
    polygon[0].x = 0; polygon[0].y = 0;
    for(int i = 0; i < n-1; i++){
        if(direction[i] == 'N'){
            polygon[i+1].x = polygon[i].x;
            polygon[i+1].y = polygon[i].y + length[i];
        }
        else if(direction[i] == 'S'){
            polygon[i+1].x = polygon[i].x;
            polygon[i+1].y = polygon[i].y - length[i];
        }
        else if(direction[i] == 'E'){
            polygon[i+1].x = polygon[i].x + length[i];
            polygon[i+1].y = polygon[i].y;
        }
        else{
            polygon[i+1].x = polygon[i].x - length[i];
            polygon[i+1].y = polygon[i].y;
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout << polygon[i].x << " " << polygon[i].y << endl;
    // }

    ll area = 0;
    for(ll i = 1; i < n-1; i++){
        area += areaTriangle(polygon[0], polygon[i], polygon[i+1]);
    }
    area = abs(area)/2;
    cout << area << endl;
}
