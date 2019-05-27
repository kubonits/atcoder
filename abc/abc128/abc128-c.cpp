#include<cstdio>
#include<cstring>
#include<vector>
#define mod 1000000007
using namespace std;

int n,m,k[10],s[10][10],p[10],ans,su[10];

void dfs(int x){
    int res=1,cnt=0;
    if(x==n){
        for(int i=0;i<m;i++){
            cnt=0;
            for(int j=0;j<k[i];j++){
                if(su[s[i][j]-1]){
                    cnt++;
                }
            }
            if(cnt%2!=p[i]){
                res=0;
            }
        }
        ans+=res;
    }
    else{
        su[x]=1;
        dfs(x+1);
        su[x]=0;
        dfs(x+1);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&k[i]);
        for(int j=0;j<k[i];j++){
            scanf("%d",&s[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d",&p[i]);
    }
    dfs(0);
    printf("%d\n",ans);
}