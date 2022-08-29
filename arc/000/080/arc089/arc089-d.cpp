#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,g[2000][2000]={},x,y,ans=0,sum[2001][2001]={};
    char c;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d %d %c",&x,&y,&c);
        if(c=='B'){
            x+=k;
        }
        x%=2*k;
        y%=2*k;
        g[x][y]++;
        g[(x+k)%(2*k)][(y+k)%(2*k)]++;
        if(x+k<2*k&&y+k<2*k){
            g[x+k][y+k]++;
            g[x+k][y]--;
            g[x][y+k]--;
        }
        else if(x+k<2*k){
            g[x+k][y]--;
            g[x][0]++;
            g[x][(y+k)%(2*k)]--;
            g[x+k][0]--;
            g[x+k][(y+k)%(2*k)]++;
        }
        else if(y+k<2*k){
            g[x][y+k]--;
            g[0][y]++;
            g[(x+k)%(2*k)][y]--;
            g[(x+k)%(2*k)][y+k]++;
            g[0][y+k]--;
        }
        else{
            g[0][0]++;
            g[(x+k)%(2*k)][(y+k)%(2*k)]++;
            g[0][(y+k)%(2*k)]--;
            g[(x+k)%(2*k)][0]--;
            g[0][y]++;
            g[x][0]++;
            g[(x+k)%(2*k)][y]--;
            g[x][(y+k)%(2*k)]--;
        }
        if((x+k)%(2*k)+k<2*k&&(y+k)%(2*k)+k<2*k){
            g[(x+k)%(2*k)+k][(y+k)%(2*k)+k]++;
            g[(x+k)%(2*k)+k][(y+k)%(2*k)]--;
            g[(x+k)%(2*k)][(y+k)%(2*k)+k]--;
        }
        else if((x+k)%(2*k)+k<2*k){
            g[(x+k)%(2*k)+k][(y+k)%(2*k)]--;
            g[(x+k)%(2*k)][0]++;
            g[(x+k)%(2*k)][((y+k)%(2*k)+k)%(2*k)]--;
            g[(x+k)%(2*k)+k][0]--;
            g[(x+k)%(2*k)+k][((y+k)%(2*k)+k)%(2*k)]++;
        }
        else if((y+k)%(2*k)+k<2*k){
            g[(x+k)%(2*k)][(y+k)%(2*k)+k]--;
            g[0][(y+k)%(2*k)]++;
            g[((x+k)%(2*k)+k)%(2*k)][(y+k)%(2*k)]--;
            g[0][(y+k)%(2*k)+k]--;
            g[((x+k)%(2*k)+k)%(2*k)][(y+k)%(2*k)+k]++;
        }
        else{
            g[0][0]++;
            g[((x+k)%(2*k)+k)%(2*k)][((y+k)%(2*k)+k)%(2*k)]++;
            g[0][((y+k)%(2*k)+k)%(2*k)]--;
            g[((x+k)%(2*k)+k)%(2*k)][0]--;
            g[0][(y+k)%(2*k)]++;
            g[(x+k)%(2*k)][0]++;
            g[x][(y+k)%(2*k)]--;
            g[(x+k)%(2*k)][y]--;
        }
    }
    for(int i=0;i<2*k;i++){
        for(int j=0;j<2*k;j++){
            sum[i+1][j+1]=sum[i+1][j]+g[i][j];
        }
    }
    for(int i=0;i<k*2;i++){
        for(int j=0;j<2*k;j++){
            sum[i+1][j+1]=sum[i+1][j+1]+sum[i][j+1];
        }
    }
    for(int i=0;i<2*k;i++){
        for(int j=0;j<2*k;j++){
            ans=max(ans,sum[i+1][j+1]);
            printf("%d ",sum[i+1][j+1]);
        }printf("\n");
    }
    printf("%d\n",ans);
}