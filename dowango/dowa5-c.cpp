#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,q,k;
    long ans,a[1000001],b[1000001],c[1000001],d[1000001],sum[1000001];
    char s[1000010];
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&q);
    c[0]=0;
    a[0]=0;
    d[0]=0;
    sum[0]=0;
    for(int i=0;i<n;i++){
        if(s[i]=='C'){
            c[i+1]=c[i]+1;
        }
        else{
            c[i+1]=c[i];
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='D'){
            a[i+1]=a[i]+1;
        }
        else{
            a[i+1]=a[i];
        }
    }
    for(int i=0;i<q;i++){
        ans=0;
        scanf("%d",&k);
        for(int i=0;i<n;i++){
            if(s[i]=='D'){
                d[i+1]=d[i]+c[min(n,i+k-1)];
            }
            else{
                d[i+1]=d[i];
            }
            sum[i+1]=sum[i]+d[i+1];
        }
        for(int i=1;i<n-1;i++){
            if(s[i]=='M'){
                ans+=sum[i]-sum[max(0,i-k+2)]-c[i+1]*(a[i]-a[max(0,i-k+2)]);
            }
        }
        printf("%ld\n",ans);
    }
}