//动态规划训练

#include <iostream>
#include <map>
#include <string>
using namespace std;

long long int Fib(int n, long long int array[]); //斐波那契数列

int main() {
    long long int fibArray[255]={};
    cout<<Fib(50,fibArray)<<endl;
    return 0;
}

long long int Fib(int n, long long int array[]){
    if(array[n]!=0) return array[n];
    if(n<=2) return 1;
    array[n]=Fib(n-1,array)+Fib(n-2,array);
    return array[n];
}