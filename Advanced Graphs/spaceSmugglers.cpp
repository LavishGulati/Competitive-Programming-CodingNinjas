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
typedef pair<long long, long long> pll;

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

struct node{
    ll vertex;
    ll weight;
    node *next;
};

struct adjList{
    node *head;
};

struct graph{
    ll num;
    adjList *array;
};

struct heapNode{
    ll vertex;
    ll weight;
};

struct heap{
    ll size;
    ll capacity;
    ll *pos;
    heapNode **array;
};

node *createNode(ll v, ll w){
    node *newNode = new node;
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

graph *createGraph(ll n){
    graph *newGraph = new graph;
    newGraph->num = n;
    newGraph->array = new adjList[n];
    for(ll i = 0; i < n; i++){
        newGraph->array[i].head = NULL;
    }

    return newGraph;
}

void addEdge(graph *newGraph, ll source, ll dest, ll weight){
    node *newNode = createNode(dest, weight);
    newNode->next = newGraph->array[source].head;
    newGraph->array[source].head = newNode;
}

heapNode *createHeapNode(ll v, ll w){
    heapNode *newNode = new heapNode;
    newNode->vertex = v;
    newNode->weight = w;
    return newNode;
}

heap *createHeap(ll c){
    heap *newHeap = new heap;
    newHeap->pos = new ll[c];
    newHeap->size = 0;
    newHeap->capacity = c;
    newHeap->array = new heapNode *[c];
    return newHeap;
}

void swapHeapNode(heapNode **a, heapNode **b){
    heapNode *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(heap *minHeap, ll id){
    ll smallest, left, right;
    smallest = id;
    left = 2*id+1;
    right = 2*id+2;

    if(left < minHeap->size && minHeap->array[left]->weight < minHeap->array[smallest]->weight){
        smallest = left;
    }

    if(right < minHeap->size && minHeap->array[right]->weight < minHeap->array[smallest]->weight){
        smallest = right;
    }

    if(smallest != id){
        heapNode *smallestNode = minHeap->array[smallest];
        heapNode *idNode = minHeap->array[id];

        minHeap->pos[smallestNode->vertex] = id;
        minHeap->pos[idNode->vertex] = smallest;

        swapHeapNode(&minHeap->array[smallest], &minHeap->array[id]);
        minHeapify(minHeap, smallest);
    }
}

bool isEmpty(heap *newHeap){
    return newHeap->size == 0;
}

heapNode *extractMin(heap *minHeap){
    if(isEmpty(minHeap)) return NULL;

    heapNode *root = minHeap->array[0];
    heapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->vertex] = minHeap->size - 1;
    minHeap->pos[lastNode->vertex] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(heap *minHeap, ll v, ll w){
    ll i = minHeap->pos[v];
    minHeap->array[i]->weight = w;

    while(i && minHeap->array[i]->weight < minHeap->array[(i-1)/2]->weight){
        minHeap->pos[minHeap->array[i]->vertex] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->vertex] = i;
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i-1)/2]);

        i = (i-1)/2;
    }
}

bool isInMinHeap(heap *minHeap, ll v){
    if(minHeap->pos[v] < minHeap->size) return true;
    else return false;
}

ll *djikstra(graph *newGraph, ll source){
    ll n = newGraph->num;
    ll *distance = new ll[n];

    heap *minHeap = createHeap(n);
    for(ll v = 0; v < n; v++){
        distance[v] = INT_MAX;
        minHeap->array[v] = createHeapNode(v, distance[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[source] = createHeapNode(source, distance[source]);
    minHeap->pos[source] = source;
    distance[source] = 0;
    decreaseKey(minHeap, source, distance[source]);

    minHeap->size = n;

    while(!isEmpty(minHeap)){
        heapNode *minHeapNode = extractMin(minHeap);
        ll u = minHeapNode->vertex;

        node *temp = newGraph->array[u].head;
        while(temp != NULL){
            ll v = temp->vertex;
            if(isInMinHeap(minHeap, v) && distance[u] != INT_MAX && temp->weight + distance[u] < distance[v]){
                distance[v] = temp->weight + distance[u];
                decreaseKey(minHeap, v, distance[v]);
            }
            temp = temp->next;
        }
    }

    return distance;
}

int main(){
    ll n, m, s, t, i, w;
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    s--;
    t--;

    graph *newGraph = createGraph(n);
    graph *revGraph = createGraph(n);

    ll u, v, g;
    for(i = 0; i < m; i++){
        scanf("%lld%lld%lld", &u, &v, &g);
        addEdge(newGraph, u-1, v-1, g);
        addEdge(revGraph, v-1, u-1, g);
    }

    ll *sToV = djikstra(newGraph, s);
    ll *vToS = djikstra(revGraph, s);
    ll *vToT = djikstra(revGraph, t);
    ll *tToV = djikstra(newGraph, t);

    ll minTime = INT_MAX;
    for(w = 0; w < n; w++){
        if(w == s || w == t) continue;
        if(sToV[w]+vToT[w]+tToV[w]+vToS[w] < minTime){
            minTime = sToV[w]+vToT[w]+tToV[w]+vToS[w];
        }
    }

    if(minTime == INT_MAX) cout << -1 << endl;
    else cout << minTime << endl;
}
