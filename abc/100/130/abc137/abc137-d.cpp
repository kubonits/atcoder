#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
typedef long long ll;
using namespace std;
int main(){
    int n,m,a;
    ll b,ans=0;
    vector<pair<ll,int> > p;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d %lld",&a,&b);
        p.push_back(make_pair(b,a));
    }
    sort(p.begin(),p.end());
    set<int> s;
    for(int i=1;i<=m;i++){
        s.insert(i);
    }
    for(int i=n-1;i>=0;i--){
        decltype(s)::iterator it =s.lower_bound(p[i].second);
        if(it!=s.end()){
            ans+=p[i].first;
            s.erase(*it);
        }
    }
    printf("%lld\n",ans);
}