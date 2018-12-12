#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

int power[100001];

void buildPower(){
    power[0] = 1;
    for(int i = 1; i < 100001; i++) power[i] = (power[i-1]*2)%3;
}

void buildTree(int *tree, int *input, int si, int ei, int id){
    if(si == ei) tree[id] = input[si];
    else{
        int mid = (si+ei)/2;
        buildTree(tree, input, si, mid, 2*id);
        buildTree(tree, input, mid+1, ei, 2*id+1);

        tree[id] = (power[ei-mid]*tree[2*id] + tree[2*id+1])%3;
    }
}

int query(int *tree, int si, int ei, int id, int left, int right){
    if(si > right || ei < left) return 0;
    else if(si >= left && ei <= right) return (tree[id]*power[right-ei])%3;

    int mid = (si+ei)/2;

    int x = query(tree, si, mid, 2*id, left, right);
    int y = query(tree, mid+1, ei, 2*id+1, left, right);
    return (x+y)%3;
}

void update(int *tree, int *input, int si, int ei, int id, int key){
    if(si == ei){
        input[key] = 1;
        tree[id] = 1;
    }
    else{
        int mid = (si+ei)/2;
        if(si <= key && mid >= key) update(tree, input, si, mid, 2*id, key);
        else update(tree, input, mid+1, ei, 2*id+1, key);

        tree[id] = (power[ei-mid]*tree[2*id] + tree[2*id+1])%3;
    }
}

int main(){
    buildPower();

    int n;
    scanf("%d", &n);

    string s;
    cin >> s;
    int *input = new int[n];
    for(int i = 0; i < n; i++) input[i] = s[i]-'0';

    int *tree = new int[4*n];
    buildTree(tree, input, 0, n-1, 1);

    int q, type, key, left, right;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &type);
        if(type == 0){
            scanf("%d%d", &left, &right);
            printf("%d\n", query(tree, 0, n-1, 1, left, right));
        }
        else{
            scanf("%d", &key);
            if(input[key] == 0) update(tree, input, 0, n-1, 1, key);
        }
    }
}
