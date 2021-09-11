#include<cstdio>
using namespace std;
typedef long long ll;
int n,t[100000],sum[100000],f;
ll s[100000],h[100000],l,r,mid,x;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&h[i],&s[i]);
    }
    l=0;
    r=1000000000000000;
    while(l<=r){
        mid=(l+r)/2LL;
        f=1;
        for(int i=0;i<n;i++){
            t[i]=0;
        }
        for(int i=0;i<n;i++){
            x=(mid-h[i])/s[i];
            if(mid-h[i]<0){
                f=0;
                break;
            }
            if(x<n){
                t[x]++;
            }
        }
        sum[0]=t[0];
        if(sum[0]>1){
            f=0;
        }
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+t[i];
            if(sum[i]>i+1){
                f=0;
                break;
            }
        }
        if(f){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%lld\n",l);
}