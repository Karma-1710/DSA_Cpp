#include<bits/stdc++.h>
using namespace std;

int minComputation(int n, int files[]){
    priority_queue<int, vector<int>, greater<int>> pq; // acts as a Min heap 

    for(int i=0;i<n;i++){
        pq.push(files[i]);
    }
    int count = 0;

    while(pq.size() > 1){
        int first_element = pq.top();
        pq.pop();
        int second_element = pq.top();
        pq.pop();

        int temp = first_element + second_element;

        count+= temp;

        pq.push(temp);
    }

    return count;
}

int main(){
    int n = 5;
    int files[] = {5,10,20,30,30};
    cout << minComputation(n, files) << endl;
    return 0;
}