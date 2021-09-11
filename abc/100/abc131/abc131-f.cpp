#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
typedef long long ll;
pair<ll,ll> c[100001];
int a[100001],b[100001],n,x[100000],y[100000];
vector<int> vx[100001],vy[100001];
ll ans;

void dfs(int v,int p,int z){
    if(!z){
        c[p].first++;
        a[v]=p;
        for(int i=0;i<vx[v].size();i++){
            if(b[vx[v][i]]!=p){
                dfs(vx[v][i],p,z^1);
            }
        }
    }
    else{
        c[p].second++;
        b[v]=p;
        for(int i=0;i<vy[v].size();i++){
            if(a[vy[v][i]]!=p){
                dfs(vy[v][i],p,z^1);
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x[i],&y[i]);
        vx[x[i]].push_back(y[i]);
        vy[y[i]].push_back(x[i]);
    }
    for(int i=1;i<=100000;i++){
        a[i]=i;
        b[i]=i+100000;
    }
    for(int i=1;i<=100000;i++){
        c[i]=make_pair(0,0);
        if(a[i]==i){
            dfs(i,i,0);
            if(c[i].first>1&&c[i].second>1){
                ans+=c[i].first*c[i].second;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(c[a[x[i]]].first>1&&c[a[x[i]]].second>1){
            ans--;
        }
    }
    printf("%lld\n",ans);
}