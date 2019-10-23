#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
    int n;
    ll ans=0,a[100001],b[100000],x;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&b[i]);
        x=min(a[i],b[i]);
        ans+=x;
        a[i]-=x;
        b[i]-=x;
        x=min(a[i+1],b[i]);
        ans+=x;
        a[i+1]-=x;
        b[i]-=x;
    }
    printf("%lld\n",ans);
}