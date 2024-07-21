#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
        char id;
        int profit;
        int deadline;
};

bool compare(Job a, Job b){
    return a.profit > b.profit;
};

void printJobSchedule(Job arr[], int n){
    sort(arr, arr+n, compare);
    int result[n];
    bool slot[n] = {false};

    for(int i=0;i<n;i++){
        for(int j = min(n,arr[i].deadline)-1;j>=0;j--){
            if(slot[j] == false){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(slot[i]){
            cout << arr[result[i]].id << " ";
        }
    }
}

int main(){
    Job arr[] = {{'a',20,2},
                {'b',15,2},
                {'c',10,1},
                {'d',5,3},
                {'e',1,3}};

    int n = sizeof(arr)/sizeof(arr[0]);
    printJobSchedule(arr, n);
    return 0;
}