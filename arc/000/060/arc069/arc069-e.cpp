#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
pair<ll ,ll> p[100001];
ll ans[100000],n,a[100000],l,b;
int main(){
    scanf("%lld",&n);
    for(ll i=0;i<n;i++){
        scanf("%lld",&a[i]);
        p[i]=make_pair(a[i],i+1);
    }
    p[n]=make_pair(0,0);
    sort(p,p+n+1);
    l=n;
    b=n;
    while(l){
        while(p[l].first==p[l-1].first){
            l--;
        }
        b=min(b,p[l].second);
        ans[b-1]+=(n-l+1)*(p[l].first-p[l-1].first);
        l--;
    }
    for(int i=0;i<n;i++){
        printf("%lld\n",ans[i]);
    }
}