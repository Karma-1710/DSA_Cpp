#include<iostream>
#define V 8
#define I 32767
using namespace std;

void PrintMST(int T[2][V-2], int cost[V][V]){
    cout << "Minimum Spanning Tree along with cost: " << endl;
    int sum = 0;
    for(int i=0;i<V-2;i++){
        int c = cost[T[0][i]][T[1][i]];
        cout << "(" << T[0][i] << "," << T[1][i] << ") : " << c << endl;
        sum+=c;
    }
    cout << endl;
    cout << "Sum : " << sum << endl;
}

void PrimMST(int cost[V][V], int n){
    int u, v;
    int near[V];
    int T[2][V-2] = {0};
    int min = I;
    // Finding the Minimum cost edge from the upper triangular matrix
    for(int i=1;i<=n;i++){
        near[i] = I;
        for(int j=i;j<=n;j++){
            if(cost[i][j] < min){
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    // Updating T table with the shortest edge (i,j) => (1,6)
    T[0][0] = u;
    T[1][0] = v;
    near[u] = near[v] = 0;

    // Comparing
    for(int i=1;i<=n;i++){
        if(near[i] != 0){
            if(cost[u][i] < cost[v][i]){
                near[i] = u;
            }else{
                near[i] = v;
            }
        }
    }

    // Repeating Steps Now:
    for(int i=1;i<n-1;i++){
        min = I;
        int k;

        // Finding Minimum edges
        for(int j=1;j<=n;j++){
            if(near[j] != 0){
                if(cost[j][near[j]] < min){
                    min = cost[j][near[j]];
                    k = j;
                }
            }
        }

        // Updating the table T
        T[0][i] = k;
        T[1][i] = near[k];
        near[k] = 0;

        // Comparing
        for(int j=1;j<=n;j++){
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]]){
                near[j] = k;
            }
        }
    }
    PrintMST(T, cost);
}

int main(){
    int cost[V][V] = {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
    PrimMST(cost, n);
    return 0;
}