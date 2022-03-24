#include <iostream>
using namespace std;

typedef struct Array{
    int array[255]={};
    int length=0;
} Array ;

int canAndHowSum(int target,int array[],int cS[],int n,int targetArray[],int m,int i,int &min,int tempArray[],int &tag); //canSum，target表示目标值，array[]内的元素用来凑target，cS是用来存储重复信息的仓库，targetArray是组成target的元素集合，m用来记录当前递归的深度
int bestSum_byTable(Array a[],int elem[],int target,int length);

int Sort(int a[],int low,int high);
void QuickSort(int a[],int low,int high);

int main(){
/** BestSum_byTree(递归实现有问题） **/
//    int target,n,m=0,i=0,min,tag=0;
//    cout<<"输入目标值和元素数组的大小:";
//    cin>>target>>n;
//    int *elem=new int[n];
//    int *cS=new int[target]();
//    int *targetArray=new int[target]();
//    int *tempArray=new int[target]();
//    for(int i=0;i<n;i++){
//        int num;
//        cout<<"输入数组的第"<<i+1<<"个元素:";
//        cin>>num;
//        elem[i]=num;
//    }
//    QuickSort(elem,0,n-1);
//    min=target;
//    canAndHowSum(target,elem,cS,n,targetArray,m,i,min,tempArray,tag);
//    if(tag==1){
//        for(int i=0;i<min;i++){
//            if(tempArray[i]==0) break;
//            cout<<tempArray[i]<<" ";
//        }
//    }
//    else cout<<"null";

/** BestSum_byTable **/
    Array a[255]={};
    int elem[4]={1,2,5,25};
    int target=100;
    int lengthArray=sizeof(elem)/sizeof(elem[0]);
    bestSum_byTable(a,elem,target,lengthArray);
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

int bestSum_byTable(Array a[],int elem[],int target,int length){
    for(int i=0;i<target+1;i++){
        if(i==0){
            for(int j=0;j<length;j++){
                a[i+elem[j]].array[a[i+elem[j]].length]=elem[j];
                a[i+elem[j]].length++;
            }
        }
        else{
            if(a[i].length!=0){
                for(int j=0;j<length;j++){
                    if(i+elem[j]<target+1){
                        /** 比较长度 **/
                        if(a[i].length+1<=a[i+elem[j]].length&&a[i+elem[j]].length!=0){
                            a[i+elem[j]].length=a[i].length;
                            for(int k=0;k<a[i].length;k++){
                                a[i+elem[j]].array[k]=a[i].array[k];
                            }
                            a[i+elem[j]].array[a[i+elem[j]].length]=elem[j];
                            a[i+elem[j]].length++;
                        }
                        else if(a[i].length>=a[i+elem[j]].length+1&&a[i+elem[j]].length!=0);
                        else{
                            a[i+elem[j]].length=a[i].length;
                            for(int k=0;k<a[i].length;k++){
                                a[i+elem[j]].array[k]=a[i].array[k];
                            }
                            a[i+elem[j]].array[a[i+elem[j]].length]=elem[j];
                            a[i+elem[j]].length++;
                        }
                    }
                }
            }
        }
    }
    for(int k=0;k<=a[target].length-1;k++){
        cout<<a[target].array[k]<<" ";
    }
}