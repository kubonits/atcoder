#include<cstdio>
#include<set>
#include<utility>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
using namespace std;

struct ans{
    int y;
    int x;
    char c;
};
int main(){
    int n,m,rx[100],ry[100],by[300],bx[300],b,gx,gy,x,y,cnt=0,cnt2=0,cnt3=0;
    int visited[40][41]={},dis[40][40];
    char c[110],g[40][41],d;
    deque<pair<int,int> > st;
    scanf("%d %d %d",&n,&m,&b);
    scanf("%d%d",&gy,&gx);
    set<pair<int,int> > bs,as;
    vector<ans> v;
    priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > q;
    for(int i=0;i<m;i++){
        scanf("%d %d %c",&ry[i],&rx[i],&c[i]);
    }
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            g[i][j]='X';
        }
        g[i][40]='\0';
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
    
    while(1){
        cnt2++;
        if(cnt2>11000){
            break;
        }
        for(int i=0;i<m;i++){
            x=rx[i];
            y=ry[i];
            d=c[i];
            if(d==g[y][x]&&dis[y][x]-1>0){
                q.push({dis[y][i]-1,i});
            }
            else if(d!=g[y][x]&&dis[y][x]>0){
                q.push({dis[y][x],i});
            }
        }
        if(q.empty()){
            break;
        }
        int top=q.top().second;
        x=rx[top];
        y=ry[top];
        d=c[top];
        //printf("%d %d %d %d\n",top,dis[y][x],x,y);
        while(!q.empty()){
            q.pop();
        }//printf("%d %c\n",dis[y][x],g[y][x]);
        while(visited[y][x]==0&&(x!=gx||y!=gy)){
            if(d!=g[y][x]){
                visited[y][x]=1;
                dis[y][x]=0;
                cnt++;
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
        for(int i=0;i<40;i++){
            for(int j=0;j<40;j++){
                if(visited[i][j]==0&&g[i][j]!='G'&&g[i][j]!='B'){
                    g[i][j]='X';//printf("%d\t",dis[i][j]);
                }
                else if(visited[i][j]==1){
                    dis[i][j]=0;
                    st.push_front({i,j});
                }/*else if(g[i][j]=='G'||g[i][j]=='B'){
                    printf("%c\t",g[i][j]);
                }*/
            }//printf("\n");
        }//printf("\n");
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
            if(g[(y+n-1)%n][(x+n)%n]=='X'&&g[y][x]!='U'){
                g[(y+n-1)%n][(x+n)%n]='D';
                if(g[y][x]==g[(y+n-1)%n][(x+n)%n]&&visited[y][x]==0){
                    st.push_front({(y+n-1)%n,(x+n)%n});
                    dis[(y+n-1)%n][(x+n)%n]=dis[y][x];
                }
                else{
                    st.push_back({(y+n-1)%n,(x+n)%n});
                    dis[(y+n-1)%n][(x+n)%n]=dis[y][x]+1;
                }
            }
            if(g[(y+n+1)%n][(x+n)%n]=='X'&&g[y][x]!='D'&&visited[y][x]==0){
                g[(y+n+1)%n][(x+n)%n]='U';
                if(g[y][x]==g[(y+n+1)%n][(x+n)%n]&&visited[y][x]==0){
                    st.push_front({(y+n+1)%n,(x+n)%n});
                    dis[(y+n+1)%n][(x+n)%n]=dis[y][x];
                }
                else{
                    st.push_back({(y+n+1)%n,(x+n)%n});
                    dis[(y+n+1)%n][(x+n)%n]=dis[y][x]+1;
                }
            }
            if(g[(y+n)%n][(x+n-1)%n]=='X'&&g[y][x]!='L'&&visited[y][x]==0){
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
            if(g[(y+n)%n][(x+n+1)%n]=='X'&&g[y][x]!='R'&&visited[y][x]==0){
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
        /*for(int i=0;i<40;i++){
            printf("%s\n",g[i]);
        }printf("\n");*/
    }
    printf("%d\n",cnt);
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++){
            if(visited[i][j]==1&&g[i][j]!='X'){
                printf("%d %d %c\n",i,j,g[i][j]);
            }
            else{
                printf("%d %d R\n",i,j);
            }
        }
    }
}