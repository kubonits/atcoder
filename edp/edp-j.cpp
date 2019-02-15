#include<cstdio>
using namespace std;
double dp[301][301][301];
int main(){
    int n,a,x[3]={};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        x[a-1]++;
    }
    for(int k=0;k<=x[2];k++){
        for(int j=0;j+k<=x[2]+x[1];j++){
            for(int i=0;i+j+k<=x[2]+x[1]+x[0];i++){
                if(i){
                    dp[i][j][k]+=(double)i/(i+j+k)*dp[i-1][j][k];
                }
                if(j){
                    dp[i][j][k]+=(double)j/(i+j+k)*dp[i+1][j-1][k];
                }
                if(k){
                    dp[i][j][k]+=(double)k/(i+j+k)*dp[i][j+1][k-1];
                }
                if(i||j||k){
                    dp[i][j][k]+=(double)n/(i+j+k);
                }
                //printf("%d %d %d %f\n",i,j,k,dp[i][j][k]);
            }
        }
    }
    printf("%.10f\n",dp[x[0]][x[1]][x[2]]);
}