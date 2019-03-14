#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    long n;
    long x[100000],ans=0;
    scanf("%ld",&n);
    for(long i=0;i<n;i++){
        scanf("%ld",&x[i]);
    }
    sort(x,x+n);
    for(long i=0;i<n;i++){
        ans+=x[i]*(i-(n-1-i));
    }
    printf("%ld\n",ans);
}