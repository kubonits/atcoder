#include<cstdio>
#define mod 1000000007
using namespace std;
int n,a[21][21],two[22];
long long dp[5000000];

long long dfs(int x,int y){
    if(dp[y]!=-1){
        return dp[y];
    }
    if(x==n){
        return 1;
    }
    dp[y]=0;
    for(int i=0;i<n;i++){
        if(a[x][i]==1&&(y&two[i])){
            dp[y]+=dfs(x+1,(y^two[i]));
            dp[y]%=mod;
        }
    }
    return dp[y];
}
int main(){
    scanf("%d",&n);
    two[0]=1;
    for(int i=1;i<=n;i++){
        two[i]=2*two[i-1];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<two[n];i++){
        dp[i]=-1;
    }
    dp[0]=1;
    dfs(0,two[n]-1);
    printf("%lld\n",dp[two[n]-1]);
}