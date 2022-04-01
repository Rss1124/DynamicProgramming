#include "iostream"
using namespace std;

int main(){
    const int N = 1010, M = 20010;
    int n,m;
    int v[N], w[N], s[N];
    int f[N][M];
    int q[M];
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];
    for(int i=1;i<=n;i++){
        for(int r=0;r<v[i];r++){
            int h=0,t=-1;
            for(int j=r;j<=m;j+=v[i]){
                while(h<=t && j-q[h]>s[i]*v[i]) h++;
                while(h<=t && f[i-1][q[t]] + (j-q[t])/v[i]*w[i] <= f[i-1][j]) t--;
                q[++t] = j;
                f[i][j]=f[i-1][q[t]] + (j-q[t])/v[i]*w[i];
            }
        }
    }
    cout<<f[n][m];
}
