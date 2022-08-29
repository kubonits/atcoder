#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    long long ans=0,sum=0,a[100000],b[100000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a[i],&b[i]);
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            ans=max(ans,sum-b[i]);
        }
    }
    printf("%lld\n",ans);
}