#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

ll a[100000],b[100000];
int n,ua[100000],ub[100000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&b[i]);
    }
    for(int i=59;i>=0;i--){
        for(int j=0;j<n;j++){
            if(ua[j]==0&&((1LL<<i)&a[j])){
                ua[j]=1;
                for(int k=0;k<n;k++){
                    if(j!=k&&((1LL<<i)&a[k])){
                        a[k]^=a[j];
                    }
                }
            }
        }
        for(int j=0;j<n;j++){
            if(ub[j]==0&&((1LL<<i)&b[j])){
                ub[j]=1;
                for(int k=0;k<n;k++){
                    if(j!=k&&((1LL<<i)&b[k])){
                        b[k]^=b[j];
                    }
                }
            }
        }
    }
    sort(a,a+n);
    sort(b,b+n);
    int f=1;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            f=0;
        }
    }
    if(f){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}