#include<cstdio>
#include<queue>
#include<utility>
using namespace std;
#define INF 1000000000000
typedef long long ll;
int used[1002][1002];
ll g[1002][1002],c[100000][4],x,y,ti;
char s[1002][1002],d[100001],t[1002];
priority_queue<pair<ll,pair<ll,ll> > ,vector<pair<ll,pair<ll,ll> > >,greater<pair<ll,pair<ll,ll> > > > q;
pair<ll,pair<ll,ll> > p;
int main(){
    ll n,m,k,a,sx,sy,gx,gy;
    scanf("%lld %lld %lld",&n,&m,&k);
    scanf("%s",d);
    for(int i=0;i<=m+1;i++){
        s[0][i]=s[n+1][i]='#';
    }
    for(int i=1;i<=n;i++){
        scanf("%s",t);
        s[i][0]=s[i][m+1]='#';
        for(int j=0;j<m;j++){
            s[i][j+1]=t[j];
            if(s[i][j+1]=='S'){
                sx=i;
                sy=j+1;
            }
            if(s[i][j+1]=='G'){
                gx=i;
                gy=j+1;
            }
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<4;j++){
            c[i][j]=-1;
        }
    }
    for(int i=k-1;i>=0;i--){
        if(d[i]=='U'){
            a=0;
        }
        else if(d[i]=='R'){
            a=1;
        }
        else if(d[i]=='D'){
            a=2;
        }
        else{
            a=3;
        }
        c[i][a]=0;
        for(int j=1;j<=k;j++){
            if(d[i]==d[(i-j+k)%k]){
                break;
            }
            c[(i-j+k)%k][a]=j;
        }
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            g[i][j]=INF;
        }
    }
    q.push(make_pair(0,make_pair(sx,sy)));
    while(!q.empty()){
        p=q.top();
        x=p.second.first;
        y=p.second.second;
        ti=p.first;
        q.pop();
        if(used[x][y]==0){
            used[x][y]=1;
            g[x][y]=ti;
            if(s[x-1][y]!='#'&&c[ti%k][0]>=0){
                q.push(make_pair(ti+c[ti%k][0]+1,make_pair(x-1,y)));
            }
            if(s[x][y+1]!='#'&&c[ti%k][1]>=0){
                q.push(make_pair(ti+c[ti%k][1]+1,make_pair(x,y+1)));
            }
            if(s[x+1][y]!='#'&&c[ti%k][2]>=0){
                q.push(make_pair(ti+c[ti%k][2]+1,make_pair(x+1,y)));
            }
            if(s[x][y-1]!='#'&&c[ti%k][3]>=0){
                q.push(make_pair(ti+c[ti%k][3]+1,make_pair(x,y-1)));
            }
        }
    }
    if(g[gx][gy]==INF){
        printf("-1\n");
    }
    else{
        printf("%lld\n",g[n][m]);
    }
}