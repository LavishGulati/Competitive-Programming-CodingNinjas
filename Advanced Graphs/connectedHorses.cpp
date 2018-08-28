#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll moveX[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
ll moveY[8] = {1, -1, -2, -2, -1, 1, 2, 2};

ll dfs(ll i, ll j, vector< pair<ll, ll> > **graph, bool **isVisited){
    isVisited[i][j] = true;

    ll answer = 1;
    for(ll k = 0; k < graph[i][j].size(); k++){
        ll x = graph[i][j][k].first;
        ll y = graph[i][j][k].second;
        if(!isVisited[x][y]){
            answer = (answer+dfs(x, y, graph, isVisited))%MOD;
        }
    }

    return answer;
}

int main(){
    ll *factorial = new ll[1000000];
    factorial[1] = 1;
    for(ll i = 2; i < 1000000; i++) factorial[i] = (factorial[i-1]*i)%MOD;
    ll t;
    cin >> t;
    while(t--){
        ll n, m, q;
        cin >> n >> m >> q;

        vector< pair<ll, ll> > **graph = new vector< pair<ll, ll> >*[n];
        for(ll i = 0; i < n; i++){
            graph[i] = new vector< pair<ll, ll> >[m];
        }

        ll **board = new ll*[n];
        for(ll i = 0; i < n; i++){
            board[i] = new ll[m];
            for(ll j = 0; j < m; j++) board[i][j] = 0;
        }

        for(ll i = 0; i < q; i++){
            ll x, y;
            cin >> x >> y;
            board[x-1][y-1] = 1;
        }

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                // cout << i << " " << j << ": ";
                if(board[i][j] > 0){
                    // cout << i << " " << j << ": ";
                    for(ll k = 0; k < 8; k++){
                        ll nextX = i+moveX[k];
                        ll nextY = j+moveY[k];
                        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && board[nextX][nextY] > 0){
                            // cout << nextX << " " << nextY << ", ";
                            graph[i][j].push_back({nextX, nextY});
                        }
                    }
                    // cout << endl;
                }
                // cout << endl;
            }
        }

        bool **isVisited = new bool*[n];
        for(ll i = 0; i < n; i++){
            isVisited[i] = new bool[m];
            for(ll j = 0; j < m; j++) isVisited[i][j] = false;
        }

        ll product = 1;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                if(board[i][j] > 0 && !isVisited[i][j]){
                    ll comp = dfs(i, j, graph, isVisited);
                    // cout << i << " " << j << " " << comp << endl;
                    product = (product*factorial[comp])%MOD;
                }
            }
        }

        cout << product << endl;
    }
}
