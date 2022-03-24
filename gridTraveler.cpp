#include <iostream>
using namespace std;


long long int gridTraveler_byTree(int m,int r,int c,long long int array[]); //gridTraveler m表示二维数组的列数，r、c分别表示当前结点所处的行与列
long long int gridTraveler_byTable(int r,int c,long long int **array); //r、c分别表示当前结点所处的行与列

int main(){
/** gridTraveler_byTree **/
//    int r,c,n,m;
//    cout<<"请输入二维数组的行列:";
//    cin>>r>>c;
//    n=r*c;
//    m=c;
//    long long int *gTA=new long long int[n](); //gridTravelerArray
//    cout<<gridTraveler_byTree(m,r-1,c-1,gTA); //m=3,r=2,c=3,n=6
//    return 0;

/** gridTraveler_byTable **/
    int r,c;
    long long int **array; //array[r][c]
    cout<<"请输入二维数组的行列:";
    cin>>r>>c;
    array = new long long int*[r];
    for(int i=0;i<r;i++){
        array[i]= new long long int[c]{}; //二维数组初始化
    }
    array[0][0]=1;
    cout<<gridTraveler_byTable(r,c,array);
}

long long int gridTraveler_byTree(int m,int r,int c, long long int array[]){  //m=3,r=1,c=2
    if(array[r*m+c]!=0&&(r>=0&&c>=0)) return array[r*m+c]; //二维数组表示一维数组：r*m+c
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