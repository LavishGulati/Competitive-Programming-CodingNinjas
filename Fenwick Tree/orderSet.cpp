#include <bits/stdc++.h>
using namespace std;
#define all(x) (x)->begin(), (x)->end()

void update(int *bit, int id, int value, int n){
    for(; id <= n; id += id&(-id)){
        bit[id] += value;
    }
}

int query(int *bit, int id){
    int total = 0;
    for(; id > 0; id -= id&(-id)){
        total += bit[id];
    }
    return total;
}

int findLowerBound(vector<int> *insert, int x){
    int answer = 0;
    int start = 0;
    int end = insert->size() - 1;
    int mid;

    // cout << end << " " << insert->at(start) << " " << insert->at(end) << endl;

    if(x > insert->at(end)) return end;
    if(x <= insert->at(start)) return 0;

    while(start <= end){
        // cout << start << " "wrong << end << endl;

        mid = (start+end)/2;

        if(insert->at(mid) < x) start = mid+1;
        else{
            answer = mid;
            end = mid-1;
        }

    }

    // cout << answer << endl;

    return answer;
}

int main(){
    int q, i;
    scanf("%d", &q);

    char *token = new char[q];
    int *input = new int[q];
    vector<int> *insert = new vector<int>;
    for(i = 0; i < q; i++){
        scanf(" %c %d", token+i, input+i);
        if(token[i] == 'I') insert->push_back(input[i]);
    }

    // cout << "No Error" << endl;

    int n = insert->size();
    sort(all(insert));

    unordered_map<int, int> m;
    for(i = 1; i <= n; i++){
        if(m.find(insert->at(i-1)) == m.end()){
            m[ insert->at(i-1) ] = i;
        }
    }

    int *bit = new int[n+1];
    for(int i = 0; i <= n; i++) bit[i] = 0;

    // cout << "Starting outputting queries" << endl;

    int answer, start, end, mid, x, id;
    char tok;

    for(i = 0; i < q; i++){
        tok = token[i];
        x = input[i];

        if(tok == 'I'){
            if(query(bit, m[x]) == query(bit, m[x]-1)){
                update(bit, m[x], 1, n);
            }
            // cout << "Status of BIT array: ";
            // for(int i = 0; i <= n; i++) cout << bit[i] << " ";
            // cout << endl;
        }
        else if(tok == 'D'){
            if(query(bit, m[x]) != query(bit, m[x]-1)){
                update(bit, m[x], -1, n);
            }
        }
        else if(tok == 'K'){
            // int answer = find_K_Smallest(bit, insert, x, m);

            answer = -1;
            start = 0;
            end = insert->size()-1;
            mid;

            if(!(x <= 0 || x > m.size())){

                while(start <= end){
                    if(start < 0 || start >= n || end < 0 || end >= n) break;

                    mid = (start+end)/2;
                    int q = query(bit, m[ insert->at(mid) ]);
                    if(q == x){
                        if(q != query(bit, m[insert->at(mid)]-1)){
                            answer = insert->at(mid);
                            break;
                        }
                        else end = mid-1;
                    }
                    else if(q < x) start = mid+1;
                    else end = mid-1;
                }

            }

            if(answer != -1) printf("%d\n", answer);
            else printf("invalid\n");
        }
        else if(tok == 'C'){
            id = findLowerBound(insert, x);
            // cout << "Lower Bound element is: " << insert->at(id) << endl;
            if(id == 0) printf("0\n");
            else{
                id--;
                printf("%d\n", query(bit, m[ insert->at(id) ]));
            }
        }
    }
}
