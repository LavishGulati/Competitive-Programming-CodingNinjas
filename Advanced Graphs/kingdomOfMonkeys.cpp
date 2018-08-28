#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<ll> *graph, bool *isVisited, ll i, unordered_set<ll> *component){
    isVisited[i] = true;
    component->insert(i);

    for(ll j = 0; j < graph[i].size(); j++){
        ll next = graph[i][j];
        if(!isVisited[next]){
            dfs(graph, isVisited, next, component);
        }
    }
}

unordered_set< unordered_set<ll> * > *connectComponents(vector<ll> *graph, ll n){
    unordered_set< unordered_set<ll> * > *output = new unordered_set< unordered_set<ll> * >();

    bool *isVisited = new bool[n];
    for(ll i = 0; i < n; i++) isVisited[i] = false;

    for(ll i = 0; i < n; i++){
        if(!isVisited[i]){
            unordered_set<ll> *component = new unordered_set<ll>();
            dfs(graph, isVisited, i, component);
            output->insert(component);
        }
    }

    return output;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;

        vector<ll> *graph = new vector<ll>[n];

        for(ll i = 0; i < m; i++){
            // cout << i << endl;
            ll x, y;
            cin >> x >> y;
            graph[x-1].push_back(y-1);
            graph[y-1].push_back(x-1);
        }

        ll *reward = new ll[n];
        for(ll i = 0; i < n; i++){
            // cout << "Reward inputting" << endl;
            cin >> reward[i];
        }

        unordered_set< unordered_set<ll> * > *output = connectComponents(graph, n);

        ll max = 0;
        unordered_set< unordered_set<ll> * >::iterator i = output->begin();
        while(i != output->end()){
            unordered_set<ll> *component = *i;
            ll total = 0;
            unordered_set<ll>::iterator j = component->begin();
            while(j != component->end()){
                total += reward[*j];
                j++;
            }

            if(max < total) max = total;

            i++;
        }

        cout << max << endl;
    }
}
