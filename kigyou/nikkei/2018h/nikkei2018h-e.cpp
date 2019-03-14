#include<cstdio>
#define mod 1000000007
using namespace std;
int main(){
    int n,dp[5002]={},sum[5002]={},k,t1[30],t2[30],x,y=1;
    t1[0]=1;
    t2[0]=2;
    for(int i=1;i<30;i++){
        t1[i]=2*t1[i-1];
        t2[i]=t2[i-1]*t2[i-1];
        t2[i]%=mod;
    }
    scanf("%d %d",&n,&k);
    dp[0]=1;
    sum[1]=1;
    for(int i=1;i<=n;i++){
        sum[i+1]=sum[i];
        //printf("%d ",i);
        if(i-k>0){
            y=1;
            x=(i-k-1)*(i-k)/2;
            for(int j=0;j<30;j++){
                if((x&t1[j])){
                    y*=t2[j];
                    y%=mod;
                }
            }
            dp[i]=y;printf("%d %d %d\n\n",i,x,y);
            sum[i+1]+=dp[i];
            sum[i+1]%=mod;
        }
        y*=2;
        y%=mod;
        for(int j=2;j<=i-k;j++){
            dp[i]+=y-sum[j-1];
            sum[i+1]+=y-sum[j-1];
            if(dp[i]<0){
                dp[i]+=mod;
            }
            if(sum[i+1]<0){
                sum[i+1]+=mod;
            }
            dp[i]%=mod;
            sum[i+1]%=mod;
            y*=2;
            y%=mod;
            printf("%d\n",y);
        }//printf("\n");
    }
    for(int i=0;i<=n;i++){
        printf("%d\n",dp[i]);
    }
    printf("%d\n",dp[n]);
}