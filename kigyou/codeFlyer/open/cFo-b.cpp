#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,q,l,r,mid[3],p,cnt=0;
    long long int x[100000],sum[100001],ans,c,d;
    scanf("%d %d",&n,&q);
    sum[0]=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&x[i]);
        sum[i+1]=sum[i]+x[i];
    }
    for(int i=0;i<q;i++){
        ans=0;
        scanf("%lld %lld",&c,&d);
        mid[0]=lower_bound(x,x+n,c-d)-x;
        mid[1]=lower_bound(x,x+n,c)-x;
        mid[2]=lower_bound(x,x+n,c+d)-x;
        printf("%lld\n",d*(long long int)(mid[0])+(c*(long long int)(mid[1]-mid[0])-sum[mid[1]]+sum[mid[0]])+(sum[mid[2]]-sum[mid[1]]-c*(long long int)(mid[2]-mid[1]))+d*(long long int)(n-mid[2]));
    }
}