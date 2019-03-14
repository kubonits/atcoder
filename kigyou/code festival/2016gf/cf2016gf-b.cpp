#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    double x[3],y[3],z[3],l,s,S,r,left,right,mid;
    for(int i=0;i<3;i++){
        scanf("%lf %lf",&x[i],&y[i]);
    }
    for(int i=0;i<3;i++){
        z[i]=(x[i]-x[(i+1%3)])*(x[i]-x[(i+1%3)])+(y[i]-y[(i+1%3)])*(y[i]-y[(i+1%3)]);
        z[i]=sqrt(z[i]);
    }
    s=(z[0]+z[1]+z[2])/2;
    S=sqrt(s*(s-z[0])*(s-z[1])*(s-z[2]));
    r=S/s;
    l=max(z[0],z[1]);
    l=max(l,z[2]);
    left=0;
    right=r;
    while(right-left>0.000000001){
        mid=(left+right)/2;
        if((1-mid/r)*l<2*mid){
            right=mid;
        }
        else{
            left=mid;
        }
        printf("%f\n",left);
    }
    printf("%f\n",left);
}