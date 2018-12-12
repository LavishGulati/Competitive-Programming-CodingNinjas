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

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define MAX 100001

struct node{
    ll sumSquares, sum;
};

// Type 1 for increment
// Type 2 for change
struct lazyNode{
    ll key, type;
};

node tree[4*MAX];
lazyNode lazy[4*MAX];

void update(ll si, ll ei, ll start, ll end, ll id, ll val, ll choice){
    if(si > ei) return;

    if(lazy[id].type != 0){
        if(lazy[id].type == 1){
            tree[id].sumSquares += 2*(lazy[id].key)*(tree[id].sum);
            tree[id].sumSquares += (lazy[id].key)*(lazy[id].key)*(ei-si+1);
            tree[id].sum += (lazy[id].key)*(ei-si+1);

            if(si != ei){
                lazy[2*id].type = lazy[2*id].type == 2 ? 2 : 1;
                lazy[2*id].key += lazy[id].key;
                lazy[2*id+1].type = lazy[2*id].type == 2 ? 2 : 1;
                lazy[2*id+1].key += lazy[id].key;
            }
        }
        else if(lazy[id].type == 2){
            tree[id].sumSquares = (lazy[id].key)*(lazy[id].key)*(ei-si+1);
            tree[id].sum = (lazy[id].key)*(ei-si+1);

            if(si != ei){
                lazy[2*id].type = 2;
                lazy[2*id].key = lazy[id].key;
                lazy[2*id+1].type = 2;
                lazy[2*id+1].key = lazy[id].key;
            }
        }

        lazy[id].key = 0;
        lazy[id].type = 0;
    }

    if(start > ei || end < si) return;
    else if(start <= si && ei <= end){
        if(choice == 1){
            tree[id].sumSquares += 2*val*(tree[id].sum);
            tree[id].sumSquares += val*val*(ei-si+1);
            tree[id].sum += val*(ei-si+1);

            if(si != ei){
                lazy[2*id].type = lazy[2*id].type == 2 ? 2 : 1;
                lazy[2*id].key += val;
                lazy[2*id+1].type = lazy[2*id].type == 2 ? 2 : 1;
                lazy[2*id+1].key += val;
            }
        }
        else if(choice == 2){
            tree[id].sumSquares = val*val*(ei-si+1);
            tree[id].sum = val*(ei-si+1);

            if(si != ei){
                lazy[2*id].type = 2;
                lazy[2*id].key = val;
                lazy[2*id+1].type = 2;
                lazy[2*id+1].key = val;
            }
        }

        return;
    }

    ll mid = (si+ei)/2;
    update(si, mid, start, end, 2*id, val, choice);
    update(mid+1, ei, start, end, 2*id+1, val, choice);
    tree[id].sumSquares = tree[2*id].sumSquares + tree[2*id+1].sumSquares;
    tree[id].sum = tree[2*id].sum + tree[2*id+1].sum;
}

ll query(ll si, ll ei, ll start, ll end, ll id){
    if(si > ei) return 0;

    if(lazy[id].type != 0){
        if(lazy[id].type == 1){
            tree[id].sumSquares += 2*(lazy[id].key)*(tree[id].sum);
            tree[id].sumSquares += (lazy[id].key)*(lazy[id].key)*(ei-si+1);
            tree[id].sum += (lazy[id].key)*(ei-si+1);

            if(si != ei){
                lazy[2*id].type = lazy[2*id].type == 2 ? 2 : 1;
                lazy[2*id].key += lazy[id].key;
                lazy[2*id+1].type = lazy[2*id].type == 2 ? 2 : 1;
                lazy[2*id+1].key += lazy[id].key;
            }
        }
        else if(lazy[id].type == 2){
            tree[id].sumSquares = (lazy[id].key)*(lazy[id].key)*(ei-si+1);
            tree[id].sum = (lazy[id].key)*(ei-si+1);

            if(si != ei){
                lazy[2*id].type = 2;
                lazy[2*id].key = lazy[id].key;
                lazy[2*id+1].type = 2;
                lazy[2*id+1].key = lazy[id].key;
            }
        }

        lazy[id].key = 0;
        lazy[id].type = 0;
    }

    if(start > ei || end < si) return 0;
    else if(start <= si && ei <= end) return tree[id].sumSquares;

    ll mid = (si+ei)/2;
    ll x = query(si, mid, start, end, 2*id);
    ll y = query(mid+1, ei, start, end, 2*id+1);
    return x+y;
}

void printTree(ll n){
    for(ll i = 0; i < 3*n; i++){
        cout << tree[i].sumSquares << " " << tree[i].sum << ", ";
    }
    cout << endl;
}

void printLazy(ll n){
    for(ll i = 0; i < 3*n; i++){
        cout << lazy[i].key << " " << lazy[i].type << ", ";
    }
    cout << endl;
}

int main(){
    ll t, n, q, val, choice, start, end;
    cin >> t;
    for(ll j = 0; j < t; j++){
        cout << "Case " << j+1 << ":\n";

        for(ll i = 0; i < 4*MAX; i++){
            tree[i].sumSquares = 0;
            tree[i].sum = 0;
            lazy[i].key = 0;
            lazy[i].type = 0;
        }

        cin >> n >> q;
        for(ll i = 0; i < n; i++){
            cin >> val;
            update(0, n-1, i, i, 1, val, 1);
        }

        while(q--){
            cin >> choice;
            if(choice == 2){
                cin >> start >> end;
                cout << query(0, n-1, start-1, end-1, 1) << endl;
                // printTree(n);
                // printLazy(n);
            }
            else if(choice == 0){
                cin >> start >> end >> val;
                update(0, n-1, start-1, end-1, 1, val, 2);
                // printTree(n);
                // printLazy(n);
            }
            else if(choice == 1){
                cin >> start >> end >> val;
                update(0, n-1, start-1, end-1, 1, val, 1);
                // printTree(n);
                // printLazy(n);
            }
        }
    }
}
