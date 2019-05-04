#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,d[20],a[20],sum,ans,bit[20],dp[2000000],top[20];
vector<int> g[20];

bool check(int x){
    for(int i=0;i<n;i++){
        if(x&(1<<i)){
            bit[i]=1;
            top[i]=1;
        }
        else{
            bit[i]=0;
            top[i]=0;
        }
    }
    for(int i=0;i<n;i++){
        if(bit[i]){
            for(int j=0;j<g[i].size();j++){
                if(bit[g[i][j]]==0){
                    return false;
                }
                top[g[i][j]]=0;
            }
        }
    }
    return true;
}

int parent(int x){
    if(x==0){
        return 0;
    }
    if(bit[a[x]]==1){
        return false;
    }
    else{
        return parent(a[x]);
    }
}

int solve(int x){
    int res=0,f[20]={};
    ans=1000000000;
    for(int i=0;i<n;i++){
        if(top[i]==1){
            res+=d[i];
            for(int j=0;j<g[i].size();j++){
                f[i]+=d[g[i][j]];
            }
        }
    }
    for(int i=0;i<n;i++){
        if(top[i]==1){
            ans=min(ans,max(dp[x^(1<<i)],res+f[i]));
        }
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        a[i]--;
        g[a[i]].push_back(i);
    }
    for(int i=1;i<(1<<n);i++){
        if(check(i)){
            dp[i]=solve(i);
        }
    }
    printf("%d\n",dp[(1<<n)-1]);
}