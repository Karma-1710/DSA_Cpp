#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Item{
    int profit, weight;

    Item(int profit, int weight){
        this->profit = profit;
        this->weight = weight;
    }
};

bool compare(struct Item a, struct Item b){
    double r1 = (double) a.profit/a.weight;
    double r2 = (double) b.profit/b.weight;

    return r1 > r2;
}

double fractionalKnapsack(struct Item arr[], int N, int size){
    // Sorting the array based on compare factor
    sort(arr, arr + size, compare);

    int currentWt = 0;

    double finalProfit = 0.0;
    for(int i=0;i<N;i++){
        if(currentWt + arr[i].weight <= N){
            currentWt += arr[i].weight;
            finalProfit += arr[i].profit;
        }else{
            int remain = N - currentWt;
            finalProfit += arr[i].profit * ((double)remain/arr[i].weight);

            break;
        }
    }
    return finalProfit;
}

int main(){
    // Capacity of Knapsack
    int N = 60;
    Item arr[] = { { 100, 10 }, 
                   { 280, 40 }, 
                   { 120, 20 }, 
                   { 120, 24 } };
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << fractionalKnapsack(arr,N, size) << endl;

    return 0;
}