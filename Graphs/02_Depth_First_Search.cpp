#include<iostream>
using namespace std;

void DFS(int vertex, int A[8][8], int n){
    static int visited[8] = {0};
    if(visited[vertex] == 0){
        cout << vertex << " " << flush;
        visited[vertex] = 1;
        for(int v=1;v<n;v++){
            if(A[vertex][v] == 1 && visited[v] == 0){
                DFS(v, A, n);
            }
        }
    }
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
    DFS(7, A, 8);
    return 0;
}