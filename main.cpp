//��̬�滮ѵ��

#include <iostream>
#include <map>
#include <string>
using namespace std;

long long int Fib(int n, long long int array[]); //쳲���������
long long int gridTraveler(int m,int r,int c,long long int array[]); //gridTraveler m��ʾ��ά�����������r��c�ֱ��ʾ��ǰ���������������

int main() {

/** 쳲��������� **/
//    long long int fA[255]={}; //fibArray
//    cout<<Fib(50,fA)<<endl;

/** gridTraveler **/
    int r,c,n,m;
    cout<<"�������ά���������:";
    cin>>r>>c;
    n=r*c;
    m=c;
    long long int *gTA=new long long int[n](); //gridTravelerArray
    cout<<gridTraveler(m,r-1,c-1,gTA)<<endl; //m=3,r=2,c=3,n=6
    return 0;
}

long long int Fib(int n, long long int array[]){
    if(array[n]!=0) return array[n];
    if(n<=2) return 1;
    array[n]=Fib(n-1,array)+Fib(n-2,array);
    return array[n];
}

long long int gridTraveler(int m,int r,int c, long long int array[]){  //m=3,r=1,c=2
    if(array[r*m+c]!=0&&(r>=0&&c>=0)) return array[r*m+c]; //��ά�����ʾһά���飺r*m+c
    if(r==0&&c==0) return array[r*m+c]=1;
    if(r<0||c<0) return 0;
    array[r*m+c]=gridTraveler(m,r,c-1,array)+gridTraveler(m,r-1,c,array);
    return array[r*m+c];
}