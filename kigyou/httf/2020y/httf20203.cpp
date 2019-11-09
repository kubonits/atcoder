#include<cstdio>
#include<set>
#include<utility>
#include<vector>
#include<stack>
#include<deque>
using namespace std;

struct ans{
    int y;
    int x;
    char c;
};
int main(){
    int n,m,rx[100],ry[100],by[300],bx[300],b,gx,gy,x,y,cnt=0,cnt2,cnt3=0;
    int visited[40][40]={},dis[40][40];
    char c[110],g[40][40],d;
    deque<pair<int,int> > st;
    scanf("%d %d %d",&n,&m,&b);
    scanf("%d%d",&gy,&gx);
    set<pair<int,int> > bs,as;
    vector<ans> v;
    for(int i=0;i<m;i++){
        scanf("%d %d %c",&ry[i],&rx[i],&c[i]);
    }
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            g[i][j]='X';
        }
    }
    g[gy][gx]='G';
    dis[gy][gx]=0;
    for(int i=0;i<b;i++){
        scanf("%d%d",&by[i],&bx[i]);
        g[by[i]][bx[i]]='B';
        bs.insert({by[i],bx[i]});
    }
    if(g[(gy+n-1)%n][(gx+n)%n]=='X'){
        g[(gy+n-1)%n][(gx+n)%n]='D';
        st.push_front({(gy+n-1)%n,(gx+n)%n});
        dis[(gy+n-1)%n][(gx+n)%n]=1;
    }
    if(g[(gy+n+1)%n][(gx+n)%n]=='X'){
        g[(gy+n+1)%n][(gx+n)%n]='U';
        st.push_front({(gy+n+1)%n,(gx+n)%n});
        dis[(gy+n+1)%n][(gx+n)%n]=1;
    }
    if(g[(gy+n)%n][(gx+n-1)%n]=='X'){
        g[(gy+n)%n][(gx+n-1)%n]='R';
        st.push_front({(gy+n)%n,(gx+n-1)%n});
        dis[(gy+n)%n][(gx+n-1)%n]=1;
    }
    if(g[(gy+n)%n][(gx+n+1)%n]=='X'){
        g[(gy+n)%n][(gx+n+1)%n]='L';
        st.push_front({(gy+n)%n,(gx+n+1)%n});
        dis[(gy+n)%n][(gx+n+1)%n]=1;
    }
    while(!st.empty()){
        y=st.front().first;
        x=st.front().second;
        st.pop_front();
        if(g[(y+n-1)%n][(x+n)%n]=='X'){
            g[(y+n-1)%n][(x+n)%n]='D';
            if(g[y][x]==g[(y+n-1)%n][(x+n)%n]){
                st.push_front({(y+n-1)%n,(x+n)%n});
                dis[(y+n-1)%n][(x+n)%n]=dis[y][x];
            }
            else{
                st.push_back({(y+n-1)%n,(x+n)%n});
                dis[(y+n-1)%n][(x+n)%n]=dis[y][x]+1;
            }
        }
        if(g[(y+n+1)%n][(x+n)%n]=='X'){
            g[(y+n+1)%n][(x+n)%n]='U';
            if(g[y][x]==g[(y+n+1)%n][(x+n)%n]){
                st.push_front({(y+n+1)%n,(x+n)%n});
                dis[(y+n+1)%n][(x+n)%n]=dis[y][x];
            }
            else{
                st.push_back({(y+n+1)%n,(x+n)%n});
                dis[(y+n+1)%n][(x+n)%n]=dis[y][x]+1;
            }
        }
        if(g[(y+n)%n][(x+n-1)%n]=='X'){
            g[(y+n)%n][(x+n-1)%n]='R';
            if(g[y][x]==g[(y+n)%n][(x+n-1)%n]){
                st.push_front({(y+n)%n,(x+n-1)%n});
                dis[(y+n)%n][(x+n-1)%n]=dis[y][x];
            }
            else{
                st.push_back({(y+n)%n,(x+n-1)%n});
                dis[(y+n)%n][(x+n-1)%n]=dis[y][x]+1;
            }
        }
        if(g[(y+n)%n][(x+n+1)%n]=='X'){
            g[(y+n)%n][(x+n+1)%n]='L';
            if(g[y][x]==g[(y+n)%n][(x+n+1)%n]){
                st.push_front({(y+n)%n,(x+n+1)%n});
                dis[(y+n)%n][(x+n+1)%n]=dis[y][x];
            }
            else{
                st.push_back({(y+n)%n,(x+n+1)%n});
                dis[(y+n)%n][(x+n+1)%n]=dis[y][x]+1;
            }
        }
    }
    for(int i=0;i<m;i++){
        x=rx[i];
        y=ry[i];
        d=c[i];
        while(visited[y][x]==0&&(x!=gx||y!=gy)&&cnt3<1000000000){
            if(d!=g[y][x]){
                int xx=x,yy=y,mini=dis[y][x];
                cnt2=0;
                while(g[yy][xx]!='B'&&cnt2<50&&cnt3<10000){
                    cnt3++;
                    cnt2++;
                    if(visited[yy][xx]==1){
                        y=yy;
                        x=xx;
                        break;
                    }
                    /*if(mini>dis[yy][xx]){
                        x=xx;
                        y=yy;
                        mini=dis[yy][xx];
                    }*/
                    if(d=='D'){
                        yy=(yy+n+1)%n;
                    }
                    else if(d=='U'){
                        yy=(yy+n-1)%n;
                    }
                    else if(d=='R'){
                        xx=(xx+n+1)%n;
                    }
                    else{
                        xx=(xx+n-1)%n;
                    }
                }
                if(visited[y][x]==0){
                    visited[y][x]=1;
                    cnt++;
                }
                d=g[y][x];
            }
            if(g[y][x]=='D'){
                y=(y+n+1)%n;
            }
            else if(g[y][x]=='U'){
                y=(y+n-1)%n;
            }
            else if(g[y][x]=='R'){
                x=(x+n+1)%n;
            }
            else if(g[y][x]=='L'){
                x=(x+n-1)%n;
            }
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            if(visited[i][j]==1){
                printf("%d %d %c\n",i,j,g[i][j]);
            }
        }
    }
}