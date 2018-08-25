#include <bits/stdc++.h>
using namespace std;

int findMinBridge(vector<int> *graph, int n){
    queue< pair<int, int> > q;

    q.push({0, 0});

    bool *isVisited = new bool[n];
    for(int i = 0; i < n; i++) isVisited[i] = false;

    while(!q.empty()){
        int currVertex = q.front().first;
        int depth = q.front().second;
        isVisited[currVertex] = true;
        q.pop();

        for(int i = 0; i < graph[currVertex].size(); i++){
            int x = graph[currVertex][i];

            if(!isVisited[x]){
                if(x == n-1) return depth+1;
                else q.push({x, depth+1});
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> *graph = new vector<int>[n];

        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            graph[x-1].push_back(y-1);
            graph[y-1].push_back(x-1);
        }

        cout << findMinBridge(graph, n) << endl;
    }
}
