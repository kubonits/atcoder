#include<cstdio>
typedef long long ll;
using namespace std;
int main(){
    int f;
    ll l,r,mid,a[50],n,sum,ans=0,x;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    do{
        f=1;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i]/n;
        }
        for(int i=0;i<n;i++){
            x=a[i]/n;
            a[i]+=sum-x-x*n;
            if(a[i]>=n){
                f=0;
            }
        }
        ans+=sum;
    }while(f==0);
    printf("%lld\n",ans);
}