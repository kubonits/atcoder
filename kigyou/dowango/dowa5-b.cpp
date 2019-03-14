#include<cstdio>
using namespace std;
int main(){
    int n,k,cnt=0;
    long a[1000],sum[1001],ans=0,t[41],b;
    t[0]=1;
    for(int i=1;i<=40;i++){
        t[i]=t[i-1]*2;
    }
    sum[0]=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
        sum[i+1]=sum[i]+a[i];
    }
    for(int i=40;i>=0;i--){
        cnt=0;
        for(int j=0;j<n;j++){
            for(int l=j+1;l<=n;l++){
                b=(ans+t[i])&(sum[l]-sum[j]);
                if(b==ans+t[i]){
                    cnt++;
                }
            }
        }
        if(cnt>=k){
            ans+=t[i];
        }
    }
    printf("%ld\n",ans);
}