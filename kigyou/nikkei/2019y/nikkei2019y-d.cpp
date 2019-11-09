#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<utility>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
    int n,m,l,r;
    vector<pair<pair<int,int> ,ll> > e;
    ll c,dis[100001];
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%lld",&l,&r,&c);
        e.push_back({{l,r},c});
    }
    sort(e.begin(),e.end());
    for(int i=0;i<=n;i++){
        dis[i]=1000000000000000;
    }
    dis[1]=0;
    int p=0;
    l=0;
    q.push({0LL,-1});
    while(!q.empty()&&l<n&&p<m){
        while(!q.empty()&&-q.top().second<=l){
            q.pop();
        }
        if(q.empty()){
            break;
        }
        l=-q.top().second;
        q.pop();
        while(e[p].first.first<=l&&p<m){
            if(dis[e[p].first.second]>dis[l]+e[p].second){
                dis[e[p].first.second]=dis[l]+e[p].second;
                //printf("%lld %lld %lld\n",dis[e[p].first.second],dis[l],e[p].second);
                q.push({dis[e[p].first.second],-e[p].first.second});
            }
            p++;
        }
    }
    if(dis[n]==1000000000000000){
        printf("-1\n");
    }
    else{
        printf("%lld\n",dis[n]);
    }
}