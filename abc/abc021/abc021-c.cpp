#include<cstdio>
#include<algorithm>
#include<utility>
#define mod 1000000007
using namespace std;
int main(){
    int n,a,b,m,x,y,g[100][100],dp[100]={};
    pair<int,int> p[100];
    scanf("%d",&n);
    scanf("%d %d",&a,&b);
    a--;
    b--;
    scanf("%d",&m);
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(i==j){
                g[i][j]=0;
            }
            else{
                g[i][j]=1000;
            }
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        x--;
        y--;
        g[x][y]=1;
        g[y][x]=1;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        p[i]=make_pair(g[a][i],i);
    }
    sort(p,p+n);
    dp[a]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[p[i].second][j]==1&&g[p[i].second][b]==g[j][b]+1){
                dp[j]+=dp[p[i].second];
                dp[j]%=mod;
            }
        }
    }
    printf("%d\n",dp[b]);
}