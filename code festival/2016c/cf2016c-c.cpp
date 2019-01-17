#include<cstdio>
#include<algorithm>
using namespace std;
#define mod 1000000007
int main(){
    int n;
    long t[100000],a[100000],ans=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%ld",&t[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }
    if(t[0]>a[0]||t[n-1]<a[n-1]||t[n-1]!=a[0]){
        ans*=0;
    }
    for(int i=1;i<n-1;i++){
        if(t[i]==t[i-1]&&a[i]==a[i+1]){
            ans*=min(a[i],t[i]);
            ans%=mod;
        }
        else if(a[i]!=t[i]&&t[i]>t[i-1]&&a[i]>a[i+1]){
            ans*=0;
        }
        else if(a[i]>t[i]&&a[i]>a[i+1]){
            ans*=0;
        }
        else if(a[i]<t[i]&&t[i]>t[i-1]){
            ans*=0;
        }
    }
    printf("%ld\n",ans);
}