#include<cstdio>
#include<map>
#include<utility>
#include<algorithm>
#define mod 1000000007
typedef long long ll;
using namespace std;

map<pair<ll,ll>,int> ma;

int dfs(ll x, ll y){
    decltype(ma)::iterator it = ma.find(make_pair(x/2,y/2));
    int res;
    if(x<0||y<0){
        return 0;
    }
    if(x==0){
        return 1;
    }
    if(x==1&&y==1){
        return 2;
    }
    if(it!=ma.end()){
        res=ma[make_pair(x/2,y/2)];
    }
    else{
        res=dfs(x/2,y/2);
    }
    res%=mod;
    it = ma.find(make_pair((x-1)/2,(y-1)/2));
    if(it!=ma.end()){
        res+=ma[make_pair((x-1)/2,(y-1)/2)];
    }
    else{
        res+=dfs((x-1)/2,(y-1)/2);
    }
    res%=mod;
    it = ma.find(make_pair((x-2)/2,min(x-2,y)/2));
    if(it!=ma.end()){
        res+=ma[make_pair((x-2)/2,min(x-2,y)/2)];
    }
    else{
        res+=dfs((x-2)/2,min(x-2,y)/2);
    }
    res%=mod;
    ma.insert(make_pair(make_pair(x,y),res));
    return res;
}

int main(){
    ll n;
    scanf("%lld",&n);
    printf("%d\n",dfs(n,n));
}