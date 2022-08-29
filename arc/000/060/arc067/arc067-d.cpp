#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int n;
    long long x[100000],dp[100000],a,b;
    scanf("%d%lld%lld",&n,&a,&b);
    for(int i=0;i<n;i++){
        scanf("%lld",&x[i]);
    }
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]+min(a*(x[i]-x[i-1]),b);
    }
    printf("%lld\n",dp[n-1]);
}