#include<cstdio>
#include<algorithm>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll dp[201][100001]={},n,ans=0;
int x,s[200];
int main(){
    scanf("%lld %d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    dp[0][x]=1;
    sort(s,s+n);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=x;j++){
            if(dp[i][j]){
                for(ll k=0;k<n;k++){
                    if(s[k]>j){
                        dp[i+1][j]+=dp[i][j]*(n-k-i);
                        dp[i+1][j]%=mod;
                        break;
                    }
                    else{
                        dp[i+1][j%s[k]]+=dp[i][j];
                        dp[i+1][j%s[k]]%=mod;
                    }
                }
            }
        }
    }
    for(ll i=0;i<=x;i++){
        ans+=i*dp[n][i];
        ans%=mod;
    }
    printf("%lld\n",ans);
}