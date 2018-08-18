#include <bits/stdc++.h>
using namespace std;

int main(){
    int v, e;
    cin >> v >> e;

    int **input = new int*[v];
    for(int i = 0; i < v; i++){
        input[i] = new int[v];
        for(int j = 0; j < v; j++) input[i][j] = -1;
    }

    int ei, ej, w;
    for(int i = 0; i < e; i++){
        cin >> ei >> ej >> w;
        input[ei][ej] = w;
        input[ej][ei] = w;
    }

    int *parent = new int[v];
    int *weight = new int[v];
    for(int i = 0; i < v; i++) weight[i] = INT_MAX;

    bool *isVisited = new bool[v];
    for(int i = 0; i < v; i++) isVisited[i] = false;

    for(int i = 0; i < v-1; i++){
        isVisited[i] = true;

        for(int j = 0; j < v; j++){
            if(input[i][j] != -1 && !isVisited[j]){
                if(input[i][j] < weight[j]){
                    parent[j] = i;
                    weight[j] = input[i][j];
                }
            }
        }
    }

    for(int i = 1; i < v; i++){
        ei = i;
        ej = parent[i];
        w = weight[i];

        if(ei <= ej) cout << ei << " " << ej << " " << w << endl;
        else cout << ej << " " << ei << " " << w << endl;
    }
}
