#include<cstdio>
using namespace std;
int main(){
    int n;
    long a[100000],b[100000],ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%ld %ld",&a[i],&b[i]);
    }
    for(int i=n-1;i>=0;i--){
        ans+=(b[i]-(a[i]+ans)%b[i])%b[i];
    }
    printf("%ld\n",ans);
}