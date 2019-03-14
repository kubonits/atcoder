#include<cstdio>
#include<algorithm>
using namespace std;
long b[200000],dp[200001],maxd[200001];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%ld",&b[i]);
    }
    dp[0]=maxd[0]=0;
    for(int i=0;i<n;i++){
        if(i+1<k){
            dp[i+1]=dp[i]+b[i];
        }
        else{
            dp[i+1]=max(dp[i]+b[i],maxd[i+1-k]);
        }
        maxd[i+1]=max(maxd[i],dp[i+1]);
    }
    printf("%ld\n",dp[n]);
}