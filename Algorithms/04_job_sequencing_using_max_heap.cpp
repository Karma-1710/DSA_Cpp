#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
        char id;
        int deadline;
        int profit;
};

class jobProfit{
    public:
        bool operator()(Job const& a,Job const& b){
            return (a.profit < b.profit); // ascending order
        }
};

void printJobScheduling(Job arr[], int n){
    vector<Job> result;
    sort(arr, arr+n, [](Job a, Job b){return a.deadline < b.deadline;});

    priority_queue<Job, vector<Job>, jobProfit> pq;

    for(int i=n-1;i>=0;i--){
        int slot_available;

        if(i == 0){
            slot_available = arr[i].deadline;
        }else{  
            slot_available = arr[i].deadline - arr[i-1].deadline;
        }

        pq.push(arr[i]);

        while(slot_available > 0 && pq.size() > 0){
            Job job = pq.top();
            pq.pop();

            slot_available--;

            result.push_back(job);
        }
    }

    sort(result.begin(), result.end(), [&](Job a, Job b){return a.deadline < b.deadline;});

    for(int i=0;i<result.size();i++){
        cout << result[i].id << " ";
    }
}

int main(){
    Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
   
    int n = sizeof(arr) / sizeof(arr[0]);
    printJobScheduling(arr, n);
    return 0;
}