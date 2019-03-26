#include<cstdio>
#include<cmath>
using namespace std;
int n,d,x,y;
double dp[1001][1001]={},dp2[1001][1001];
int main(){
    scanf("%d %d %d %d",&n,&d,&x,&y);
    x=(int)abs(x);
    y=(int)abs(y);
    if(x%d||y%d){
        printf("0.0\n");
        return 0;
    }
    x/=d;
    y/=d;
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            for(int k=(i+j)%2;j+k<=i;k+=2){
                dp2[(int)abs(j+1)][(int)abs(k)]+=dp[j][k]/4;
                dp2[(int)abs(j-1)][(int)abs(k)]+=dp[j][k]/4;
                dp2[(int)abs(j)][(int)abs(k+1)]+=dp[j][k]/4;
                dp2[(int)abs(j)][(int)abs(k-1)]+=dp[j][k]/4;
            }
        }
        for(int j=0;j<=i+1;j++){
            for(int k=0;j+k<=i+1;k++){
                dp[j][k]=dp2[j][k];
                dp2[j][k]=0.0;
            }
        }
    }
    if(x){
        dp[x][y]/=2;
    }
    if(y){
        dp[x][y]/=2;
    }
    printf("%.10f\n",dp[(int)abs(x)][(int)abs(y)]);
}