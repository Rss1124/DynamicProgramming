//动态规划训练

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
using namespace std;

long long int Fib(int n, long long int array[]); //斐波那契数列
long long int gridTraveler(int m,int r,int c,long long int array[]); //gridTraveler m表示二维数组的列数，r、c分别表示当前结点所处的行与列
int canAndHowSum(int target,int array[],int cS[],int n,int targetArray[],int m,int i,int &min,int tempArray[],int &tag); //canSum，target表示目标值，array[]内的元素用来凑target，cS是用来存储重复信息的仓库，targetArray是组成target的元素集合，m用来记录当前递归的深度
int Sort(int a[],int low,int high);
void QuickSort(int a[],int low,int high);

int main() {

/** 斐波那契数列 **/
//    long long int fA[255]={}; //fibArray
//    cout<<Fib(50,fA)<<endl;

/** gridTraveler **/
//    int r,c,n,m;
//    cout<<"请输入二维数组的行列:";
//    cin>>r>>c;
//    n=r*c;
//    m=c;
//    long long int *gTA=new long long int[n](); //gridTravelerArray
//    cout<<gridTraveler(m,r-1,c-1,gTA)<<endl; //m=3,r=2,c=3,n=6
//    return 0;

/** canAndHowSum **/
    int target,n,m=0,i=0,min,tag=0;
    cout<<"输入目标值和元素数组的大小:";
    cin>>target>>n;
    int *elem=new int[n];
    int *cS=new int[target]();
    int *targetArray=new int[target]();
    int *tempArray=new int[target]();
    for(int i=0;i<n;i++){
        int num;
        cout<<"输入数组的第"<<i+1<<"个元素:";
        cin>>num;
        elem[i]=num;
    }
    QuickSort(elem,0,n-1);
    min=target;
    canAndHowSum(target,elem,cS,n,targetArray,m,i,min,tempArray,tag);
    if(tag==1){
        for(int i=0;i<min;i++){
            if(tempArray[i]==0) break;
            cout<<tempArray[i]<<" ";
        }
    }
    else cout<<"null";
}

long long int Fib(int n, long long int array[]){
    if(array[n]!=0) return array[n];
    if(n<=2) return 1;
    array[n]=Fib(n-1,array)+Fib(n-2,array);
    return array[n];
}

long long int gridTraveler(int m,int r,int c, long long int array[]){  //m=3,r=1,c=2
    if(array[r*m+c]!=0&&(r>=0&&c>=0)) return array[r*m+c]; //二维数组表示一维数组：r*m+c
    if(r==0&&c==0) return array[r*m+c]=1;
    if(r<0||c<0) return 0;
    array[r*m+c]=gridTraveler(m,r,c-1,array)+gridTraveler(m,r-1,c,array);
    return array[r*m+c];
}

int canAndHowSum(int target,int array[],int cS[],int n,int targetArray[],int m,int i,int &min,int tempArray[],int &tag){

    m++;
    if(cS[target]==1){
        targetArray[m-1]=array[i];
    }
    if(cS[target]==-1) return 0;
    if(target==0) return 1;
    if(target<0) return 0;
    for(i=n-1;i>=0;i--){
        int temp;
        temp=target-array[i]; //target=8 array[1]=4 temp=4
        targetArray[m-1]=array[i];
        if(canAndHowSum(temp,array,cS,n,targetArray,m,i,min,tempArray,tag)==1){
            if(m<=min){
                min=m;
                memcpy(tempArray,targetArray, m * sizeof(int)); //此处要注意对数据长度（size）的处理
            }
            tag=1;
            cS[target]=1;
        }
    }
    cS[target]=-1;
    return 0;
}

int Sort(int a[],int low,int high){
    int pivot=a[low]; //第一个元素为数轴
    while (low<high){
        while(low<high&&a[high]>=pivot) --high;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot) ++low;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}

void QuickSort(int a[],int low,int high){
    if(low<high){
        int mid=Sort(a,low,high);
        QuickSort(a,low,mid-1);
        QuickSort(a,mid+1,high);
    }
}