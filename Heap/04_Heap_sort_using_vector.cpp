#include<iostream>
#include<vector>
using namespace std;

void Insert(vector<int>& v, int key){
    auto i = v.size();
    v.emplace_back(key);
    while(i>0 && key > v[i%2 == 0 ? (i/2)-1 : i/2]){
        v[i] = v[i%2 == 0 ? (i/2)-1 : i/2];
        i = i%2 == 0 ? (i/2)-1 : i/2;
    }
    v[i] = key;
}

void CreateHeap(vector<int>& v,int H[], int n){
    for(int i=0;i<n;i++){
        Insert(v,H[i]);
    }
}

void Print(vector<int>& v, int n){
    for(int i=0;i<n;i++){
        cout << v[i] << " " << flush;
    }
}

int Delete(vector<int>& v, int n){
    int i, j, x, val, temp;
    val = v[0];
    x = v[n];
    v[0] = v[n];
    v[n] = val;
    i = 0;
    j = 2*i + 1;
    while(j < n){
        if(j<n-1 && v[j+1] > v[j]){
            j+=1;
        }
        if(v[i] < v[j]){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i=j;
            j = 2*i+1;
        }else{
            break;
        }
    }    
    return val;
}

int main(){
    int H[] = {14,15,5,20,30,8,40};
    int n = sizeof(H)/sizeof(H[0]);

    vector<int> v;
    CreateHeap(v,H,n);
    Print(v,n);

    for(int i=n-1;i>0;i--){
        Delete(v, i);
    }
    cout << endl;
    Print(v, n);
    return 0;
}