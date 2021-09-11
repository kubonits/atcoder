#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m,u,v,l,g[300][300]={},ans=500000000;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            g[i][j]=g[j][i]=500000000;
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&l);
        u--;
        v--;
        if(u){
            g[v][u]=l;
        }
        if(v){
            g[u][v]=l;
        }
    }
    for(int k=1;k<n;k++){
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=min(ans,g[0][i]+g[0][j]+g[i][j]);
        }
    }
    if(ans<500000000){
        printf("%d\n",ans);
    }
    else{
        printf("-1\n");
    }
}