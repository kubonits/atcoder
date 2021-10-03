#include<cstdio>
#include<algorithm>
using namespace std;
int dp[5001][10011];
int main(){
    int n,m,a[9],f[8]={},keta=0,b[10]={0,2,5,5,4,5,6,3,7,6};
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
        if(a[i]==1){
            f[2]=1;
        }
        else if(a[i]==7){
            f[3]=7;
        }
        else if(a[i]==4){
            f[4]=4;
        }
        else if(a[i]==2||a[i]==3||a[i]==5){
            f[5]=max(f[5],a[i]);
        }
        else if(a[i]==9||a[i]==6){
            f[6]=max(a[i],f[6]);
        }
        else{
            f[7]=8;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<5000;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]){
                for(int k=2;k<8;k++){
                    if(f[k]){
                        dp[i+1][j+k]=max(dp[i+1][j+k],f[k]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=5000;i++){
        if(dp[i][n]){
            keta=i;
        }
    }
    for(int i=keta;i>0;i--){
        printf("%d",dp[i][n]);
        n-=b[dp[i][n]];
    }
    printf("\n");
}