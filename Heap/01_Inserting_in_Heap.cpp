#include<iostream>
#include<vector>
using namespace std;

void Insert(vector<int>& vec, int key){
    auto i = vec.size();
    vec.emplace_back(key);
    while(i > 0 && key > vec[i%2 == 0 ? (i/2)-1 : i/2]){
        vec[i] = vec[i%2 == 0 ? (i/2)-1 : i/2];
        i = i%2 == 0 ? (i/2)-1 : i/2;
    }
    vec[i] = key;
}

void Print(vector<int>& vec, int n){
    cout << "Max Heap: [" << flush;
    for(int i=0;i<n;i++){
        cout << vec[i] << " " << flush;
    }
    cout << "]" << endl;
}

int main() {
    vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
    v.reserve(15);
    Insert(v, 50);
    Print(v, v.size());
    return 0;
}