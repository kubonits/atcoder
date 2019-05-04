#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,sum[100001],a[100000],b[100005]={},ans[100001];
int main(){
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(i!=n-1){
            b[a[i]+2]--;
        }
        if(i!=0){
            b[a[i]+1]++;
            if(a[i]<a[i-1]){
                b[0]--;
            }
        }
    }
    sum[0]=b[0];
    for(int i=1;i<=m;i++){
        sum[i]=sum[i-1]+b[i];
    }
    for(int i=1;i<n;i++){
        sum[a[i]%m+1]+=(m+a[i]-a[i-1])%m-1;
    }
    ans[1]=0;
    for(int i=0;i<n-1;i++){
        ans[1]+=min(1+(a[i+1]+m-1)%m,(a[i+1]+m-a[i])%m);
    }
    for(int i=2;i<=m;i++){
        ans[i]=ans[i-1]+sum[i];
    }ans[0]=ans[1];
    for(int i=1;i<=m;i++){
        ans[0]=min(ans[0],ans[i]);
    }
    printf("%lld\n",ans[0]);
}