#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    long long n,a,b,ans=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a,&b);
        ans+=max(a,b);
    }
    printf("%lld\n",ans);
}