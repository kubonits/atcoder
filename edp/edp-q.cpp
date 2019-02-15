#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N=1<<18;
typedef long long ll;
int n;
ll dat[2*MAX_N-1];
int m,h[200000];
ll dp[200001]={},a[200000],ans=0;
void init(int n_){
    n=1;
    while(n<n_){
        n*=2;
    }
    for(int i=0;i<2*n-1;i++){
        dat[i]=0;
    }
}

void update(int k,ll a){
    k+=n-1;
    dat[k]=a;
    while(k>0){
        k=(k-1)/2;
        dat[k]=max(dat[k*2+1],dat[k*2+2]);
    }
}

ll query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l){
        return 0;
    }
    if(a<=l&&r<=b){
        return dat[k];
    }
    else{
        ll vl=query(a,b,k*2+1,l,(l+r)/2);
        ll vr=query(a,b,k*2+2,(l+r)/2,r);
        return max(vl,vr);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
        h[i]--;
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    m=n;
    init(n);
    for(int i=0;i<m;i++){
        dp[h[i]]=a[i]+query(0,h[i],0,0,n);
        update(h[i],dp[h[i]]);
    }
    for(int i=0;i<m;i++){
        ans=max(ans,dp[i]);
    }
    printf("%lld\n",ans);
}