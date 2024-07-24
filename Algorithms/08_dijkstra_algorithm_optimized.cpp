#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// declaring a new datatype iPair which is pair containing two integer values
typedef pair<int,int> iPair;

// make structure for graph
class Graph{
    public:
        int V;
        // adj is a pointer to a an array which is not declared yet, and each element in the list contains list of pair of integers
        list<pair<int,int>>* adj;
        Graph(int V); // constructor
        void addEdge(int u, int v, int w);
        void shortestPath(int src);
};

Graph::Graph(int V){
    this->V = V;
    // here we are declaring an array of length V where each element will be a list of pairs
    adj = new list<iPair>[V];
};

void Graph::addEdge(int u, int v, int w){
    // we will be able to push into adj list so that to ensure undirected graph
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void Graph::shortestPath(int src){
    // Now we will declare a priority queue to develop a Min heap data structure using greater<iPair> as a functor for minHeap 
    // So in MinHeap we will have always shorter value alway at the top

    priority_queue<iPair, vector<iPair>,greater<iPair>> pq;
    
    // Make a distance vector to store the minimum distances from the source vertex to all the vertex in Graph and declare all the initial values to INF (infinity)
    vector<int> dist(V, INF);
    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(!pq.empty()){
        // taking the top most element out of Min heap
        int u = pq.top().second;
        pq.pop();

        // make a iterator for itereating through the list of pairs of each element in the adjaceny array/list
        list<pair<int,int>>::iterator i;

        for(i=adj[u].begin();i!=adj[u].end();i++){
            int v = (*i).first;
            int weight = (*i).second;

            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for(int i=0;i<V;i++){
        cout << i << " " << dist[i] << endl;
    }
}

int main(){
    int V = 9;
    Graph g(V);

    // making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    // Function call
    g.shortestPath(0);
    return 0;
}