#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    ll n,a[5],ans=0,f;
    scanf("%lld",&n);
    for(ll i=0;i<5;i++){
        scanf("%lld",&a[i]);
        if(n%a[i]){
            f=1;
        }
        else{
            f=0;
        }
        ans=max(ans,f+n/a[i]+4);
    }
    printf("%lld\n",ans);
}