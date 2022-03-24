#include <iostream>
using namespace std;

long long int Fib_byTree(int n, long long int array[]); //斐波那契数列
long long int Fib_byTable(long long int array[],int n);

int main(){
    /** 斐波那契数列_树型策略 **/
    long long int fA[255]={}; //fibArray
    cout<<Fib_byTree(50,fA)<<endl;

/** 斐波那契数列_表格策略 **/
    long long int array[255]={};
    array[1]=1;
    int n=50;
    cout<<Fib_byTable(array,n);
}

long long int Fib_byTree(int n, long long int array[]){
    if(array[n]!=0) return array[n];
    if(n<=2) return 1;
    array[n]=Fib_byTree(n-1,array)+Fib_byTree(n-2,array);
    return array[n];
}

long long int Fib_byTable(long long int array[],int n){
    for(int i=0;i<=n;i++){
        array[i+1]+=array[i]; //array[1]=array[1]+array[0] =>1
        array[i+2]+=array[i]; //array[2]=array[2]+array[0] =>1
    }
    return array[n];
}