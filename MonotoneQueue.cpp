#include "iostream"
#include "deque"
using namespace std;

void sliding(int a[], int output[], int &length, deque<int> &dq, int size);

int main(){
    int a[6]={8,7,6,9,2,4};
    int size=3;
    int *output;
    output=new int[(6-size)+(6/size)-1]{};
    deque<int>dq;
    int length=0;
    sliding(a,output,length,dq,size);
    for(int i=0;i<length;i++) cout<<output[i]<<" ";
}

void sliding(int a[], int output[], int &length, deque<int> &dq,int size){
    for(int i=0;i<6;i++){
        while(!dq.empty() && a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=size-1){
            while(!dq.empty() && dq.front()<i-size+1){
                dq.pop_front();
            }
            output[length]=a[dq.front()];
            length++;
        }
    }
}