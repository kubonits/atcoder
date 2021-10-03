#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll dp[40000][101][2]={},sum;
int main(){
    int n,k,rn;
    scanf("%d %d",&n,&k);
    dp[1][0][0]=1;
    rn=sqrt(n);
    for(int i=1;i<=k;i++){
        sum=0;
        for(int j=1;j<=rn;j++){
            sum+=dp[j][i-1][0];
            sum%=mod;
            if(j!=rn){
                dp[j][i][1]=sum*(ll)(n/j-n/(j+1));
            }
            else{
                dp[j][i][1]=sum*(ll)(n/j-j);
            }
            dp[j][i][1]%=mod;
        }
        for(int j=rn;j>0;j--){
            sum+=dp[j][i-1][1];
            sum%=mod;
            dp[j][i][0]=sum;
        }
    }
    sum=0;
    
    for(int i=1;i<=rn;i++){
        sum+=dp[i][k][0]+dp[i][k][1];
        sum%=mod;
    }
    printf("%lld\n",sum);
}