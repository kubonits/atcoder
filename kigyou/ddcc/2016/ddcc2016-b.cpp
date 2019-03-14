#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

double r,n,m,ans=0;

double calc(double x){
    if(x<0||x>n){
        return 0;
    }
    double l;
    l=fabs(x-n/2)*2*r/n;
    return 2*sqrt((r*r-l*l));
}

int main(){
    scanf("%lf %lf %lf",&r,&n,&m);
    for(double i=-1*m;i<=n;i++){
        ans+=max(calc(i),calc(i+m));
    }
    printf("%f\n",ans);
}