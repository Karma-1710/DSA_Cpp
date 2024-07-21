#include<bits/stdc++.h>
using namespace std;

void maxProfit(vector<int> profit, vector<int> weight, int N){
    int noofElements = profit.size();
    int i;

    multimap<double, int> ratio;

    for(i=0;i<noofElements;i++){
        ratio.insert(make_pair((double)profit[i]/weight[i], i));
    }
    double max_profit = 0;
    multimap<double, int>::reverse_iterator itr;

    for(itr = ratio.rbegin();itr!=ratio.rend();itr++){
        double fraction = (double)N/weight[itr->second];
        if(N >= 0 && N >= weight[itr->second]){
            max_profit += profit[itr->second];
            N -= weight[itr->second];
        }else if(N < weight[itr->second]){
            max_profit += fraction *  profit[itr->second];
            break;
        }
    }

    cout << max_profit << endl;
}

int main(){
    int size = 4;
    vector<int> profit(size);
    vector<int> weight(size);
    int N = 60; // capacity

    profit[0] = 100, profit[1] = 280, 
    profit[2] = 120, profit[3] = 120; 
  
    // Weight of items 
    weight[0] = 10, weight[1] = 40, 
    weight[2] = 20, weight[3] = 24;
    maxProfit(profit, weight, N);
    return 0;
}