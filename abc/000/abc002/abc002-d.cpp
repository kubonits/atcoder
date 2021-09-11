#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,g[13][13],x,y,f[12];

int dfs(int a){
    int ans=0;
    if(a==n){
        for(int i=0;i<n;i++){
            if(f[i]){
                ans++;
                for(int j=0;j<n;j++){
                    if(i!=j&&f[j]&&g[i][j]==0){
                        return 0;
                    }
                }
            }
        }
        return ans;
    }
    f[a]=0;
    ans=dfs(a+1);
    f[a]=1;
    return max(ans,dfs(a+1));
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        x--;
        y--;
        g[x][y]=g[y][x]=1;
    }
    printf("%d\n",dfs(0));
}