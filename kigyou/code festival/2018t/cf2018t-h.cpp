/*
https://atcoder.jp/contests/code-thanks-festival-2018-open/tasks/code_thanks_festival_2018_h
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,dp1[1001]={},dp2[1001]={};
    long long a[1000],sum[1001],l,r,mid;
    sum[0]=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum[i+1]=sum[i]+a[i];
    }
    l=-1000000000000;
    r=1000000000000;
    while(l<=r){
        mid=(l+r)/2;
        for(int i=n-1;i>=0;i--){
            dp1[i]=dp2[i]=-1000;
            for(int j=n;j>i;j--){
                if(sum[j]-sum[i]>=mid){
                    dp1[i]=max(dp1[i],1-dp2[j]);
                    dp2[i]=max(dp2[i],-1-dp1[j]);
                }
                else{
                    dp1[i]=max(dp1[i],-1-dp2[j]);
                    dp2[i]=max(dp2[i],1-dp1[j]);
                }
            }
        }
        if(dp1[0]>=0){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    printf("%lld\n",r);
}
