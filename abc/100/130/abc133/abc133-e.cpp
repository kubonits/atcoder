#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,k,ans=1;
vector<int> G[100001];

void dfs(int x,int y,ll z,ll d){
    ll flag=0;
    if(x==1){
        ans=k;
    }
    else if(k-z-d<=0){
        ans=0;
    }
    else{
        ans*=(k-d-z);
    }
    ans%=MOD;
    for(ll i=0;i<G[x].size();i++){
        if(G[x][i]!=y){
            dfs(G[x][i],x,i-flag,min(2LL,d+1));
        }
        else{
            flag=1LL;
        }
    }
}

int main(){
    int a,b;
    ans=1;
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,-1,0LL,0LL);
    printf("%lld\n",ans);
}