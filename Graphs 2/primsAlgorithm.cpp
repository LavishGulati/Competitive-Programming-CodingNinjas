#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int *weight, bool *isVisited, int n){
    int minVertex;
    int i = 0;
    while(i < n){
        if(!isVisited[i]){
            minVertex = i;
            break;
        }
        i++;
    }

    while(i < n){
        if(!isVisited[i] && weight[i] < weight[minVertex]) minVertex = i;
        i++;
    }

    return minVertex;
}

int main(){
    int n, e;
    cin >> n >> e;

    int **input = new int*[n];
    for(int i = 0; i < n; i++){
        input[i] = new int[n];
        for(int j = 0; j < n; j++) input[i][j] = -1;
    }

    for(int i = 0; i < e; i++){
        int ei, ej, w;
        cin >> ei >> ej >> w;
        input[ei][ej] = w;
        input[ej][ei] = w;
    }

    int *parent = new int[n];
    int *weight = new int[n];
    bool *isVisited = new bool[n];

    for(int i = 0; i < n; i++){
        weight[i] = INT_MAX;
        isVisited[i] = false;
    }

    parent[0] = -1;
    weight[0] = 0;
    for(int i = 0; i < n; i++){
        int minVertex = findMinVertex(weight, isVisited, n);
        cout << minVertex << endl;
        isVisited[minVertex] = true;

        for(int j = 0; j < n; j++){
            if(!isVisited[j] && input[minVertex][j] != -1 && input[minVertex][j] < weight[j]){
                weight[j] = input[minVertex][j];
                parent[j] = minVertex;
            }
        }
    }

    for(int i = 1; i < n; i++){
        int ei = i;
        int ej = parent[i];
        int w = weight[i];
        if(ei < ej) cout << ei << " " << ej << " " << w << endl;
        else cout << ej << " " << ei << " " << w << endl;
    }
}
