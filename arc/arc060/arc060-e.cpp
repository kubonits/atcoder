#include<cstdio>
using namespace std;
int n,l,q,x[100001],a,b,dp[17][100001],ans;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    x[n]=x[n-1]+l+1;
    scanf("%d",&l);
    int p;
    p=1;
    for(int i=0;i<n;i++){
        while(x[p]<=x[i]+l&&p<n){
            p++;
        }
        dp[0][i]=p-1;
    }
    dp[0][n]=dp[0][n-1]=n;
    for(int i=1;i<17;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d %d",&a,&b);
        a--;
        b--;
        if(a>b){
            a^=b;
            b^=a;
            a^=b;
        }
        ans=0;
        p=a;
        for(int j=16;j>=0;j--){
            if(dp[j][p]<=b){
                ans+=(1<<j);
                p=dp[j][p];
            }
        }
        if(p!=b){
            ans++;
        }
        printf("%d\n",ans);
    }
}