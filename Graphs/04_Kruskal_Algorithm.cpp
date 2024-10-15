#include<iostream>
#define V 7
#define I 32767
#define E 9
using namespace std;

void Union(int u, int v, int S[]){
    if(S[u] < S[v]){
        S[u] = S[u] + S[v];
        S[v] = u;
    }else{
        S[v] = S[v] +S[u];
        S[u] = v;
    }
};

int Find(int u, int S[]){
    int x = u;
    while(S[x] > 0){
        x = S[x];
    }

    return x;
}

void PrintMST(int T[2][V-1], int edges[][E]){
    cout << "Minimum cost spanning tree: " << endl;
    for(int i=0;i<V-1;i++){
        cout << "[" << T[0][i] << "]---[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}

void KruskalMST(int edges[3][9]){
    int T[2][V-1];
    int included[E] = {0};
    int set[V+1] = {-1};

    int i = 0;
    
    //Repeating till we get all minimum edges
    while(i < V-1){
        int min = I;
        int u = 0;
        int v = 0;
        int k = 0;
        for(int j =0; j<E;j++){
            if(included[j] == 0 && edges[2][j] < min){
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }

        if(Find(u, set) != Find(v, set)){
            T[0][i] = u;
            T[1][i] = v;

            Union(Find(u, set), Find(v, set), set);
            i++;
        }
        included[k] = 1;
    }
    PrintMST(T, edges);
}



int main(){
    int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
    KruskalMST(edges);
    return 0;
}