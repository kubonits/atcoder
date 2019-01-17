#include<cstdio>
#include<algorithm>
#define mod 1000000007
using namespace std;
long long n,m,a[1000],b[1000],ans=1,la,lb,x;
int main(){
    scanf("%lld %lld",&n,&m);
    for(long long i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(long long i=0;i<m;i++){
        scanf("%lld",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+m);
    for(long long i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            ans=0;
        }
    }
    for(long long i=0;i<m-1;i++){
        if(b[i]==b[i+1]){
            ans=0;
        }
    }
    if(ans==0){
        printf("0\n");
        return 0;
    }
    la=0;
    lb=0;
    for(long long i=1;i<=n*m;i++){
        while(la!=n&&i>a[la]){
            la++;
        }
        while(lb!=m&&i>b[lb]){
            lb++;
        }
        x=(n-la)*(m-lb)-(n*m-i);
        if(a[la]==i&&b[lb]==i);
        else if(a[la]==i){
            ans*=(m-lb);
        }
        else if(b[lb]==i){
            ans*=(n-la);
        }
        else if(x>0){
            ans*=x;
        }
        else{
            printf("0\n");
            return 0;
        }
        ans%=mod;
    }
    printf("%lld\n",ans);
}