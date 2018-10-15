#include <bits/stdc++.h>
using namespace std;

class query{
public:
    int start, end, index;
};

bool operator< (query a, query b){
    return a.end < b.end;
}

void update(int *bit, int id, int value, int n){
    for(; id <= n; id += id&(-id)){
        bit[id] += value;
    }
}

int value(int *bit, int id){
    int answer = 0;
    for(; id > 0; id -= id&(-id)){
        answer += bit[id];
    }
    return answer;
}

int main(){
    int n, i;
    cin >> n;

    int *input = new int[n+1];
    for(i = 1; i <= n; i++) cin >> input[i];

    int q;
    cin >> q;

    query *queries = new query[q];
    for(i = 0; i < q; i++){
        cin >> queries[i].start >> queries[i].end;
        queries[i].index = i;
    }

    sort(queries, queries+q);
    int *distinct = new int[1000001];
    for(i = 0; i < 1000001; i++) distinct[i] = -1;

    int *bit = new int[n+1];
    for(i = 0; i <= n; i++) bit[i] = 0;
    int total = 0, k = 0;
    int *answer = new int[q];

    for(i = 1; i <= n; i++){
        if(distinct[input[i]] != -1){
            update(bit, distinct[input[i]], -1, n);
        }
        else total++;

        update(bit, i, 1, n);
        distinct[input[i]] = i;

        while(k < q && queries[k].end == i){
            answer[ queries[k].index ] = total - value(bit, queries[k].start - 1);
            k++;
        }
    }

    for(i = 0; i < q; i++) cout << answer[i] << endl;
}
