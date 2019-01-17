#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,W,w[100];
    long dp[100001]={},v[100];
    scanf("%d %d",&n,&W);
    for(int i=0;i<n;i++){
        scanf("%d %ld",&w[i],&v[i]);
        for(int j=W-w[i];j>=0;j--){
            dp[j+w[i]]=max(dp[j+w[i]],dp[j]+v[i]);
        }
    }
    printf("%ld\n",dp[W]);
}