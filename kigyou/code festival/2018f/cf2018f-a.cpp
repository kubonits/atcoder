#include<cstdio>
int g[100010][2010];
int main(){
    int n,m,a,b,l,ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&l);
        g[a][l]++;
        g[b][l]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1000;j<1270;j++){
            ans+=g[i][j]*g[i][2540-j];
        }
        if(g[i][1270]>1){
            ans+=g[i][1270]*(g[i][1270]-1)/2;
        }
    }
    printf("%d\n",ans);
}