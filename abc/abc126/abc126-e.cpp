#include<cstdio>
#include<set>
using namespace std;

int n,m,x,y,z;
int g[100001];

void init(){
    for(int i=1;i<=n;i++){
        g[i]=i;
    }
}

int dfs(int x){
    if(x==g[x]){
        return x;
    }
    return g[x]=dfs(g[x]);
}

int main(){
    set<int> s;
    scanf("%d %d",&n,&m);
    init();
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&z);
        x=dfs(x);
        y=dfs(y);
        if(x<y){
            g[y]=x;
        }
        else{
            g[x]=y;
        }
    }
    for(int i=1;i<=n;i++){
        dfs(i);
        s.insert(g[i]);
    }
    printf("%ld\n",s.size());
}