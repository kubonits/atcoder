#include<cstdio>
#include<algorithm>
using namespace std;
int dp[5001][5001][2][2],to[5001],from[5001],a[5001],b[5001];

void dfs(int x,int y){
    a[x]=y;
    if(to[x]==y){
        return ;
    }
    dfs(to[x],y);
}
int main(){
    int n,k,x,cnt=0,y,ans=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        to[a[i]]=b[i];
        from[b[i]]=a[i];
    }
    for(int i=0;i<=n;i++){
        a[i]=i;
        b[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==i){
            dfs(i,i);
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==i){
            x=i;
            while(to[x]!=i){
                for(int j=0;j<n;j++){
                    if(x==i){
                        y=max(dp[cnt][j][0][0],dp[cnt][j][0][1]);
                        y=max(y,dp[cnt][j][1][0]);
                        y=max(y,dp[cnt][j][1][1]);
                        if(y||cnt==0&&j==0){
                            dp[cnt+1][j+1][0][0]=y+x;
                            dp[cnt+1][j+1][1][1]=y+to[x];
                        }
                    }
                    else{
                        if(dp[cnt][j][0][0]){
                            dp[cnt+1][j+1][0][0]=max(dp[cnt+1][j+1][0][0],dp[cnt][j][0][0]+x);
                            dp[cnt+1][j+1][0][1]=max(dp[cnt+1][j+1][0][1],dp[cnt][j][0][0]+to[x]);
                        }
                        if(dp[cnt][j][0][1]){
                            dp[cnt+1][j][0][0]=max(dp[cnt+1][j][0][0],dp[cnt][j][0][1]+x);
                            dp[cnt+1][j+1][0][1]=max(dp[cnt+1][j+1][0][1],dp[cnt][j][0][1]+to[x]);
                        }
                        if(dp[cnt][j][1][0]){
                            dp[cnt+1][j+1][1][0]=max(dp[cnt+1][j+1][1][0],dp[cnt][j][1][0]+x);
                            dp[cnt+1][j+1][1][1]=max(dp[cnt+1][j+1][1][1],dp[cnt][j][1][0]+to[x]);
                        }
                        if(dp[cnt][j][1][1]){
                            dp[cnt+1][j][1][0]=max(dp[cnt+1][j][1][0],dp[cnt][j][1][1]+x);
                            dp[cnt+1][j+1][1][1]=max(dp[cnt+1][j+1][1][1],dp[cnt][j][1][1]+to[x]);
                        }
                    }
                }
                x=to[x];
                cnt++;
            }
            if(x==to[x]){
                for(int j=0;j<n;j++){
                    y=max(dp[cnt][j][0][0],dp[cnt][j][0][1]);
                    y=max(y,dp[cnt][j][1][0]);
                    y=max(y,dp[cnt][j][1][1]);
                    if(y||cnt==0){
                        dp[cnt+1][j+1][0][0]=y+x;
                    }
                }
            }
            else{
                for(int j=0;j<n;j++){
                    if(dp[cnt][j][0][0]){
                        dp[cnt+1][j+1][0][0]=max(dp[cnt+1][j+1][0][0],dp[cnt][j][0][0]+x);
                        dp[cnt+1][j][0][1]=max(dp[cnt+1][j][0][1],dp[cnt][j][0][0]+to[x]);
                    }
                    if(dp[cnt][j][0][1]){
                        dp[cnt+1][j][0][0]=max(dp[cnt+1][j][0][0],dp[cnt][j][0][1]+x);
                        dp[cnt+1][j][0][1]=max(dp[cnt+1][j][0][1],dp[cnt][j][0][1]+to[x]);
                    }
                    if(dp[cnt][j][1][0]){
                        dp[cnt+1][j+1][1][0]=max(dp[cnt+1][j+1][1][0],dp[cnt][j][1][0]+x);
                        dp[cnt+1][j+1][1][1]=max(dp[cnt+1][j+1][1][1],dp[cnt][j][1][0]+to[x]);
                    }
                    if(dp[cnt][j][1][1]){
                        dp[cnt+1][j][1][0]=max(dp[cnt+1][j][1][0],dp[cnt][j][1][1]+x);
                        dp[cnt+1][j+1][1][1]=max(dp[cnt+1][j+1][1][1],dp[cnt][j][1][1]+to[x]);
                    }
                }
            }
            cnt++;
        }
    }
    for(int i=k;i<=n;i++){
        ans=max(ans,dp[n][i][0][0]);
        ans=max(ans,dp[n][i][0][1]);
        ans=max(ans,dp[n][i][1][0]);
        ans=max(ans,dp[n][i][1][1]);
    }
    printf("%d\n",ans);
}