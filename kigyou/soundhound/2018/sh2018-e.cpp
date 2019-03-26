#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> > g[100001];
ll visit[100001];
pair<ll,ll> p[100001],mi[100001];
void dfs(ll x,ll y,ll z){
    visit[x]=1;
    for(ll i=0;i<g[x].size();i++){
        if(z){
            if(p[g[x][i].first].second==0){
                p[g[x][i].first].first=g[x][i].second-mi[x].first;
                p[g[x][i].first].second=1;
            }
            else if(p[g[x][i].first].first!=g[x][i].second-mi[x].first){
                p[g[x][i].first].second=-1;
            }
        }
        else{
            if(mi[g[x][i].first].second==0){
                mi[g[x][i].first].first=g[x][i].second-p[x].first;
                mi[g[x][i].first].second=1;
            }
            else if(mi[g[x][i].first].first!=g[x][i].second-p[x].first){
                mi[g[x][i].first].second=-1;
            }
        }
    }
    for(ll i=0;i<g[x].size();i++){
        if(visit[g[x][i].first]==0){
            dfs(g[x][i].first,y,z^1);
        }
    }
}

int main(){
    ll n,m,u,v,s,f=1,l,r,x=0,y=0;
    scanf("%lld %lld",&n,&m);
    for(ll i=0;i<m;i++){
        scanf("%lld %lld %lld",&u,&v,&s);
        g[u].push_back(make_pair(v,s));
        g[v].push_back(make_pair(u,s));
    }
    dfs(1,0,0);
    for(ll i=1;i<=n;i++){
        if(p[i].second==-1||mi[i].second==-1){
            f=0;
        }
        if(p[i].second==1&&mi[i].second==1){
            if(y==1){
                if(x!=(mi[i].first-p[i].first)/2){
                    f=0;
                }
            }
            y=1;
            x=(mi[i].first-p[i].first)/2;
        }
    }
    if(!f){
        printf("0\n");
    }
    else if(y){
        for(int i=1;i<=n;i++){
            if(p[i].second){
                if(x+p[i].first<=0){
                    f=0;
                }
            }
            if(mi[i].second){
                if(mi[i].first-x<=0){
                    f=0;
                }
            }
        }
        printf("%lld\n",f);
    }
    else{
        l=1;
        r=1000000000;
        for(ll i=1;i<=n;i++){
            if(mi[i].second){
                r=min(r,mi[i].first-1);
            }
            if(p[i].second){
                l=max(l,-p[i].first+1);
            }
        }
        if(l>r){
            printf("0\n");
        }
        else{
            printf("%lld\n",r-l+1);
        }
    }
}
