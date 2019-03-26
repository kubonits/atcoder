#include<cstdio>
#define mod 1000000007
using namespace std;
int main(){
    int n,dp[101][3125]={},x,f,bit[5],ans=0;
    scanf("%d",&n);
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<3125;j++){
            for(int k=1;k<5;k++){
                x=j%625;
                x*=5;
                x+=k;
                f=1;
                for(int l=0;l<5;l++){
                    bit[l]=x%5;
                    x/=5;
                }
                x=j%625;
                x*=5;
                x+=k;
                for(int l=0;l<3;l++){
                    if((bit[l]==1&&bit[l+1]==3&&bit[l+2]==2)||(bit[l]==1&&bit[l+1]==2&&bit[l+2]==3)||(bit[l]==3&&bit[l+1]==1&&bit[l+2]==2)){
                        f=0;
                    }
                }
                for(int l=0;l<2;l++){
                    if((bit[l]==1&&bit[l+2]==3&&bit[l+3]==2)||(bit[l]==1&&bit[l+1]==3&&bit[l+3]==2)){
                        f=0;
                    }
                }
                if(f){
                    dp[i+1][x]+=dp[i][j];
                    dp[i+1][x]%=mod;
                }
            }
        }
    }
    for(int i=0;i<3125;i++){
        ans+=dp[n][i];
        ans%=mod;
    }
    printf("%d\n",ans);
}
