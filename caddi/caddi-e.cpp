#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long ans=0,n,a[200000],b,po[200001],ne[200001];
double c;
   vector<long long> z;
int main(){
    
    scanf("%lld",&n);
    for(long long i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(!a[i]){
            z.push_back(i);
        }
    }
    if(z.size()){
        for(long long i=1;i<z.size();i++){
            if(z[i]-z[i-1]!=1){
                printf("-1\n");
                return 0;
            }
        }
        for(long long i=n-1;i>z.back();i--){
            b=0;
            if(a[i]<a[i-1]){
                c=(double)a[i-1]/a[i];
                while(c>1.0){
                    c/=4.0;
                    b+=2;
                }
                if(c==1.0){
                    b+=2;
                }
                ans+=b*(n-i);
            }
        }
        for(long long i=0;i<z[0];i++){
            a[i]*=(long long)-2;
            ans++;
        }
        for(long long i=0;i<z[0];i++){
            if(a[i]>a[i+1]){
                c=(double)a[i]/a[i+1];
                while(c<1.0){
                    b+=2;
                    c*=4;
                }
                ans+=b*(i+1);
            }
        }
    }
    else{
        po[n]=0;
        po[n-1]=0;
        for(long long i=n-2;i>=0;i--){
            po[i]=po[i+1];
            if(a[i]>a[i+1]){
                b=0;
                c=(double)a[i+1]/a[i];
                while(c<1.0){
                    b+=2;
                    c*=4;
                }
                po[i]+=b*(n-1-i);
            }
        }
        ne[0]=0;
        ne[1]=1;
        a[0]*=-2;
        for(long long i=1;i<n;i++){
            a[i]*=-2;
            ne[i+1]=ne[i]+1;
            if(a[i]<a[i-1]){
                c=(double)a[i-1]/a[i];
                b=0;
                while(c<1.0){
                    b+=2;
                    c*=4;
                }
                ne[i+1]+=b*(i);
            }
        }
        ans=po[0]+ne[0];
        for(long long i=1;i<=n;i++){
            ans=min(ans,po[i]+ne[i]);
            //printf("%ld %ld\n",po[i],ne[i]);
        }
    }
    printf("%lld\n",ans);
}