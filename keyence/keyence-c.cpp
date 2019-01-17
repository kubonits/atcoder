#include<cstdio>
#include<algorithm>
using namespace std;
int n,f[100000]={},ans=0,l;
long long a[100000],b[100000],suma=0,sumb=0,sa[100000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        suma+=a[i];
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&b[i]);
        sumb+=b[i];
        sa[i]=a[i]-b[i];
    }
    if(suma<sumb){
        printf("-1\n");
    }
    else{
        sort(sa,sa+n);
        l=n-1;
        for(int i=0;i<n;i++){
            if(sa[i]>=0){
                break;
            }
            f[i]=1;
            while(sa[i]<0){
                if(sa[i]+sa[l]>=0){
                    sa[l]+=sa[i];
                    sa[i]=0;
                    f[l]=1;
                }
                else{
                    f[l]=1;
                    sa[i]+=sa[l];
                    l--;
                    f[l]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            ans+=f[i];
        }
        printf("%d\n",ans);
    }
}