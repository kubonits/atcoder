#include<cstdio>
using namespace std;
int n,k,a[100],dp[2][100001];
int dfs(int p,int x){
    int y;
    if(dp[p][x]){
        return dp[p][x];
    }
    if(x<a[n-1]){
        if(p){
            dp[p][x]=1;
            return 1;
        }
        else{
            dp[p][x]=-1;
            return -1;
        }
    }
    for(int i=0;i<n;i++){
        if(x>=a[i]){
            y=dfs((p+1)%2,x-a[i]);
            if(y==1&&p==0){
                dp[p][x]=y;
                return y;
            }
            if(y==-1&&p==1){
                dp[p][x]=y;
                return y;
            }
        }
    }
    if(p){
        dp[p][x]=1;
        return 1;
    }
    else{
        dp[p][x]=-1;
        return -1;
    }
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[n-1-i]);
    }
    if(dfs(0,k)==1){
        printf("First\n");
    }
    else{
        printf("Second");
    }
}