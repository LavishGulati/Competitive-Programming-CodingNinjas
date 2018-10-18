#include <bits/stdc++.h>
using namespace std;

class point{
public:
    int x, y;

    point(){

    }

    point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int main(){
    int n, q, c;
    cin >> n >> q >> c;

    point *star = new point[n];
    int *brightness = new int[n];
    for(int i = 0; i < n; i++){
        cin >> star[i].x >> star[i].y >> brightness[i];
    }

    while(q--){
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;

        int total = 0;
        for(int i = 0; i < n; i++){
            if(star[i].x >= min(x1, x2) && star[i].x <= max(x1, x2) && star[i].y >= min(y1, y2) && star[i].y <= max(y1, y2)){
                total += (brightness[i]+t)%(c+1);
            }
        }

        cout << total << endl;
    }
}
