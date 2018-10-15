#include <bits/stdc++.h>
using namespace std;

class point{
public:
    int x, y;
};

bool toChange(point p, point q, point r){
    int x1 = q.x-p.x;
    int y1 = q.y-p.y;
    int x2 = r.x-q.x;
    int y2 = r.y-q.y;

    int value = x1*y2-y1*x2;
    return value < 0;
}

void convexHull(point *polygon, int n){
    int leftMost = 0;
    for(int i = 1; i < n; i++){
        if(polygon[leftMost].x > polygon[i].x) leftMost = i;
    }

    int p = leftMost;
    do{
        cout << polygon[p].x << " " << polygon[p].y << endl;
        int q = (p+1)%n;

        for(int i = 0; i < n; i++){
            if(toChange(polygon[p], polygon[q], polygon[i])){
                q = i;
            }
        }

        p = q;
    } while(p != leftMost);
}

int main(){
    int n;
    cin >> n;

    point *polygon = new point[n];
    for(int i = 0; i < n; i++) cin >> polygon[i].x;
    for(int i = 0; i < n; i++) cin >> polygon[i].y;

    convexHull(polygon, n);
}
