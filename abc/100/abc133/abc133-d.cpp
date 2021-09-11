#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
typedef long long ll;
int main(){
    ll n,a[100000],sum[100001];
    sum[0]=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(i%2){
            sum[i+1]=sum[i]-a[i];
        }
        else{
            sum[i+1]=sum[i]+a[i];
        }
    }
    for(int i=0;i<n;i++){
        if(i==0){
            printf("%lld\n",sum[n]);
        }
        else if(i%2){
            printf("%lld\n",-sum[n]+2*sum[i]);
        }
        else{
            printf("%lld\n",sum[n]-2*sum[i]);
        }
    }
}