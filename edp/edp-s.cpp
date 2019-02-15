#include<cstdio>
#include<cstring>
#define mod 1000000007
using namespace std;
char s[10010];
int n,d,dp[10010][100]={},num[10001],ans=0,sum=0;
int main(){
    scanf("%s",s);
    scanf("%d",&d);
    n=strlen(s);
    for(int i=0;i<n;i++){
        num[i]=s[i]-'0';
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<d;k++){
                dp[i][(j+k)%d]+=dp[i-1][k];
                dp[i][(j+k)%d]%=mod;
            }
        }
    }
    for(int i=n;i>0;i--){
        for(int j=0;j<=num[n-i];j++){
            if(j!=num[n-i]){
                ans+=dp[i-1][(d*100-j-sum)%d];
                ans%=mod;
            }
            else if(i==1){
                ans+=dp[i-1][(d*100-j-sum)%d];
                ans%=mod;
            }
        }
        sum+=num[n-i];
        sum%=d;
    }
    ans+=mod-1;
    ans%=mod;
    printf("%d\n",ans);
}