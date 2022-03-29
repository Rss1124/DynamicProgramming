#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int value[100000]{}, weight[100000]{}, dp[200000]{};
    int num, volume;
    int index=0;
    int w,v,s; //w:物品重量 v:物品价值 s:物品数量
    cin>>num>>volume;
    /** 将多重背包拆解为01背包 **/
    while(num--){
        cin>>w>>v>>s;
        int k=1;
        /** 将s拆成"向上取整"(log2(s+1))个小包
         * 举例: s=7 可以拆成 {s=1, s=2, s=4}三个小包,每个小包分别有1个,2个,4个物品,这样就把原来要拆成7个小包给优化成了3个小包
         * 举例: s=16 可以拆成 {s=1, s=2, s=4, s=8, s=1}五个小包
        **/
        while(k<=s){
            index++;
            weight[index]=w*k;
            value[index]=v*k;
            s-=k;
            k=k<<1; //k左移一位
        }
        if(s>0){
            index++;
            weight[index]=w*s;
            value[index]=v*s;
        }
    }
    int n=index;
    /** 01背包 **/
    for(int i=1;i<=n;i++){
        for(int j=volume;j>=weight[i];j--){
            dp[j]=max(dp[j], dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[volume];
}