int dp[105][1<<12];

int findTouches(int pos, int mask, vector<string> &v){
    if(!(mask&(mask-1)) && mask) return 0;

    if(pos == -1 || mask == 0) return 100000;

    if(dp[pos][mask]) return dp[pos][mask];

    int newMask1 = 0, newMask2 = 0, touches = 0;
    for(int i = 0; i < v.size(); i++){
        if((mask>>i)&1){
            touches++;
            if(v[i][pos] == '0') newMask1 |= (1<<i);
            else newMask2 |= (1<<i);
        }
    }

    return dp[pos][mask] = min(findTouches(pos-1, newMask1, v)+findTouches(pos-1, newMask2, v)+touches, findTouches(pos-1, mask, v));
}

int minimumTouchesRequired(int n, vector<string> v){
    return findTouches(v[0].size()-1, (1<<n)-1, v);
}
