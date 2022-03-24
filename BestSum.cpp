#include <iostream>
using namespace std;

typedef struct Array{
    int array[255]={};
    int length=0;
} Array ;

int canAndHowSum(int target,int array[],int cS[],int n,int targetArray[],int m,int i,int &min,int tempArray[],int &tag); //canSum��target��ʾĿ��ֵ��array[]�ڵ�Ԫ��������target��cS�������洢�ظ���Ϣ�Ĳֿ⣬targetArray�����target��Ԫ�ؼ��ϣ�m������¼��ǰ�ݹ�����
int bestSum_byTable(Array a[],int elem[],int target,int length);

int Sort(int a[],int low,int high);
void QuickSort(int a[],int low,int high);

int main(){
/** BestSum_byTree(�ݹ�ʵ�������⣩ **/
//    int target,n,m=0,i=0,min,tag=0;
//    cout<<"����Ŀ��ֵ��Ԫ������Ĵ�С:";
//    cin>>target>>n;
//    int *elem=new int[n];
//    int *cS=new int[target]();
//    int *targetArray=new int[target]();
//    int *tempArray=new int[target]();
//    for(int i=0;i<n;i++){
//        int num;
//        cout<<"��������ĵ�"<<i+1<<"��Ԫ��:";
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
    int pivot=a[low]; //��һ��Ԫ��Ϊ����
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
                memcpy(tempArray,targetArray, m * sizeof(int)); //�˴�Ҫע������ݳ��ȣ�size���Ĵ���
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
                        /** �Ƚϳ��� **/
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