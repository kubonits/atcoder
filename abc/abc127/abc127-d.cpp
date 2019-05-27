#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    long long a,c,ans=0,b;
    vector<pair<ll,ll> >in;
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a);
        in.push_back(make_pair(a,1));
    }
    for(int i=0;i<m;i++){
        scanf("%lld %lld",&b,&c);
        in.push_back(make_pair(c,b));
    }
    sort(in.begin(),in.end());
    for(int i=in.size()-1;i>=0;i--){
        if(in[i].second<=n){
            ans+=in[i].first*in[i].second;
            n-=in[i].second;
        }
        else{
            ans+=in[i].first*n;
            n=0;
        }
    }
    printf("%lld\n",ans);
}