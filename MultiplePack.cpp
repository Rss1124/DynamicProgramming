#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int value[10005]{}, weight[10005]{}, dp[10005]{};
    int num, volume;
    int index=0;
    int w,v,s; //w:��Ʒ���� v:��Ʒ��ֵ s:��Ʒ����
    cin>>num>>volume;
    /** �����ر������Ϊ01���� **/
    while(num--){
        cin>>w>>v>>s;
        while(s--){
            value[++index]=v;
            weight[index]=w;
        }
    }
    /** 01���� **/
    for(int i=1;i<=index;i++){
        for(int j=volume;j>=weight[i];j--){
            dp[j]=max(dp[j], dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[volume];
}