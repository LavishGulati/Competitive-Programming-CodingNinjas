#include <bits/stdc++.h>
using namespace std;

int findParent(int *parent, int id){
    while(parent[id] != id){
        id = parent[id];
    }
    return id;
}

int main(){
    int v, e;
    cin >> v >> e;
    pair< int, pair<int, int> > *input = new pair< int, pair<int, int> >[e];
    for(int i = 0; i < e; i++){
        int ei, ej, wi;
        cin >> ei >> ej >> wi;
        input[i] = { wi, {ei, ej} };
    }

    sort(input, input+e);

    int *parent = new int[v];
    for(int i = 0; i < v; i++) parent[i] = i;

  	int count = 0;
  	int i = 0;
    while(count < v-1){
        int ei, ej, wi;
        ei = input[i].second.first;
        ej = input[i].second.second;
        wi = input[i].first;

        int parent1 = findParent(parent, ei);
        int parent2 = findParent(parent, ej);

        if(parent1 != parent2){
          	if(ei <= ej) cout << ei << " " << ej << " " << wi << endl;
          	else cout << ej << " " << ei << " " << wi << endl;

          	parent[parent1] = parent2;
          	count++;
        }
      	i++;
    }
}
