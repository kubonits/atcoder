#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
int w,h,n,x[32],y[32],sum[4][32],dp[31][31][32][32]={},res;
int main(){
    pair<int,int> p[32];
    scanf("%d %d",&h,&w);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x[i],&y[i]);
        p[i]=make_pair(x[i],y[i]);
    }
    x[n]=p[n].first=y[n]=p[n].second=0;
    x[n+1]=p[n+1].first=h+1;
    y[n+1]=p[n+1].second=w+1;
    sort(x,x+n+2);
    sort(y,y+n+2);
    for(int i=0;i<n+2;i++){
        for(int j=0;j<n+2;j++){
            if(p[i].first==x[j]){
                p[i].first=j;
                break;
            }
        }
        for(int j=0;j<n+2;j++){
            if(p[i].second==y[j]){
                p[i].second=j;
                break;
            }
        }
    }
    for(int i=0;i<n+2;i++){
        sum[0][i]=x[i]-1;
        sum[1][i]=h-x[i];
        sum[2][i]=y[i]-1;
        sum[3][i]=w-y[i];
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            for(int k=0;i+k<=n+1;k++){
                for(int l=0;l+j<=n+1;l++){
                    for(int m=0;m<n;m++){
                        if(k<p[m].first&&i+k>p[m].first&&l<p[m].second&&j+l>p[m].second){
                            res=sum[0][p[m].first]-sum[0][k]+sum[1][p[m].first]-sum[1][i+k]+sum[2][p[m].second]-sum[2][l]+sum[3][p[m].second]-sum[3][j+l]-3;
                            res+=dp[k][l][p[m].first][p[m].second];
                            res+=dp[k][p[m].second][p[m].first][l+j];
                            res+=dp[p[m].first][l][i+k][p[m].second];
                            res+=dp[p[m].first][p[m].second][i+k][l+j];
                            dp[k][l][k+i][j+l]=max(dp[k][l][k+i][j+l],res);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",dp[0][0][n+1][n+1]);
}