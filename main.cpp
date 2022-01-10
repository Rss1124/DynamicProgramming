//��̬�滮ѵ��

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

typedef struct Array{
    int array[255]={};
    int length=0;
} Array ;

long long int Fib_byTree(int n, long long int array[]); //쳲���������
long long int Fib_byTable(long long int array[],int n);
long long int gridTraveler_byTree(int m,int r,int c,long long int array[]); //gridTraveler m��ʾ��ά�����������r��c�ֱ��ʾ��ǰ���������������
long long int gridTraveler_byTable(int r,int c,long long int **array); //r��c�ֱ��ʾ��ǰ���������������
int canAndHowSum(int target,int array[],int cS[],int n,int targetArray[],int m,int i,int &min,int tempArray[],int &tag); //canSum��target��ʾĿ��ֵ��array[]�ڵ�Ԫ��������target��cS�������洢�ظ���Ϣ�Ĳֿ⣬targetArray�����target��Ԫ�ؼ��ϣ�m������¼��ǰ�ݹ�����
int bestSum_byTable(Array a[],int elem[],int target,int length);
int Sort(int a[],int low,int high);
void QuickSort(int a[],int low,int high);
bool canConstruct(string target,string array[],int length,map<string,bool> &memo);
int countConstruct(string target,string array[],int length,map<string,int> &memo);

int main() {

/** 쳲���������_���Ͳ��� **/
//    long long int fA[255]={}; //fibArray
//    cout<<Fib(50,fA)<<endl;

/** 쳲���������_������ **/
//    long long int array[255]={};
//    array[1]=1;
//    int n=50;
//    cout<<Fib_byTable(array,n);

/** gridTraveler_byTree **/
//    int r,c,n,m;
//    cout<<"�������ά���������:";
//    cin>>r>>c;
//    n=r*c;
//    m=c;
//    long long int *gTA=new long long int[n](); //gridTravelerArray
//    cout<<gridTraveler_byTree(m,r-1,c-1,gTA); //m=3,r=2,c=3,n=6
//    return 0;

/** gridTraveler_byTable **/
//    int r,c;
//    long long int **array; //array[r][c]
//    cout<<"�������ά���������:";
//    cin>>r>>c;
//    array = new long long int*[r];
//    for(int i=0;i<r;i++){
//        array[i]= new long long int[c]{}; //��ά�����ʼ��
//    }
//    array[0][0]=1;
//    cout<<gridTraveler_byTable(r,c,array);

/** BestSum_byTree **/
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

/** canConstruct **/
//    string target="abcdef";
//    string array[]={"ab","abc","cd","def","abcd"};
//    string target="skateboard";
//    string array[]={"bo","rd","ate","t","ska","sk","boar"};
//    string target="enterapotentpot";
//    string array[]={"a","p","ent","enter","ot","o","t"};
//    string target="eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
//    string array[]={"e","ee","eee","eeee","eeeee","eeeeee"};
//    map<string,bool> memo;
//    int length=sizeof(array)/sizeof(array[0]);
//    cout<<canConstruct(target,array,length,memo);

/** countConstruct **/
////    string target="purple";
////    string array[]={"purp","p","ur","le","purpl"};
////    string target="abcdef";
////    string array[]={"ab","abc","cd","def","abcd"};
////    string target="enterapotentpot";
////    string array[]={"a","p","ent","enter","ot","o","t"};
//    string target="eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
//    string array[]={"e","ee","eee","eeee","eeeee","eeeeee"};
//    map<string,int> memo;
//    int length=sizeof(array)/sizeof(array[0]);
//    cout<<countConstruct(target,array,length,memo);

}

long long int Fib(int n, long long int array[]){
    if(array[n]!=0) return array[n];
    if(n<=2) return 1;
    array[n]=Fib(n-1,array)+Fib(n-2,array);
    return array[n];
}

long long int Fib_byTable(long long int array[],int n){
    for(int i=0;i<=n;i++){
        array[i+1]+=array[i]; //array[1]=array[1]+array[0] =>1
        array[i+2]+=array[i]; //array[2]=array[2]+array[0] =>1
    }
    return array[n];
}

long long int gridTraveler_byTree(int m,int r,int c, long long int array[]){  //m=3,r=1,c=2
    if(array[r*m+c]!=0&&(r>=0&&c>=0)) return array[r*m+c]; //��ά�����ʾһά���飺r*m+c
    if(r==0&&c==0) return array[r*m+c]=1;
    if(r<0||c<0) return 0;
    array[r*m+c]=gridTraveler_byTree(m,r,c-1,array)+gridTraveler_byTree(m,r-1,c,array);
    return array[r*m+c];
}

long long int gridTraveler_byTable(int r,int c,long long int **array){
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            if(i+1<r) array[i+1][j]=array[i+1][j]+array[i][j];
            if(j+1<c) array[i][j+1]=array[i][j+1]+array[i][j];
        }
    }
    return array[r-1][c-1];
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

bool canConstruct(string target,string array[],int length,map<string,bool> &memo){
    map<string,bool> ::iterator find;
    if(target=="") return true;
    if((find=memo.find(target))!=memo.end()) return find->second;
    for(int i=0;i<length;i++){
        if(target.find(array[i])==0){
            string str=target.substr(array[i].length());
            if(canConstruct(str,array,length,memo)==true) {
                memo.insert(pair<string,bool>(target, true));
                return true;
            }
        }
    }
    memo.insert(pair<string,bool>(target,false));
    return false;
}

int countConstruct(string target,string array[],int length,map<string,int> &memo){
    map<string,int> ::iterator find;
    if(target=="") return 1;
    if((find=memo.find(target))!=memo.end()) return find->second;
    int totalNum = 0;
    for(int i=0;i<length;i++){
        if(target.find(array[i])==0){
            string str=target.substr(array[i].length());
            totalNum+=countConstruct(str,array,length,memo);
            memo.insert(pair<string,int>(target, totalNum));
        }
    }
    memo.insert(pair<string,int>(target, totalNum));
    return totalNum;
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
