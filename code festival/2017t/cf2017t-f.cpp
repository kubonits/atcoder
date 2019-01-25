/*
https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_f
*/

#include<cstdio>
#include<algorithm>
#include<vector>
#define mod 1000000007
using namespace std;
int main(){
    int n,k,a[100001],two[20],x;
    vector<vector<int> > dp;
    scanf("%d %d",&n,&k);
    dp.resize(n+1);
    a[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n+1);
    two[0]=1;
    for(int i=1;i<20;i++){
        two[i]=two[i-1]*2;
    }
    dp[0].resize(1);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<20;j++){
            if(a[i]<two[j]){
                x=two[j];
                dp[i].resize(x);
                break;
            }
        }fill(dp[i].begin(), dp[i].end(), 0);
        if(i==n){
            dp[i].resize(max(x,k+1));
        }
        for(int j=0;j<dp[i-1].size();j++){
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=mod;
            dp[i][j^a[i]]+=dp[i-1][j];
            dp[i][j^a[i]]%=mod;
        }
    }
    printf("%d\n",dp[n][k]);
}