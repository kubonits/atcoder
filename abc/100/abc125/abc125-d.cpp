#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n,cnt=0;
    ll a[100000],ans=0,mini=1000000001;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>0){
            ans+=a[i];
            mini=min(mini,a[i]);
        }
        else{
            ans-=a[i];
            cnt++;
            mini=min(mini,-a[i]);
        }
    }
    if(cnt%2){
        printf("%lld\n",ans-2LL*mini);
    }
    else{
        printf("%lld\n",ans);
    }
}