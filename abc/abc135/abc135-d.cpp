#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define MOD 1000000007
using namespace std;
typedef long long ll;
char s[100010];
ll dp[100010][13],a[100010];
int main(){
    int n;
    scanf("%s",s);
    n=strlen(s);
    dp[0][0]=1;
    a[n-1]=1;
    for(int i=n-2;i>=0;i--){
        a[i]=a[i+1]*10;
        a[i]%=13;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            for(int j=0;j<=9;j++){
                for(int k=0;k<13;k++){
                    dp[i+1][(j*a[i]+k)%13]+=dp[i][k];
                    dp[i+1][(j*a[i]+k)%13]%=MOD;
                }
            }
        }
        else{
            for(int j=0;j<13;j++){
                dp[i+1][((j+(s[i]-'0')*a[i]))%13]+=dp[i][j];
                dp[i+1][((j+(s[i]-'0')*a[i]))%13]%=MOD;
            }
        }
    }
    printf("%lld\n",dp[n][5]);
}