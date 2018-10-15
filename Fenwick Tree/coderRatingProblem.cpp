#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

class coder{
public:
    int index, x, y;
};

bool compare(coder c1, coder c2){
    if(c1.x == c2.x) return c1.y < c2.y;

    return c1.x < c2.x;
}

void update(int y, int *fenwick){
    for(; y < MAX; y += y&(-y)){
        fenwick[y]++;
    }
}

int query(int y, int *fenwick){
    int value = 0;
    for(; y > 0; y -= y&(-y)){
        value += fenwick[y];
    }
    return value;
}

int main(){
    int n;
    cin >> n;

    coder *input = new coder[n];
    for(int i = 0; i < n; i++){
        cin >> input[i].x >> input[i].y;
        input[i].index = i;
    }

    sort(input, input+n, compare);

    int *solution = new int[n];

    int *fenwick = new int[MAX];
    for(int i = 0; i < MAX; i++) fenwick[i] = 0;

    for(int i = 0; i < n;){
        int endIndex = i;
        while(endIndex < n && input[i].x == input[endIndex].x && input[i].y == input[endIndex].y){
            endIndex++;
        }

        for(int j = i; j < endIndex; j++){
            solution[input[j].index] = query(input[j].y, fenwick);
        }

        for(int j = i; j < endIndex; j++){
            update(input[j].y, fenwick);
        }

        i = endIndex;
    }

    for(int i = 0; i < n; i++) cout << solution[i] << endl;
}
