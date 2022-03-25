#include <iostream>
using namespace std;

typedef struct Things{
    int value;
    int weight;
}T;

void ZeroOneBag(T arrayThings[], long long int **dp, int target, int num);

int main() {
    int target, num;
    cin>>num>>target;
    T *arrayThings;
    long long int **dp;
    dp = new long long int*[num+1]{};
    for(int i=0;i<num+1;i++) dp[i] = new long long int[target+1]{};
    arrayThings = new T[num+1]{};
    for(int i=1;i<num+1;i++){
        int weight, value;
        cin>>weight>>value;
        arrayThings[i].weight=weight;
        arrayThings[i].value=value;
    }
    ZeroOneBag(arrayThings, dp, target, num);
//    for(int i=0;i<num+1;i++){
//        for(int j=0;j<target+1;j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<dp[num][target];
}

void ZeroOneBag(T arrayThings[], long long int **dp, int target, int num){
    for(int i=1;i<num+1;i++){ //arrayThings的下标
        for(int j=1;j<target+1;j++){ //背包体积
            if(arrayThings[i].weight<=j){
                if(arrayThings[i].value + dp[i-1][j-arrayThings[i].weight] > dp[i-1][j]){
                    dp[i][j] = arrayThings[i].value + dp[i-1][j-arrayThings[i].weight];
                }
                else dp[i][j] =  dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
}
