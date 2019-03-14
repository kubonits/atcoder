#include<cstdio>
#include<vector>
using namespace std;
int g[100010];
vector<vector<int>> e;
int dfs(int p){
    int flag=1;
    for(int i=0;i<e[p].size();i++){
        if(g[e[p][i]]==0){
            g[e[p][i]]=g[p]*(-1);
            flag*=dfs(e[p][i]);
        }
        if(flag==0||g[e[p][i]]==g[p]){
            return 0;
        }
    }
    return flag;
}
int main(){
    int a,b;
    long n,m,x,y;
    scanf("%ld %ld",&n,&m);
    e.resize(n+1);
    for(long i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        e[b].push_back(a);
        e[a].push_back(b);
    }
    g[1]=1;
    if(dfs(1)){
        x=y=0;
        for(long i=1;i<=n;i++){
            if(g[i]==1){
                x++;
            }
            else{
                y++;
            }
            
        }
        printf("%ld\n",x*y-m);
    }
    else{
        printf("%ld\n",(n-1)*n/2-m);
    }
}