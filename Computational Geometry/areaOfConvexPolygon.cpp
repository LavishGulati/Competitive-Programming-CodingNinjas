#include <bits/stdc++.h>
using namespace std;

class point{
public:
    double x, y;
};

point p0;

double distance(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void findMinPoint(point *polygon, int n){
    int minId = 0;
    for(int i = 1; i < n; i++){
        if(polygon[i].y < polygon[minId].y) minId = i;
        else if(polygon[i].y == polygon[minId].y && polygon[i].x < polygon[minId].x){
            minId = i;
        }
    }

    point temp = polygon[minId];
    polygon[minId] = polygon[0];
    polygon[0] = temp;
}

int orientation(point p, point q, point r){
    double val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if(val == 0) return 0;
    return val > 0 ? 1 : 2;
}

int compare(const void *ap, const void *bp){
    point *a = (point *)ap;
    point *b = (point *)bp;

    int o = orientation(p0, *a, *b);

    if(o == 0) return distance(p0, *b) >= distance(p0, *a) ? -1 : 1;

    return o == 2 ? -1 : 1;
}

void sort(point *polygon, int n){
    findMinPoint(polygon, n);
    p0 = polygon[0];

    qsort(&polygon[1], n-1, sizeof(point), compare);

}

int main(){
    int n;
    cin >> n;

    point *polygon = new point[n];
    for(int i = 0; i < n; i++){
        cin >> polygon[i].x;
    }
    for(int i = 0; i < n; i++){
        cin >> polygon[i].y;
    }

    sort(polygon, n);

    double area = 0;
    for(int i = 0; i < n-1; i++){
        area += (polygon[i].x * polygon[i+1].y) - (polygon[i].y * polygon[i+1].x);
    }
    area += (polygon[n-1].x * polygon[0].y) - (polygon[0].x * polygon[n-1].y);

    area = abs(area)/2;
    printf("%.9g\n", area);
}
