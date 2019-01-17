#include<cstdio>
#include<cstring>
#include<utility>
#include<vector>
#include<algorithm>
#define INF 2000
using namespace std;
int r,c;
char s[45][45],t[45];

struct edge{int to,cap,rev;};

vector<edge> g[1610];
bool used[1610];

void add_edge(int from, int to, int cap){
    g[from].push_back((edge){to,cap,(int)g[to].size()});
    g[to].push_back((edge){from,0,(int)g[from].size()-1});
}

int dfs(int v,int t,int f){
    if(v==t){
        return f;
    }
    used[v]=true;
    for(int i=0;i<g[v].size();i++){
        edge &e=g[v][i];
        if(!used[e.to]&&e.cap>0){
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s,int t){
    int flow=0;
    for(;;){
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0) return flow;
        flow+=f;
    }
}
int main(){
    int ans=0,cnt=0;
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(s[i][j]=='.'){
                cnt++;
                if((i+j)%2){
                    add_edge(0,1+i*c+j,1);
                    if(i!=0&&s[i-1][j]=='.'){
                        add_edge(1+i*c+j,1+(i-1)*c+j,1);
                    }
                    if(i!=r-1&&s[i+1][j]=='.'){
                        add_edge(1+i*c+j,1+(i+1)*c+j,1);
                    }
                    if(j!=0&&s[i][j-1]=='.'){
                        add_edge(1+i*c+j,1+i*c+j-1,1);
                    }
                    if(j!=c-1&&s[i][j+1]=='.'){
                        add_edge(1+i*c+j,1+i*c+j+1,1);
                    }
                }
                else{
                    add_edge(1+i*c+j,r*c+1,1);
                }
            }
        }
    }
    printf("%d\n",cnt-max_flow(0,r*c+1));
}