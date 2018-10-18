#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

void buildTree(int *tree, string &input, int si, int ei, int id){
    if(si == ei){
        // cout << si << " " << ei << " " << tree[id] << endl;
        tree[id] = (input[si] == '0' ? 0 : 1);
        return;
    }

    int mid = (si+ei)/2;
    buildTree(tree, input, si, mid, 2*id);
    buildTree(tree, input, mid+1, ei, 2*id+1);

    if(tree[2*id] == 0) tree[id] = tree[2*id+1];
    else if(tree[2*id] == 1){
        if((ei-mid)%2 == 0) tree[id] = (1+tree[2*id+1])%3;
        else tree[id] = (2+tree[2*id+1])%3;
    }
    else{
        if((ei-mid)%2 == 0) tree[id] = (2+tree[2*id+1])%3;
        else tree[id] = (1+tree[2*id+1])%3;
    }

    // cout << si << " " << ei << " " << tree[id] << endl;
}

int query(int *tree, int si, int ei, int id, int left, int right){
    int mid = (si+ei)/2;

    if(si > right || ei < left){
        return 0;
    }
    else if(si >= left && ei <= right){
        return tree[id];
    }
    else if(right <= mid) return query(tree, si, mid, 2*id, left, right);
    else if(left > mid) return query(tree, mid+1, ei, 2*id+1, left, right);

    int x = query(tree, si, mid, 2*id, left, right);
    int y = query(tree, mid+1, ei, 2*id+1, left, right);

    if(x == 0) return y;
    else if(x == 1){
        if((ei-mid)%2 == 0) return (1+y)%3;
        else return (2+y)%3;
    }
    else{
        if((ei-mid)%2 == 0) return (2+y)%3;
        else return (1+y)%3;
    }
}

void update(int *tree, string &input, int si, int ei, int id, int key){
    if(si == ei){
        if(input[si] == '0'){
            input[si] = '1';
            tree[id] = 1;
        }
        // cout << si << " " << ei << " " << tree[id] << endl;
        return;
    }

    int mid = (si+ei)/2;
    if(key <= mid){
        update(tree, input, si, mid, 2*id, key);
    }
    else{
        update(tree, input, mid+1, ei, 2*id+1, key);
    }

    if(tree[2*id] == 0) tree[id] = tree[2*id+1];
    else if(tree[2*id] == 1){
        if((ei-mid)%2 == 0) tree[id] = (1+tree[2*id+1])%3;
        else tree[id] = (2+tree[2*id+1])%3;
    }
    else{
        if((ei-mid)%2 == 0) tree[id] = (2+tree[2*id+1])%3;
        else tree[id] = (1+tree[2*id+1])%3;
    }

    // cout << si << " " << ei << " " << tree[id] << endl;
}

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int *tree = new int[4*n];
    buildTree(tree, s, 0, n-1, 1);

    int q, type, key, left, right;
    cin >> q;
    while(q--){
        cin >> type;
        if(type == 0){
            cin >> left >> right;
            cout << query(tree, 0, n-1, 1, left, right) << endl;
        }
        else{
            cin >> key;
            update(tree, s, 0, n-1, 1, key);
        }
    }
}
