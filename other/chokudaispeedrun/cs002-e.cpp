#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n;
    ll ans=0,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a,&b);
        ans+=min(a/2,b);
    }
    printf("%lld\n",ans);
}