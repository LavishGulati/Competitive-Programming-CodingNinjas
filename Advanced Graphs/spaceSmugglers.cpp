#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vetor< pair<int, int> > *graph = new vector< pair<int, int> >;
    for(int i = 0; i < m; i++){
        int u, v, g;
        cin >> u >> v >> g;
        graph[i-1].push_back({v-1, g});
    }
}
