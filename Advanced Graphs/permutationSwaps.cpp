#include <bits/stdc++.h>
using namespace std;

set< set<int> *> *getComponent(vecotr<int> *graph, int n){
    bool *visited = new bool[n];
    for(int i = 0; i < )
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        int *p = new int[n+1];
        for(int i = 1; i <= n; i++) cin >> p[i];

        int *q = new int[n+1];
        for(int i = 1; i <= n; i++) cin >> q[i];

        vector<int> *graph = new vector<int>[n+1];
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[i].push_back(j);
            graph[j].push_back(i);
        }

        set< set<int> *> *component = getComponent(graph, n);

        delete[] component;
        delete[] graph;
        delete[] q;
        delete[] p;
    }
}
