#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

class node{
public:
    ll maxSum, sum, preSum, sufSum;

    node(){

    }

    node(ll ms, ll s, ll ps, ll ss){
        maxSum = ms;
        sum = s;
        preSum = ps;
        sufSum = ss;
    }
};

ll max(ll a, ll b, ll c, ll d, ll e){
    return std::max(a, std::max(b, std::max(c, std::max(d, e))));
}

void buildTree(node *tree, ll *input, ll si, ll ei, ll id){
    if(si == ei){
        tree[id] = node(input[si], input[si], input[si], input[si]);
        return;
    }

    ll mid = (si+ei)/2;
    buildTree(tree, input, si, mid, 2*id);
    buildTree(tree, input, mid+1, ei, 2*id+1);

    tree[id].sum = tree[2*id].sum + tree[2*id+1].sum;
    tree[id].preSum = std::max(tree[2*id].preSum, tree[2*id].sum + tree[2*id+1].preSum);
    tree[id].sufSum = std::max(tree[2*id+1].sufSum, tree[2*id+1].sum + tree[2*id].sufSum);
    tree[id].maxSum = max(tree[2*id].maxSum, tree[2*id+1].maxSum, tree[2*id].sum + tree[2*id+1].preSum, tree[2*id+1].sum + tree[2*id].sufSum, tree[2*id].sufSum + tree[2*id+1].preSum);
}

node query(node *tree, ll si, ll ei, ll id, ll left, ll right){
    if(si > right || ei < left){
        return node(INT_MIN, INT_MIN, INT_MIN, INT_MIN);
    }
    else if(si >= left && ei <= right){
        return tree[id];
    }
    
    ll mid = (si+ei)/2;
    node a = query(tree, si, mid, 2*id, left, right);
    node b = query(tree, mid+1, ei, 2*id+1, left, right);
    node answer;
    answer.sum = a.sum + b.sum;
    answer.preSum = std::max(a.preSum, a.sum + b.preSum);
    answer.sufSum = std::max(b.sufSum, b.sum + a.sufSum);
    answer.maxSum = max(a.maxSum, b.maxSum, a.sum + b.preSum, b.sum + a.sufSum, a.sufSum + b.preSum);
    return answer;
}

int main(){
    ll n;
    scanf("%lld", &n);

    ll *input = new ll[n];
    for(ll i = 0; i < n; i++) scanf("%lld", input+i);

    node *tree = new node[4*n];
    buildTree(tree, input, 0, n-1, 1);

    ll q;
    scanf("%lld", &q);
    ll x, y;
    while(q--){
        scanf("%lld%lld", &x, &y);
        printf("%lld\n", query(tree, 0, n-1, 1, x-1, y-1).maxSum);
    }
}
