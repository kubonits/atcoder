#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    long n,W,w[100];
    long dp[100001],v[100];
    scanf("%ld %d",&n,&W);
    dp[0]=0;
    for(long i=1;i<=100000;i++){
        dp[i]=W+1L;
    }
    for(long i=0;i<n;i++){
        scanf("%ld %ld",&w[i],&v[i]);
        for(long j=100000;j>=v[i];j--){
            dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    for(long i=100000;i>=0;i--){
        if(dp[i]<=W){
            printf("%ld\n",i);
            return 0;
        }
    }
}