#include<cstdio>
#include<set>
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,a[500000],xo[500001];
int main(){
    set<int> s;
    ll ans=1;
    xo[0]=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        xo[i+1]=xo[i]^a[i];
        printf("%d ",xo[i+1]);
        if(xo[i+1]==0){
            ans+=i+1;
            ans%=mod;
        }
    }
    printf("\n%lld\n",ans);
}