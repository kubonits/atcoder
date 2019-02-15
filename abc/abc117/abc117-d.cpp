#include<cstdio>
using namespace std;
typedef long long ll;
int main(){
    int n,cnt;
    ll k,a[100000],two[40],x=0,ans=0;
    scanf("%d %lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    two[0]=1;
    for(int i=1;i<40;i++){
        two[i]=two[i-1]*2;
    }
    for(int i=39;i>=0;i--){
        if(x+two[i]<=k){
            cnt=0;
            for(int j=0;j<n;j++){
                if((two[i]&a[j])){
                    cnt++;
                }
            }
            if(2*cnt<n){
                x+=two[i];
            }
        }
    }
    for(int i=0;i<n;i++){
        ans+=(x^a[i]);
    }
    printf("%lld\n",ans);
}
