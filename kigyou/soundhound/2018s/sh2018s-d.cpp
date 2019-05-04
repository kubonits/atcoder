#include<cstdio>
#include<algorithm>
#define INF 100000000000
using namespace std;
typedef long long ll;

ll dp[11][50000],l[10][50000],r[10][50000],p[10][50000],f[10][50000],ma;
int main(){
    int h,w;
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%lld",&p[i][j]);
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%lld",&f[i][j]);
        }
    }
    for(int i=0;i<=h;i++){
        for(int j=0;j<w;j++){
            dp[i][j]=-INF;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<h;i++){
        l[i][0]=0;
        for(int j=1;j<w;j++){
            l[i][j]=max(p[i][j-1]-f[i][j-1],l[i][j-1]+p[i][j-1]-2*f[i][j-1]);
        }
        r[i][w-1]=0;
        for(int j=w-2;j>=0;j--){
            r[i][j]=max(p[i][j+1]-f[i][j+1],r[i][j+1]+p[i][j+1]-2*f[i][j+1]);
        }
        ma=-INF;
        for(int j=0;j<w;j++){
            ma=max(max(ma+p[i][j]-f[i][j],dp[i][j]+l[i][j]+p[i][j]-f[i][j]*2),dp[i][j]+p[i][j]-f[i][j]);
            dp[i+1][j]=max(dp[i+1][j],ma);
            dp[i+1][j]=max(dp[i+1][j],ma+r[i][j]-f[i][j]);
        }
        reverse(dp[i],dp[i]+w);
        reverse(dp[i+1],dp[i+1]+w);
        reverse(p[i],p[i]+w);
        reverse(f[i],f[i]+w);
        l[i][0]=0;
        for(int j=1;j<w;j++){
            l[i][j]=max(p[i][j-1]-f[i][j-1],l[i][j-1]+p[i][j-1]-2*f[i][j-1]);
        }
        r[i][w-1]=0;
        for(int j=w-2;j>=0;j--){
            r[i][j]=max(p[i][j+1]-f[i][j+1],r[i][j+1]+p[i][j+1]-2*f[i][j+1]);
        }
        ma=-INF;
        for(int j=0;j<w;j++){
            ma=max(max(ma+p[i][j]-f[i][j],dp[i][j]+l[i][j]+p[i][j]-f[i][j]*2),dp[i][j]+p[i][j]-f[i][j]);
            dp[i+1][j]=max(dp[i+1][j],ma);
            dp[i+1][j]=max(dp[i+1][j],ma+r[i][j]-f[i][j]);
        }
        reverse(dp[i],dp[i]+w);
        reverse(dp[i+1],dp[i+1]+w);
        reverse(p[i],p[i]+w);
        reverse(f[i],f[i]+w);
    }
    for(int j=0;j<w;j++){
        printf("%lld\n",dp[h][j]);
    }
}