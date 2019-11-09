#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<utility>
#include<queue>
#include<set>
typedef long long ll;
using namespace std;
int main(){
    ll k,n,ans=0LL;
    vector<ll> a,b,c;
    set<ll> s;
    scanf("%lld %lld",&n,&k);
    for(ll i=k;i<k+3LL*n;i++){
        if(i<k+2LL*n){
            ans-=i;
            s.insert(i);
        }
        else{
            ans+=i;
            c.push_back(i);
        }
    }
}