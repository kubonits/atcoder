#include<cstdio>
using namespace std;
int main(){
    int n;
    long a,mini=1,ans=0;
    scanf("%d",&n);
    scanf("%ld",&a);
    ans+=a-1;
    mini=2;
    for(int i=1;i<n;i++){
        scanf("%ld",&a);
        ans+=(a-1)/mini;
        if(a==mini){
            mini++;
        }
    }
    printf("%ld\n",ans);
}