#include<cstdio>
using namespace std;

int visited[160001],used[160001];
long cnt,cnt2;
int h,w;
char s[410][410];
void dfs(int x,int y){
    visited[x*w+y]=1;
    used[x*w+y]=1;
    if(s[x][y]=='#'){
        cnt2++;
    }
    cnt++;
    if(x>0&&s[x][y]!=s[x-1][y]&&used[(x-1)*w+y]==0){
        dfs(x-1,y);
    }
    if(x<h-1&&s[x][y]!=s[x+1][y]&&used[(x+1)*w+y]==0){
        dfs(x+1,y);
    }
    if(y>0&&s[x][y]!=s[x][y-1]&&used[(x)*w+y-1]==0){
        dfs(x,y-1);
    }
    if(y<w-1&&s[x][y]!=s[x][y+1]&&used[(x)*w+y+1]==0){
        dfs(x,y+1);
    }
}

int main(){
    long ans=0;
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cnt=0;
            cnt2=0;
            if(used[i*w+j]==0){
                dfs(i,j);
                ans+=(cnt-cnt2)*cnt2;
            }
        }
    }
    printf("%ld\n",ans);
}