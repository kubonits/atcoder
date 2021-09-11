#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
#include<queue>
#define mod 1000000007
#define INF 1000000000000000
using namespace std;
typedef long long ll;
int a[100001];
int main(){
    int n,m,b;
    ll dp[100005]={};
    dp[0]=1LL;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&b);
        a[b]=1;
    }
    for(int i=0;i<n;i++){
        if(a[i]==1){
            dp[i]=0;
        }
        dp[i]%=mod;
        if(a[i+1]==0){
            dp[i+1]+=dp[i];
            dp[i+1]%=mod;
        }
        if(a[i+2]==0){
            dp[i+2]+=dp[i];
            dp[i+2]%=mod;
        }
    }
    printf("%lld\n",dp[n]);
}