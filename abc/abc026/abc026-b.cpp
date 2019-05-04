#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n;
    double ans=0,r[1000],pi=4*atan(1);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&r[i]);
        r[i]*=-1;
    }
    sort(r,r+n);
    for(int i=0;i<n;i++){
        if(i%2){
            ans-=r[i]*r[i];
        }
        else{
            ans+=r[i]*r[i];
        }
    }
    printf("%.7f\n",ans*pi);
}