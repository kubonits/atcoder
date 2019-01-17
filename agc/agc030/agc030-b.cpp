#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;
long l,n,x[200000],sum1[200001],sum2[200001],ans=0;
int main(){
    
    scanf("%ld %ld",&l,&n);
    sum1[0]=sum2[0]=0;
    for(int i=0;i<n;i++){
        scanf("%ld",&x[i]);
        sum1[i+1]=sum1[i]+2*x[i];
        sum2[i+1]=sum2[i]+2*(l-x[i]);
    }
    for(int i=1;i<=n;i++){
        if((n-i)%2){
            ans=max(ans,sum1[i+(n-i)/2]-sum1[i-1]+sum2[n]-sum2[i+(n-i)/2]-l+x[i+(n-i)/2]);
            //printf("%ld\n",sum1[i+(n-i)/2]-sum1[i-1]+sum2[n]-sum2[i+(n-i)/2]-l+x[i+(n-i)/2]);
        }
        else{
            ans=max(ans,sum1[i+(n-i)/2]-sum1[i-1]+sum2[n]-sum2[i+(n-i)/2]-x[i+(n-i)/2-1]);
            //printf("%ld\n",sum1[i+(n-i)/2]-sum1[i-1]+sum2[n]-sum2[i+(n-i)/2]-x[i+(n-i)/2-1]);
        }
        if(i==1){
            ans=max(ans,l-x[0]);
            //printf("%ld\n",l-x[0]);
        }
        else if(i%2){
            ans=max(ans,sum2[i]-sum2[i/2]+sum1[i/2]-l+x[i/2]);
            //printf("%ld\n",sum2[i]-sum2[i/2]+sum1[i/2]-l+x[i/2]);
        }
        else{
            ans=max(ans,sum2[i]-sum2[i/2]+sum1[i/2]-x[i/2-1]);
            //printf("%ld\n",sum2[i]-sum2[i/2]+sum1[i/2]-x[i/2-1]);
        }
    }
    printf("%ld\n",ans);
}
