#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define sec second
#define MOD 1000000007

int compNum[100005];

void dfs(vector<int> **graph, int source, bool *isVisited, stack<int> &s){
    isVisited[source] = true;
    for(int i = 0; i < graph[source]->size(); i++){
        int v = graph[source]->at(i);
        if(!isVisited[v]){
            dfs(graph, v, isVisited, s);
        }
    }

    s.push(source);
}

void revDFS(vector<int> **graph, int source, int cycle, bool *isVisited){
    isVisited[source] = true;
    compNum[source] = cycle;

    for(int i = 0; i < graph[source]->size(); i++){
        int v = graph[source]->at(i);
        if(!isVisited[v]){
            revDFS(graph, v, cycle, isVisited);
        }
    }
}

int kosaraju(vector<int> **graph, vector<int> **revGraph, int n){
    bool *isVisited = new bool[n];
    for(int i = 0; i < n; i++) isVisited[i] = false;

    stack<int> s;
    for(int i = 0; i < n; i++){
        if(!isVisited[i]){
            dfs(graph, i, isVisited, s);
        }
    }

    int cycle = 0;
    for(int i = 0; i < n; i++) isVisited[i] = false;
    while(!s.empty()){
        int vertex = s.top();
        s.pop();
        if(!isVisited[vertex]){
            revDFS(revGraph, vertex, cycle, isVisited);
            cycle++;
        }
    }

    return cycle;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> **graph = new vector<int> *[n];
    for(int i = 0; i < n; i++) graph[i] = new vector<int>;

    vector<int> **revGraph = new vector<int> *[n];
    for(int i = 0; i < n; i++) revGraph[i] = new vector<int>;

    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u-1]->pb(v-1);
        revGraph[v-1]->pb(u-1);
    }

    int cycle = kosaraju(graph, revGraph, n);

    int *out = new int[n];
    for(int i = 0; i < n; i++) out[i] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < graph[i]->size(); j++){
            int v = graph[i]->at(j);
            if(compNum[i] != compNum[v]) out[compNum[i]]++;
        }
    }

    int count = 0;
    for(int i = 0; i < cycle; i++){
        if(out[i] == 0) count++;
    }

    if(count > 1){
        cout << 0 << endl;
        return 0;
    }

    vector<int> output;
    for(int i = 0; i < n; i++){
        if(out[compNum[i]] == 0) output.pb(i);
    }

    cout << output.size() << endl;
    for(int i = 0; i < output.size(); i++){
        cout << output[i]+1 << " ";
    }
    cout << endl;
}
