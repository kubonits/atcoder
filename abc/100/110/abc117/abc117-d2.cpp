#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n,cnt;
    ll k,a[100000],x[40],b[40]={},two[40],ans=0,c;
    scanf("%d %lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    two[0]=1;
    for(int i=1;i<40;i++){
        two[i]=2*two[i-1];
    }
    for(int i=39;i>=0;i--){
        cnt=0;
        for(int j=0;j<n;j++){
            if((two[i]&a[j])){
                cnt++;
            }
        }
        if(2*cnt<n){
            x[i]=two[i];
        }
    }
    for(int i=39;i>=0;i--){
        if((k&two[i])){
            for(int j=39;j>i;j--){
                b[i]+=(k&two[j]);
            }
            for(int j=0;j<i;j++){
                b[i]+=x[j];
            }
        }
    }
    for(int i=0;i<n;i++){
        ans+=(a[i]^k);
    }
    for(int i=0;i<40;i++){
        c=0;
        for(int j=0;j<n;j++){
            c+=(b[i]^a[j]);
        }
        ans=max(ans,c);
    }
    printf("%lld\n",ans);
}