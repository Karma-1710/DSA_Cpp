#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define N 8

void shortestPath(int graph[N+1][N+1]){
    int stages = 4;
    int min;
    int cost[N+1];
    int d[N+1];
    int P[stages+1];

    cost[N] = 0;
    for(int i=N-1;i>=1;i--){
        min = INF;
        for(int k = i+1;k<=N;k++){
            if(graph[i][k] != 0 && graph[i][k] + cost[k] < min){
                min = graph[i][k] + cost[k];
                d[i] = k;
            }
            cost[i] = min;
        }
    }
    P[1] = 1;
    P[stages] = N;
    for(int i=2;i<stages;i++){
        P[i] = d[P[i-1]];
    }

    for(int i=1;i<=stages;i++){
        cout << P[i] << " " <<flush;
    }
}

int main(){
    int graph[N+1][N+1] = {{0,0,0,0,0,0,0,0,0},
                           {0,0,2,1,3,0,0,0,0},
                           {0,0,0,0,0,2,3,0,0},
                           {0,0,0,0,0,6,7,0,0},
                           {0,0,0,0,0,6,8,9,0},
                           {0,0,0,0,0,0,0,0,6},
                           {0,0,0,0,0,0,0,0,4},
                           {0,0,0,0,0,0,0,0,5},
                           {0,0,0,0,0,0,0,0,0}};

    cout << "Shortest Path: "<< endl;
    shortestPath(graph);
    return 0;
}