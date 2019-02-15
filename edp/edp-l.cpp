#include<cstdio>
#include<algorithm>
using namespace std;
long dp[3001][3001],a[3000];
int main(){
    int n;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(n%2==1){
            dp[i][n-i-1]=a[i];
        }
        else{
            dp[i][n-i-1]=-a[i];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j+i<n;j++){
            if((n-i)%2==0){
                dp[j][n-j-i-1]=min(dp[j+1][n-j-i-1]-a[j],dp[j][n-j-i]-a[j+i]);
            }
            else{
                dp[j][n-j-i-1]=max(dp[j+1][n-j-i-1]+a[j],dp[j][n-j-i]+a[j+i]);
            }
        }
    }
    printf("%ld\n",dp[0][0]);
}