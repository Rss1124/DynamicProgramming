#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int value[100000]{}, weight[100000]{}, dp[200000]{};
    int num, volume;
    int index=0;
    int w,v,s; //w:��Ʒ���� v:��Ʒ��ֵ s:��Ʒ����
    cin>>num>>volume;
    /** �����ر������Ϊ01���� **/
    while(num--){
        cin>>w>>v>>s;
        int k=1;
        /** ��s���"����ȡ��"(log2(s+1))��С��
         * ����: s=7 ���Բ�� {s=1, s=2, s=4}����С��,ÿ��С���ֱ���1��,2��,4����Ʒ,�����Ͱ�ԭ��Ҫ���7��С�����Ż�����3��С��
         * ����: s=16 ���Բ�� {s=1, s=2, s=4, s=8, s=1}���С��
        **/
        while(k<=s){
            index++;
            weight[index]=w*k;
            value[index]=v*k;
            s-=k;
            k=k<<1; //k����һλ
        }
        if(s>0){
            index++;
            weight[index]=w*s;
            value[index]=v*s;
        }
    }
    int n=index;
    /** 01���� **/
    for(int i=1;i<=n;i++){
        for(int j=volume;j>=weight[i];j--){
            dp[j]=max(dp[j], dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[volume];
}