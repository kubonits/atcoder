#include<cstdio>
using namespace std;
typedef long long ll;
#define mod 1000000007
int x,y,z,n,a,b,c,f;
ll dp[41][(1<<17)]={},ans;
int main(){
    scanf("%d %d %d %d",&n,&x,&y,&z);
    a=1<<(17);
    dp[0][0]=1;
    ans=1;
    for(int i=0;i<n;i++){
        ans*=10;
        ans%=mod;
    }
    b=1;
    b=b<<x;
    b+=1;
    b=b<<y;
    b+=1;
    b=b<<(z-1);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<a;j++){
            if(j&(1<<(x+y+z-1))&&j&(1<<(y+z-1))&&j&(1<<(z-1)));
            else{
                for(ll k=1;k<=10;k++){
                    dp[i+1][((j<<k)%(a))+(1<<(k-1))]+=dp[i][j];
                    dp[i+1][((j<<k)%(a))+(1<<(k-1))]%=mod;
                }
            }
        }
    }
    for(int i=0;i<a;i++){
        if(i&(1<<(x+y+z-1))&&i&(1<<(y+z-1))&&i&(1<<(z-1)));
        else{
            ans+=mod-dp[n][i];
            ans%=mod;
        }
    }
    printf("%lld\n",ans);
}