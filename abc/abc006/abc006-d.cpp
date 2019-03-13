#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,c[30000],dp[30001],l,r,mid;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    dp[0]=0;
    for(int i=1;i<=30000;i++){
        dp[i]=100000;
    }
    for(int i=0;i<n;i++){
        l=0;
        r=n;
        while(l<=r){
            mid=(l+r)/2;
            if(dp[mid]<c[i]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        if(dp[l]>c[i]){
            dp[l]=c[i];
        }
    }
    for(int i=0;i<=n;i++){
        if(dp[i]==100000){
            printf("%d\n",n-(i-1));
            return 0;
        }
    }
    printf("0\n");
}