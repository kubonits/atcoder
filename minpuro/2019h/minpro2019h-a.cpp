#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    double h,w,a,b,ans,t;
    scanf("%lf %lf %lf%lf",&h,&w,&a,&b);
    t=min(a,h-a);
    ans=2*t*(h*a-a*a+t*(t/3-h/2))/(h-a)/(h-a);
    t=min(b,w-b);
    ans*=2*t*(w*b-b*b+t*(t/3-w/2))/(w-b)/(w-b);
    printf("%.10f\n",ans);
}