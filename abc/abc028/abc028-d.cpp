#include<cstdio>
using namespace std;
 int main(){
     double n,k;
     double ans=0.0;
     scanf("%lf %lf",&n,&k);
     ans+=3.0*(double)n;
     ans-=2.0;
     ans+=(n-k)*(k-1)*6.0;
     ans/=n;
     ans/=n;
     ans/=n;
     printf("%.11f\n",ans);
 }