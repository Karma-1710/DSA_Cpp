#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

// int main(){
//     char A[] = "findingfinding";
//     int i,j;

//     for(i=0;A[i]!='\0';i++){
//         int count = 1;
//         if(A[i] != -1){
//             for(j=i+1;A[j]!='\0';j++){
//                 if(A[i] == A[j]){
//                     count++;
//                     A[j] = -1;
//                 }
//             }
//             if(count > 1){
//                 cout << "Character " << A[i] << " is appearing " << count << " times" << endl;
//             }
//         }
//     }
//     return 0;
// }

// Using HashMap

int main(){
    char A[] = "finding";
    int len = strlen(A);

    unordered_map<char, int> charCount;
    for(int i=0;i<len;i++){
        charCount[A[i]]++;
    }

    for(auto itr = charCount.begin();itr != charCount.end();itr++){
        if(itr->second > 1){
            cout << "Character " << itr->first << " is appearing " << itr->second << " times" << endl;
        }
    }
    return 0;
}