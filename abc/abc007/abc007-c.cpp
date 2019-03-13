#include<cstdio>
#include<queue>
#include<utility>
using namespace std;

int r,c,st[2],go[2],g[50][50];
char s[51][51];
queue<pair<int,int> > q;
int bfs(int x,int y){
    if(x==go[0]&&y==go[1]){
        return g[x][y];
    }
    pair<int,int> a;
    if(g[x-1][y]>g[x][y]+1&&s[x-1][y]=='.'){
        g[x-1][y]=g[x][y]+1;
        q.push(make_pair(x-1,y));
    }
    if(g[x+1][y]>g[x][y]+1&&s[x+1][y]=='.'){
        g[x+1][y]=g[x][y]+1;
        q.push(make_pair(x+1,y));
    }
    if(g[x][y-1]>g[x][y]+1&&s[x][y-1]=='.'){
        g[x][y-1]=g[x][y]+1;
        q.push(make_pair(x,y-1));
    }
    if(g[x][y+1]>g[x][y]+1&&s[x][y+1]=='.'){
        g[x][y+1]=g[x][y]+1;
        q.push(make_pair(x,y+1));
    }
    if(!q.empty()){
        a=q.front();
        q.pop();
        return bfs(a.first,a.second);
    }
}

int main(){
    scanf("%d %d",&r,&c);
    scanf("%d %d",&st[0],&st[1]);
    scanf("%d %d",&go[0],&go[1]);
    st[0]--;
    st[1]--;
    go[0]--;
    go[1]--;
    for(int i=0;i<r;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            g[i][j]=10000;
        }
    }
    g[st[0]][st[1]]=0;
    printf("%d\n",bfs(st[0],st[1]));
}