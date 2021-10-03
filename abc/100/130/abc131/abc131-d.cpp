#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll a,b,sum=0;
    pair<ll,ll> p[200000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a,&b);
        p[i].first=b;
        p[i].second=a;
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
        sum+=p[i].second;
        if(sum>p[i].first){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}