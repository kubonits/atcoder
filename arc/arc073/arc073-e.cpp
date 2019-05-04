#include<cstdio>
#include<algorithm>
#include<utility>
typedef long long ll;
using namespace std;
int n,f;
ll x,y,rl,rh,ans;
pair<ll,ll> p[200000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&x,&y);
        p[i]=make_pair(min(x,y),max(x,y));
    }
    sort(p,p+n);
    rh=rl=p[0].second;
    for(int i=1;i<n;i++){
        rh=max(rh,p[i].second);
        rl=min(rl,p[i].second);
    }
    ans=(p[n-1].first-p[0].first)*(rh-rl);
    f=0;
    for(int i=1;i<n;i++){
        if(rh==p[i].second){
            f=1;
            break;
        }
    }
    if(f){
        x=rh-p[0].first;
        rl=1000000000;
        rh=p[n-1].first;
        for(int i=0;i<n-1;i++){
            rl=min(rl,p[i].second);
            rh=max(rh,p[i].second);
            ans=min(ans,x*(rh-min(rl,p[i+1].first)));
        }
    }
    printf("%lld\n",ans);
}