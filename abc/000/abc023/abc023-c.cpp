#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll rr,cc,k,n,x[100001],y[100001],xx[100001],yy[100001],a,b,ans;
int r[100000],c[100000];
int main(){
    scanf("%lld %lld %lld",&rr,&cc,&k);
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&r[i],&c[i]);
        x[r[i]]++;
        y[c[i]]++;
    }
    for(int i=1;i<=rr;i++){
        xx[x[i]]++;
    }
    for(int i=1;i<=cc;i++){
        yy[y[i]]++;
    }
    for(int i=0;i<=rr;i++){
        a=k-i;
        if(a>=0&&a<=cc){
            ans+=xx[i]*yy[a];
        }
    }
    for(int i=0;i<n;i++){
        if(x[r[i]]+y[c[i]]==k+1){
            ans++;
        }
        else if(x[r[i]]+y[c[i]]==k){
            ans--;
        }
    }
    printf("%lld\n",ans);
}