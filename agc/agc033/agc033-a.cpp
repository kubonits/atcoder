#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

char s[1000][1010];
int h,w,co[1000][1000],ans,visited[1000][1000];
queue<int> q;

void bfs(int x,int y){
    q.pop();
    ans=max(ans,co[x][y]);
    visited[x][y]=1;
    if(x>0&&co[x-1][y]>co[x][y]+1){
        co[x-1][y]=co[x][y]+1;
        q.push((x-1)*1000+y);
    }
    if(x<h-1&&co[x+1][y]>co[x][y]+1){
        co[x+1][y]=co[x][y]+1;
        q.push((x+1)*1000+y);
    }
    if(y>0&&co[x][y-1]>co[x][y]+1){
        co[x][y-1]=co[x][y]+1;
        q.push((x)*1000+y-1);
    }
    if(y<w-1&&co[x][y+1]>co[x][y]+1){
        co[x][y+1]=co[x][y]+1;
        q.push((x)*1000+y+1);
    }
}

int main(){
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='.'){
                co[i][j]=10000000;
            }
            else{
                co[i][j]=0;
                q.push(i*1000+j);
            }
        }
    }
    while(!q.empty()){
        if(visited[q.front()/1000][q.front()%1000]==1){
            q.pop();
        }
        else{
            bfs(q.front()/1000,q.front()%1000);
        }
    }
    printf("%d\n",ans);
}