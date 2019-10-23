#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;

ll n,x,b[100000],l[100000],u[100000],ans=100000000000000000,sum=0,right,left,mid,a,q,r,left2,right2,mid2,sum2[100001];
int flag,in[100000];
pair<ll,ll> p[100000];
int main(){
    scanf("%lld %lld",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%lld %lld %lld",&b[i],&l[i],&u[i]);
        p[i]=make_pair((x-b[i])*u[i]+l[i]*b[i],i);
        sum-=l[i]*b[i];
    }
    sort(p,p+n);
    sum2[0]=0;
    for(int i=0;i<n;i++){
        in[p[i].second]=i;
        sum2[i+1]=sum2[i]+p[n-1-i].first;
    }
    for(int i=0;i<n;i++){
        r=x;
        left=0;
        right=n;
        while(left<=right){
            a=sum+l[i]*b[i];
            mid=(left+right)/2;
            q=mid;
            a+=max((r-b[i])*l[i],(r-b[i])*u[i]);
            if(!q||in[i]<n-q){
                a+=sum2[q];
            }
            else{
                a+=sum2[q+1]-p[in[i]].first;
            }
            if(a>=0){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        q=left;
        left=0;
        right=x;
        while(left<=right){
            a=sum+l[i]*b[i];
            mid=(left+right)/2;
            r=mid;
            a+=max((r-b[i])*l[i],(r-b[i])*u[i]);
            if(!q||in[i]<n-q){
                a+=sum2[q];
            }
            else{
                a+=sum2[q+1]-p[in[i]].first;
            }
            if(a>=0){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        ans=min(ans,q*x+left);
    }
    printf("%lld\n",ans);
}