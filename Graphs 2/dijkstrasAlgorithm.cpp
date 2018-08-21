#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int *weight, bool *isVisited, int n){
    int minIndex = -1;
    for(int i = 0; i < n; i++){
        if(!isVisited[i] && (minIndex == -1 || weight[i] < weight[minIndex])){
            minIndex = i;
        }
    }

    return minIndex;
}

int main(){
    int v, e;
    cin >> v >> e;

    int **input = new int*[v];
    for(int i = 0; i < v; i++){
        input[i] = new int[v];
        for(int j = 0; j < v; j++) input[i][j] = 0;
    }

    for(int i = 0; i < e; i++){
        int ei, ej, w;
        cin >> ei >> ej >> w;
        input[ei][ej] = w;
        input[ej][ei] = w;
    }

    int *weight = new int[v];
    bool *isVisited = new bool[v];
    for(int i = 0; i < v; i++){
        weight[i] = INT_MAX;
        isVisited[i] = false;
    }

    weight[0] = 0;

    for(int i = 0; i < v-1; i++){
        int currentVertex = findMinVertex(weight, isVisited, v);
        // cout << currentVertex << endl;
        isVisited[currentVertex] = true;

        for(int j = 0; j < v; j++){
            if(input[currentVertex][j] > 0 && !isVisited[j]){
                if(input[currentVertex][j]+weight[currentVertex] < weight[j]){
                    // cout << currentVertex << " " << j << endl;
                    weight[j] = input[currentVertex][j]+weight[currentVertex];
                }
            }
        }
    }

    for(int i = 0; i < v; i++){
        cout << i << " " << weight[i] << endl;
    }
}
