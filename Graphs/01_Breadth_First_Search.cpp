#include<iostream>
#include<queue>
using namespace std;

void BFS(int vertex, int A[8][8], int n){
    queue<int> Q;
    int visited[n] = {0};

    cout << vertex << " " << flush;
    visited[vertex] = 1;
    Q.emplace(vertex);

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int v=1;v<=n;v++){
            if(A[u][v] == 1 && visited[v] == 0){
                cout << v << " " << flush;
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }

    cout << endl;
}

int main(){
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    
    BFS(1, A, 8);
    BFS(4, A, 8);
    return 0;
}