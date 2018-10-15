#include <bits/stdc++.h>
using namespace std;

class point{
public:
    double x, y;
};

double distance(point a, point b){
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

double findWidth(point a, point b){
    if(a.x == b.x) return abs(a.y - b.y);

    double x1 = a.x; double y1 = a.y;
    double x2 = b.x; double y2 = b.y;
    double p1 = ((y2-y1)*y1)/(x2-x1) + x1;
    double p2 = ((y2-y1)*y2)/(x2-x1) + x2;
    double slope = (y2-y1)/(x2-x1);

    double width = 0;
    if(slope > 0){
        width += y1-y2;
        width += y1*x2/(x1-200);
        width -= y1*x1/(x1-200);
        width = abs(width);
        width /= sqrt(1 + (y1/(x1-200))*(y1/(x1-200)));
        return width;
    }
    else{
        width += y2-y1;
        width += ((y2-200)*x1)/(x2-200);
        width -= ((y2-200)*x2)/(x2-200);
        width = abs(width);
        width /= sqrt(1 + ((y2-200)*(y2-200))/((x2-200)*(x2-200)));
        return width;
    }

    return distance(a, b);
}

int main(){
    int n;
    cin >> n;
    point *polygon = new point[n];
    for(int i = 0; i < n; i++) cin >> polygon[i].x;
    for(int i = 0; i < n; i++) cin >> polygon[i].y;

    double maxWidth = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            double possibleWidth = findWidth(polygon[i], polygon[j]);
            cout << possibleWidth << endl;
            if(possibleWidth > maxWidth) maxWidth = possibleWidth;
        }
    }

    if(floor(maxWidth) == maxWidth) maxWidth -= 1;
    cout << floor(maxWidth) << endl;
}
