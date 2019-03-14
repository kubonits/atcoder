#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,t[5010],dp[5010][5010]={},l=0;
int main(){
    
    scanf("%d %d",&n,&x);
    t[0]=-x;
    for(int i=0;i<n;i++){
        scanf("%d",&t[i+1]);
    }
    for(int i=1;i<=n;i++){
        while(l<i-1&&t[l]+x<t[i]){
            l++;
        }
        for(int j=0;j<n;j++){
            if(l==0){
                dp[i][j+1]=dp[l][j]+min(x,t[i]-t[l]);
            }
            else{
                dp[i][j+1]=max(dp[l][j]+min(x,t[i]-t[l]),dp[l-1][j]+min(x,t[i]-t[l-1]));
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",dp[n][i]);
    }
}