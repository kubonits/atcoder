#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    long sum[100001],sum1[100001],a[100000],f[50000],l,r,mid,z;
    int n,q,x;
    scanf("%d %d",&n,&q);
    sum[0]=sum1[0]=0;
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
        sum[i+1]=sum[i]+a[i];
        sum1[i+1]=sum1[i];
        if(i%2!=n%2){
            sum1[i+1]+=a[i];
        }
    }
    f[n/2-1]=0;
    for(int i=0;i<n/2;i++){
        x=n-2-2*i;
        if(x==0){

            break;
        }
        l=a[x-1];
        r=a[n-1-i];
        while(l<=r){
            mid=(l+r)/2;
            if(abs(a[n-i-2]-mid)<abs(a[x-1]-mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        f[i]=l;
        //printf("%ld\n",f[i]);
    }
    for(int i=0;i<q;i++){
        scanf("%d",&z);
        if(n%2&&z<f[n/2-1]){
            printf("%ld\n",sum[n]-sum[n/2]);
        }
        else{
            l=0;
            r=n/2-1;
            while(l<r){
                mid=(l+r)/2;
                if(f[mid]>z){
                    l=mid+1;
                }
                else{
                    r=mid;
                }
            }
            printf("%ld\n",sum[n]-sum[n-mid-1]+sum1[n-(mid+1)*2]);
        }

    }
}